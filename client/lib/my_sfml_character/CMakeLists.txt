cmake_minimum_required(VERSION 3.13.5)
project(my_sfml_character)

set(CMAKE_CXX_STANDARD		    17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(my_sfml_character STATIC
        Character.cpp
        CreateSpriteFromPath.cpp
        setOriginMiddle.cpp)

target_include_directories(my_sfml_character PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CONAN_INCLUDE_DIRS_SFML})

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(my_sfml_character PRIVATE -Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)
