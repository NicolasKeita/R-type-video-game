cmake_minimum_required(VERSION 3.12.4)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.69.0 REQUIRED)

include_directories(./)

add_library(my_network STATIC
        ServerWrapper.cpp
        ClientWrapper.cpp)
