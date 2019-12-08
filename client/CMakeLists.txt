cmake_minimum_required(VERSION 3.13.5)
project(r-type)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(r-type_client
		srcs/main.cpp
		srcs/Background.cpp
		srcs/GraphicWrapper.cpp
		srcs/Player_pos.cpp)

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

add_custom_command(TARGET r-type_client
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:r-type_client> ${CMAKE_HOME_DIRECTORY})
