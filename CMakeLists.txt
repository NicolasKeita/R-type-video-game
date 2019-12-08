cmake_minimum_required(VERSION 3.14)
project(r-type)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(FATAL_ERROR "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_subdirectory("${CMAKE_HOME_DIRECTORY}/lib/uti/my_network")
add_subdirectory("./server/")
add_subdirectory("./client/")
