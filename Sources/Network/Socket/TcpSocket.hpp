#pragma once

#ifdef TARGET_OS_UNIX
#include <netdb.h>
#endif

#include "ASocket.hpp"
#include "../Exception/NetworkException.hpp"
#include "../Logger/Logger.hpp"

namespace Network {
    namespace TSocket {
        class TcpSocket : public ASocket {
        public:
            TcpSocket(fd_set *pRead, fd_set *pWrite, const Type &pType = Type::Client);
            TcpSocket(fd_set *pRead, fd_set *pWrite, unsigned int pSocket);
            virtual ~TcpSocket();

        public:
            /**
             * prepare socket for network
             *
             * @param pMillisecond  time in check state of socket
             * @param pIp           ip server at call
             * @param pPort         port on server
             */
            void sPrepare(unsigned int pMillisecond, const std::string &pIp, unsigned int pPort) override;

            /**
             * prepare socket for network
             *
             * @param pMillisecond  time in check state of socket
             * @param pIp           ip server at call
             * @param pPort         port on server
             */
            void sInit(unsigned int pMillisecond, const std::string &pIp, unsigned int pPort) throw() override;

            /**
             * listen for connections on a socket
             *
             * @param pNb           Number of socket at listen
             */
            void sListen(unsigned int pNb) throw() override;

            /**
             * accept a connection on a socket
             *
             * @return  file descriptor for the accepted socket
             */
            unsigned int sAccept() const throw() override;

            /**
             * initiate a connection on a socket
             */
            void sConnect() const throw() override;

            /**
             * send a message on a socket
             *
             * @param pBuff         package at send
             * @param pAddr         address of the target
             * @return  number of bytes sent
             */
            int sSend(const Packet &pBuff, struct sockaddr_in *pAddr) const override;

            /**
             * receive a message from a socket
             *
             * @param pBuff         package to write message received
             * @param pAddr         address of the target
             * @return  number of bytes received
             */
            int sRecv(Packet &pBuff, struct sockaddr_in *pAddr) override;
        };
    }
}
