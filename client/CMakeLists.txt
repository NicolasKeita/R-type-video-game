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

if (MSVC)
	set(SFML_LIB_DIR "lib/SFML-2.5.1/windows")
else(MSCV)
	set(SFML_LIB_DIR "lib/SFML-2.5.1/linux")
endif(MSVC)

target_include_directories(r-type_client PUBLIC
		./srcs/
		../lib/uti/my_network/
		../lib/uti/my_string/
		../lib/uti/my_prog_args/
		lib/my_sfml_character/
		lib/my_sfml_cinematic/
		${SFML_LIB_DIR}/include/)

add_subdirectory("lib/my_sfml_character/")
add_subdirectory("lib/my_sfml_cinematic/")
target_link_directories(r-type_client PRIVATE
		${SFML_LIB_DIR}/lib
		../lib/uti/my_network)

target_link_libraries(r-type_client PRIVATE
		my_network
		sfml-graphics
		sfml-window
		sfml-system
		sfml-audio
		my_sfml_character
		my_sfml_cinematic
		${CONAN_LIBS})

target_compile_options(r-type_client PRIVATE -Wall -Wextra -g3)

add_custom_command(TARGET r-type_client
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_client> ${CMAKE_HOME_DIRECTORY})
