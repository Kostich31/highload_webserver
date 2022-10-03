project(webServer)

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

include_directories(.)

add_executable( server
                main.cpp
                server.cpp
                utils.cpp)
                
target_link_libraries(server Threads::Threads)
