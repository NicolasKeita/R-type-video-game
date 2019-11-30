cmake_minimum_required(VERSION 3.12.4)
project(R_type_video_game)

include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(R_type_video_game
  srcs/main.cpp
  srcs/background.cpp)

set (CMAKE_CXX_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")

target_include_directories(R_type_video_game PUBLIC
  ./srcs
  lib/uti/my_network)

add_subdirectory("lib/uti/my_network")
target_link_libraries(R_type_video_game LINK_PUBLIC my_network)
