cmake_minimum_required(VERSION 3.12.4)
project(R_type_video_game)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory("lib/uti/my_network")

add_executable(R_type_video_game
        srcs/main.cpp)

target_include_directories(R_type_video_game PUBLIC
        ./srcs
        lib/uti/my_network)
