cmake_minimum_required(VERSION 3.12.4)
project(my_network_library_tests)

find_package(Boost 1.69.0 REQUIRED)
find_package(Threads)
find_program(BASH_PROGRAM bash)

include_directories(
        ${BOOST_INCLUDE_DIRS}
        ./
        ../)

#message(${CMAKE_COMMAND} " " --build " "${CMAKE_BINARY_DIR} " " --target " "${CMAKE_HOME_DIRECTORY}/tests/test_1_source_code/serv.cpp)
add_executable(test_serv test_1_source_code/serv.cpp)
add_executable(test_client test_1_source_code/client.cpp)
#target_link_directories(test_serv PUBLIC ../build)
target_link_libraries(test_serv
        ${CMAKE_THREAD_LIBS_INIT}
        my_network)
target_link_libraries(test_client
        ${CMAKE_THREAD_LIBS_INIT}
        my_network)

configure_file(${CMAKE_HOME_DIRECTORY}/tests/test_10_msgs.sh test_10_msgs.sh COPYONLY)
add_test(test_network_0
        ${CMAKE_COMMAND} --build ./)
add_test(test_network_1
        ${BASH_PROGRAM} test_10_msgs.sh)
set_tests_properties(test_network_1 PROPERTIES DEPENDS test_network_0)