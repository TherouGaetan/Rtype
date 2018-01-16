#pragma once

#ifdef TARGET_OS_WIN32
#include <WinSock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif // __linux__

#include <string>
#include "../Exception/NetworkException.hpp"
#include "Packet.hpp"

namespace Network {
	namespace TSocket {
		enum Type {
			Client,
			Server
		};

		class ASocket {
		public:
			ASocket(fd_set *pRead, fd_set *pWrite, const Type &pType = Type::Client);
			ASocket(fd_set *pRead, fd_set *pWrite, unsigned int pSocket);
			virtual ~ASocket();

		public:
			/**
			 *
			 * @return file descriptor on socket
			 */
			int getSockId() const;

            /**
             * close socket, it's call with destructor
             */
            void sClose();

            /**
             * Selection an file descriptor for socket
             *
             * @throw NetworkException on failed select
             * @return the number of file descriptor
             */
			int sSelect() throw();

            /**
             * Set name of socket in network
             */
			void sBind() const;

		public:
            /**
             * set empty socket
             */
			void setFdZero();

            /**
             * set specifique empty socket
             */
			static void setFdZero(fd_set *pZero);

            /**
             * set file descriptor socket
             */
			void setFdSet(fd_set *pSet);

            /**
             *
             * @param pIsset        check if file descriptor is set
             * @return state of socket
             */
			int setFdIsset(fd_set *pIsset);

		public:
            /**
             * prepare socket for network
             *
             * @param pMillisecond  time in check state of socket
             * @param pIp           ip server at call
             * @param pPort         port on server
             */
			virtual void sPrepare(unsigned int pMillisecond, const std::string &pIp, unsigned int pPort) = 0;

            /**
             * prepare socket for network
             *
             * @param pMillisecond  time in check state of socket
             * @param pIp           ip server at call
             * @param pPort         port on server
             */
			virtual void sInit(unsigned int pMillisecond, const std::string &pIp, unsigned int pPort) throw() = 0;

            /**
             * listen for connections on a socket
             *
             * @param pNb           Number of socket at listen
             */
			virtual void sListen(unsigned int pNb) = 0;

            /**
             * accept a connection on a socket
             *
             * @return  file descriptor for the accepted socket
             */
			virtual unsigned int sAccept() const throw() = 0;

            /**
             * initiate a connection on a socket
             */
			virtual void sConnect() const throw() = 0;

            /**
             * send a message on a socket
             *
             * @param pBuff         package at send
             * @param pAddr         address of the target
             * @return  number of bytes sent
             */
            virtual int sSend(const Packet &pBuff, struct sockaddr_in *pAddr) const = 0;

            /**
             * receive a message from a socket
             *
             * @param pBuff         package to write message received
             * @param pAddr         address of the target
             * @return  number of bytes received
             */
            virtual int sRecv(Packet &pBuff, struct sockaddr_in *pAddr) = 0;

		protected:
			Type mType;
			struct timeval mTime;
			struct sockaddr_in mAddr;
			int mSocketId;
			fd_set *mFdRead;
			fd_set *mFdWrite;
		};
	}
}
