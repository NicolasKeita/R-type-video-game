cmake_minimum_required(VERSION 3.13.5)
project(r-type)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(r-type_client
		srcs/main.cpp
		srcs/Background.cpp
		srcs/GraphicWrapper.cpp
		srcs/GameEngine.cpp
		srcs/PlayerBoard.cpp
		srcs/NetworkManager.cpp
        )

target_include_directories(r-type_client PUBLIC
		./srcs/
		../lib/uti/my_network/
		../lib/uti/my_string/
		../lib/uti/my_prog_args/
		lib/my_sfml_character/
		lib/my_sfml_cinematic/)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/my_sfml_character/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/my_sfml_cinematic/")


target_link_directories(r-type_client PUBLIC
		${CONAN_LIB_DIRS}
		../lib/uti/my_network)

find_library(sfml-graphics NAMES sfml-graphics PATHS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
find_library(sfml-window NAMES sfml-window PATHS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
find_library(sfml-system NAMES sfml-system PATHS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
find_library(sfml-audio NAMES sfml-audio PATHS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

target_link_libraries(r-type_client PUBLIC
		${sfml-graphics}
		${sfml-window}
		${sfml-system}
		${sfml-audio}
		my_network
		my_sfml_character
		my_sfml_cinematic
		)

if(CMAKE_COMPILER_IS_GNUCXX)
	target_compile_options(r-type_client PRIVATE -Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)
