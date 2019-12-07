cmake_minimum_required(VERSION 3.13.5)
project(r-type_client)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(FATAL_ERROR "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(r-type_client
        srcs/main.cpp
        srcs/Background.cpp
        srcs/GraphicWrapper.cpp)

if (MSVC)
    set(SFML_LIB_DIR "lib/SFML-2.5.1/windows")
else(MSCV)
    set(SFML_LIB_DIR "lib/SFML-2.5.1/linux")
endif(MSVC)

target_include_directories(r-type_client PUBLIC
        ./srcs/
        lib/uti/my_network/
        lib/my_sfml_character/
        ${SFML_LIB_DIR}/include/)

add_subdirectory("lib/uti/my_network")
add_subdirectory("lib/my_sfml_character/")
target_link_directories(r-type_client PRIVATE
            ${SFML_LIB_DIR}/lib)
target_link_libraries(r-type_client PRIVATE
        my_network
        sfml-graphics
        sfml-window
        sfml-system
        my_sfml_character
        ${CONAN_LIBS})

target_compile_options(r-type_client PRIVATE -Wall -Wextra)