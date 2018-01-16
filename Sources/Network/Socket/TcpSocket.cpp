#include "TcpSocket.hpp"

namespace Network {
	namespace TSocket {
		TcpSocket::TcpSocket(fd_set *pRead, fd_set *pWrite, const Type &pType)
				: ASocket(pRead, pWrite, pType) {
		}

		TcpSocket::TcpSocket(fd_set *pRead, fd_set *pWrite, const unsigned int pSocket)
				: ASocket(pRead, pWrite, pSocket) {
#ifdef _WIN32
            WSADATA  data;
            int result;

            result = WSAStartup(MAKEWORD(2, 2), &data);
            if (result != 0)
                throw NetworkException("WSAStartu failed\n");
#endif // _WIN32s
		}

		TcpSocket::~TcpSocket() {
#ifdef _WIN32
			WSACleanup();
#endif // _WIN32
		}

		void TcpSocket::sPrepare(const unsigned int pMillisecond, const std::string &pIp, const unsigned int pPort) {
			if (mType == Type::Client) {
				sInit(pMillisecond, pIp, pPort);

				Logger::getInstance().logLine("||               *-* Connect client                            ||");
				sConnect();
			} else {
				sInit(pMillisecond, pIp, pPort);
				sBind();
				sListen(5);
			}
		}

		void TcpSocket::sInit(const unsigned int pMillisecond, const std::string &pIp, const unsigned int pPort) throw() {
			struct protoent *proto;
#ifdef _WIN32
            WSADATA  data;
            int result;

            result = WSAStartup(MAKEWORD(2, 2), &data);
            if (result != 0)
                throw NetworkException("WSAStartu failed\n");
#endif // _WIN32

			mTime.tv_sec = 0;
			mTime.tv_usec = pMillisecond * 1000;

			Logger::getInstance().logLine("||               *-* Protobyname                               ||");
			if ((proto = getprotobyname("TCP")) == NULL)
				throw NetworkException("getprotobyname failed\n");

			Logger::getInstance().logLine("||               *-* Create socket                             ||");
			if ((mSocketId = socket(AF_INET, SOCK_STREAM, proto->p_proto)) < 0)
				throw NetworkException("Creat socket failed\n");

			if (mType == Type::Client) {
				char opt;
				struct hostent *host;

				Logger::getInstance().logLine("||               *-* Set sockopt                               ||");
				if (setsockopt(mSocketId, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) == -1)
					throw NetworkException("Setsockopt failed\n");

				Logger::getInstance().logLine("||               *-* Gethostbyname                             ||");
				struct in_addr in;
				inet_pton(AF_INET, pIp.c_str(), &in);
				if ((host = gethostbyaddr((char *) &in, sizeof in, AF_INET)) == NULL)
					throw NetworkException("Unknown host\n");

				mAddr.sin_family = AF_INET;
				mAddr.sin_port = htons(pPort);
				mAddr.sin_addr = in;
			} else {
				mAddr.sin_family = AF_INET;
				mAddr.sin_port = htons(pPort);
				mAddr.sin_addr.s_addr = INADDR_ANY;
			}
		}

		void TcpSocket::sListen(const unsigned int pNb) throw() {
			if (listen(mSocketId, pNb) == -1)
				throw NetworkException("Socket listen failed\n");
		}

		unsigned int TcpSocket::sAccept() const throw() {
			unsigned int fd;
			struct sockaddr_in addr;
			socklen_t len;

			len = sizeof(addr);
			if ((fd = accept(mSocketId, (struct sockaddr *) &addr, &len)) == -1)
				throw NetworkException("Socket accept failed");
			return fd;
		}

		void TcpSocket::sConnect() const throw() {
			int value;
			if ((value = connect(mSocketId, (struct sockaddr *) &mAddr, sizeof(struct sockaddr_in))) < 0)
				throw NetworkException("Socket connect failed " + std::to_string(value) + " \n");
		}

		int TcpSocket::sSend(const Packet &pBuff, struct sockaddr_in *pAddr) const
        {
            int header = htonl(pBuff.getBuff().length());
            send(mSocketId, (char *)&header, 4, 0);
            return static_cast<int>(send(mSocketId, pBuff.getBuff().c_str(), pBuff.getBuff().length(), 0));
        }

        int TcpSocket::sRecv(Packet &pBuff, struct sockaddr_in *pAddr)
        {
            int size;
            recv(mSocketId, (char*)&size, 4, 0);
            int sizeMsg = ntohl(size);

            if (sizeMsg >= 0)
            {
                char *buffrd = new char[sizeMsg + 1];
                buffrd[sizeMsg] = 0;
                int ret = static_cast<int>(recv(mSocketId, buffrd, sizeMsg, 0));
                pBuff.append(std::string(buffrd));
                return ret;
            }
            return 0;
        }
	}
}