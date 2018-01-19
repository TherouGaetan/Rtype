cmake_minimum_required(VERSION 3.8)
project(Rtype)

set(CMAKE_CXX_STANDARD 14)


include_directories(Sources)

# Global sources network
set(NETWORK_SOURCE_FILES
        Sources/Network/Socket/ASocket.cpp
        Sources/Network/Socket/TcpSocket.cpp
        Sources/Network/Socket/UdpSocket.cpp
        Sources/Network/Socket/Packet.cpp
        Sources/Network/Logger/Logger.cpp
        Sources/Network/Exception/NetworkException.cpp
        Sources/Network/AClient.cpp
        Sources/Network/AServer.cpp)

# Global sources Thread
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
        Sources/Thread/ThreadFactory.hpp
        Sources/Thread/ThreadPool/AConsumer.cpp
        Sources/Thread/ThreadPool/DoTheJob.cpp
        Sources/Thread/ThreadPool/ThreadPool.cpp)

# Sources Server
set(SERVER
        Sources/Server/Server.cpp)

# Sources Client
set(VIEW
        Sources/Client/Gui/ViewFactory.cpp
        Sources/Client/Gui/ViewManager.cpp
        Sources/Client/Gui/View/AView.cpp
        Sources/Client/Gui/Widget/AWidget.cpp
        Sources/Client/Gui/Scene/AuthenticationScene.cpp)

set(CLIENT
        Sources/Client/Client.cpp
        Sources/Client/Exception/Exception.cpp
        Sources/Client/Exception/GuiException.cpp)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Make executable server
set(EXECUTABLE_SERVER_NAME "RtypeServer")
add_executable(${EXECUTABLE_SERVER_NAME} ${SERVER} ${NETWORK_SOURCE_FILES} ${THREAD} main.cpp)
target_link_libraries(${EXECUTABLE_SERVER_NAME} Threads::Threads)

# Make executable client
set(EXECUTABLE_CLIENT_NAME "RtypeClient")
add_executable(${EXECUTABLE_CLIENT_NAME} ${CLIENT} ${VIEW} ${NETWORK_SOURCE_FILES} ${THREAD} Sources/Client/main.cpp)
target_link_libraries(${EXECUTABLE_CLIENT_NAME} Threads::Threads)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_CLIENT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()