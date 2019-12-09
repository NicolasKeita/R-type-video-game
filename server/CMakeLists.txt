cmake_minimum_required(VERSION 3.13.5)
project(r-type)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(r-type_server
        srcs/main.cpp
        srcs/GameInfo.cpp)

target_include_directories(r-type_server PUBLIC
        ./srcs/
        lib/uti/my_network/
        lib/uti/my_string/)

#add_subdirectory("${CMAKE_HOME_DIRECTORY}/lib/uti/my_network" build)
#target_link_directories(r-type_client PRIVATE ${SFML_LIB_DIR}/lib)
target_link_libraries(r-type_server PRIVATE
        my_network
        ${CONAN_LIBS})

target_compile_options(r-type_server PRIVATE -Wall -Wextra -g3)

add_custom_command(TARGET r-type_server
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_server> ${CMAKE_HOME_DIRECTORY})
