cmake_minimum_required(VERSION 3.12.4)
project(my_network_library)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.69.0 REQUIRED)

include_directories(
        ./
        ./../my_string/)

add_library(my_network STATIC
        ServerWrapper.cpp
        ClientWrapper.cpp)
