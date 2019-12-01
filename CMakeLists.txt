cmake_minimum_required(VERSION 3.12.4)
project(R_type_video_game)

include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 EXACT COMPONENTS graphics window system REQUIRED)
add_executable(R_type_video_game
        srcs/main.cpp
        srcs/background.cpp)

target_include_directories(R_type_video_game PUBLIC
        ./srcs
        lib/uti/my_network)

add_subdirectory("lib/uti/my_network")
set(SFML_BUILD_AUDIO FALSE)
target_link_libraries(R_type_video_game PRIVATE
        my_network
        sfml-graphics
        ${CONAN_LIBS})
