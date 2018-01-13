cmake_minimum_required(VERSION 3.8)
project(Rtype)

set(CMAKE_CXX_STANDARD 14)

set(THREAD)

set(NETWORK_SOURCE_FILES
        Sources/Network/Socket/ASocket.cpp
        Sources/Network/Socket/TcpSocket.cpp
        Sources/Network/Socket/UdpSocket.cpp
        Sources/Network/Socket/Packet.cpp
        Sources/Network/Logger/Logger.cpp
        Sources/Network/Exception/NetworkException.cpp
        Sources/Network/AClient.cpp Sources/Network/AServer.cpp Sources/Server/Server.cpp Sources/Server/Server.hpp)

add_executable(RtypeServer ${NETWORK_SOURCE_FILES} ${THREAD} main.cpp)