#include "UdpSocket.hpp"

namespace Network {
	namespace TSocket {
		UdpSocket::UdpSocket(fd_set *pRead, fd_set *pWrite, const Type &pType)
				: ASocket(pRead, pWrite, pType) {
		}

		UdpSocket::UdpSocket(fd_set *pRead, fd_set *pWrite, unsigned int pSocket)
				: ASocket(pRead, pWrite, pSocket) {

		}

		void UdpSocket::sPrepare(unsigned int pMillisecond, const std::string &pIp, unsigned int pPort) {
			if (mType == Type::Client)
				sInit(pMillisecond, pIp, pPort);
			else {
				sInit(pMillisecond, pIp, pPort);
				sBind();
			}
		}

		void UdpSocket::sInit(unsigned int pMillisecond, const std::string &pIp, unsigned int pPort) throw() {
			struct protoent *proto;
#ifdef _WIN32
            WSADATA  data;
            int result;

            result = WSAStartup(MAKEWORD(2, 2), &data);
            if (result != 0)
                throw NetworkException("WSAStartu failed\n");
#endif // _WIN32

			mTime.tv_sec = 0;
			mTime.tv_usec = pMillisecond * 50;

			Logger::getInstance().logLine("||               *-* Protobyname                               ||");
			if ((proto = getprotobyname("UDP")) == NULL)
				throw NetworkException("getprotobyname failed\n");

			Logger::getInstance().logLine("||               *-* Create socket                             ||");
			if ((mSocketId = socket(AF_INET, SOCK_DGRAM, proto->p_proto)) < 0)
				throw NetworkException("Creat socket failed\n");

			if (mType == Type::Client) {
				char opt;
				struct hostent *host;

				Logger::getInstance().logLine("||               *-* set sockopt                               ||");
				if (setsockopt(mSocketId, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) == -1)
					throw NetworkException("Setsockopt failed\n");

				Logger::getInstance().logLine("||               *-* Gethostbyname                             ||");
				struct in_addr in;
				inet_pton(AF_INET, pIp.c_str(), &in);
				if ((host = gethostbyaddr((char *) &in, sizeof in, AF_INET)) == NULL)
					throw NetworkException("Unknown host\n");

				mAddr.sin_family = AF_INET;
				mAddr.sin_port = htons(pPort);
				mAddr.sin_addr = *(struct in_addr *) host->h_addr;
			} else {
				mAddr.sin_family = AF_INET;
				mAddr.sin_port = htons(pPort);
				mAddr.sin_addr.s_addr = htonl(INADDR_ANY);
			}
		}

		void UdpSocket::sListen(unsigned int pNb) throw() {
			// ok
		}

		unsigned int UdpSocket::sAccept() const throw() {
			// ok
			return 0;
		}

		void UdpSocket::sConnect() const throw() {
			// ok
		}

		int UdpSocket::sSend(const Packet &pBuff, struct sockaddr_in *pAddr) const
        {
            int sizeAddr = sizeof(struct sockaddr_in);
            return static_cast<int>(sendto(mSocketId, pBuff.getBuff().c_str(), pBuff.getBuff().length(), 0, (struct sockaddr *)((mType == Type::Client) ? &mAddr : pAddr), sizeAddr));
        }

        int UdpSocket::sRecv(Packet & pBuff, struct sockaddr_in *pAddr)
        {
			socklen_t sizeAddr = sizeof(struct sockaddr_in);
            char *buffrd = new char[1024];

            int ret = static_cast<int>(recvfrom(mSocketId, buffrd, 1024, 0, (struct sockaddr *)((mType == Type::Client) ? &mAddr : pAddr), &sizeAddr));
            buffrd[ret] = 0;
            pBuff.append(std::string(buffrd));
            return ret;
        }
	}
}
