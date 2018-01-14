cmake_minimum_required(VERSION 3.8)
project(Rtype)

set(CMAKE_CXX_STANDARD 14)

set(NETWORK_SOURCE_FILES
        Sources/Network/Socket/ASocket.cpp
        Sources/Network/Socket/TcpSocket.cpp
        Sources/Network/Socket/UdpSocket.cpp
        Sources/Network/Socket/Packet.cpp
        Sources/Network/Logger/Logger.cpp
        Sources/Network/Exception/NetworkException.cpp
        Sources/Network/AClient.cpp
        Sources/Network/AServer.cpp)

set(THREAD
        Sources/Thread/Thread/StdThread.cpp
        Sources/Thread/Thread/UnixThread.cpp
        Sources/Thread/Condvar/StdCondVar.cpp
        Sources/Thread/Condvar/UnixCondVar.cpp
        Sources/Thread/Mutex/ScopeLock.cpp
        Sources/Thread/Mutex/StdMutex.cpp
        Sources/Thread/Mutex/UnixMutex.cpp
        Sources/Thread/Exception/ThreadException.cpp
        Sources/Thread/Exception/ThreadException.hpp
        Sources/Thread/Thread/StdThread.cpp
        Sources/Thread/ThreadFactory.cpp
        Sources/Thread/ThreadFactory.hpp)

set(SERVER
        Sources/Server/Server.cpp
        Sources/Server/Server.hpp)

add_executable(RtypeServer ${SERVER} ${NETWORK_SOURCE_FILES} ${THREAD} main.cpp)