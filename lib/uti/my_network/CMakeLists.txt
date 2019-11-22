cmake_minimum_required(VERSION 3.12.4)
project(my_network_library)

set(CMAKE_CXX_STANDARD 17)

add_library(my_network STATIC
        ServerWrapper.cpp
        ClientWrapper.cpp)

target_include_directories(my_network PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ./../my_string/)

enable_testing()
add_test(test_network_1
        ${CMAKE_HOME_DIRECTORY}/tests/test_1_network_server_client_multiple_messages.sh
        ${CMAKE_HOME_DIRECTORY}/tests)
