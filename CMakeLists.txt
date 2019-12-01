cmake_minimum_required(VERSION 3.12.4)
project(R_type_video_game)

include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(R_type_video_game
        srcs/main.cpp
        srcs/background.cpp
        srcs/Graphic.cpp)

if (MSVC)
    set(SFML_LIB_DIR "lib/SFML-2.5.1/windows")
else(MSCV)
    set(SFML_LIB_DIR "lib/SFML-2.5.1/linux")
endif(MSVC)

target_include_directories(R_type_video_game PUBLIC
        ./srcs
        lib/uti/my_network
        ${SFML_LIB_DIR}/include)

add_subdirectory("lib/uti/my_network")
if (NOT MSVC)
    target_link_directories(R_type_video_game PRIVATE
            ${SFML_LIB_DIR}/lib)
endif()
target_link_libraries(R_type_video_game PRIVATE
        my_network
        sfml-graphics
        sfml-window
        sfml-system
        ${CONAN_LIBS})
