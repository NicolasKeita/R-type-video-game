cmake_minimum_required(VERSION 3.13.5)
project(my_sfml_cinematic)

set(CMAKE_CXX_STANDARD		    17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(my_sfml_cinematic STATIC
        Cinematic.cpp
        CreateSpriteFromPath.cpp
        setOriginMiddle.cpp)

if (MSVC)
    set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../SFML-2.5.1/windows")
else(MSCV)
    set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../SFML-2.5.1/linux")
endif(MSVC)

target_include_directories(my_sfml_cinematic PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SFML_LIB_DIR}/include/)

target_link_directories(my_sfml_cinematic PRIVATE
        ${SFML_LIB_DIR}/lib)
target_link_libraries(my_sfml_cinematic PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(my_sfml_cinematic PRIVATE -Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)
