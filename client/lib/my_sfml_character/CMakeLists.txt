cmake_minimum_required(VERSION 3.13.5)
project(my_sfml_character)

set(CMAKE_CXX_STANDARD		    17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(my_sfml_character STATIC
        Character.cpp
        CreateSpriteFromPath.cpp
        setOriginMiddle.cpp)

if (MSVC)
    set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../SFML-2.5.1/windows")
else(MSCV)
    set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../SFML-2.5.1/linux")
endif(MSVC)

target_include_directories(my_sfml_character PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SFML_LIB_DIR}/include/)

target_link_directories(my_sfml_character PRIVATE
        ${SFML_LIB_DIR}/lib)
target_link_libraries(my_sfml_character PRIVATE
        sfml-graphics
        sfml-window
        sfml-system)

target_compile_options(my_sfml_character PRIVATE -Wall -Wextra)
