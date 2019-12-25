cmake_minimum_required(VERSION 3.13.5)
project(r-type)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(r-type_server
        srcs/main.cpp
        srcs/GameInfo.cpp
        srcs/ProtocolHandler.cpp)

target_include_directories(r-type_server PUBLIC
        ./srcs/
        ../lib/uti/my_prog_args/
        lib/uti/my_network/BlockingMultiThread
        lib/uti/my_network/
        lib/uti/my_string/)

target_link_libraries(r-type_server PRIVATE
        my_network
        ${CONAN_LIBS})

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(r-type_server PRIVATE -Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)

#add_custom_command(TARGET r-type_server
#                   POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_server> ${CMAKE_HOME_DIRECTORY})
