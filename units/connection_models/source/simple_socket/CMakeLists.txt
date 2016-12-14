# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6 )
project (testbench_simple_socket)
set(CMAKE_CXX_COMPILER g++)
set(UNIT_DIR connection_models)
set(EXEC_NAME testbench_simple_socket)

add_executable ( test_server server.cpp)
add_executable ( test_client client.cpp)
add_executable ( test_main   main.cpp)
LIST(APPEND CMAKE_MODULE_PATH "$ENV{WORKAREA}/etc/modules")
find_package( Boost REQUIRED COMPONENTS iostreams program_options serialization thread system)

INCLUDE_DIRECTORIES   ( ${CMAKE_SOURCE_DIR}     ) 
INCLUDE_DIRECTORIES   ( ${Boost_INCLUDE_DIRS}   ) 
target_compile_options      ( test_server PUBLIC -fpermissive )
target_compile_options      ( test_main   PUBLIC -fpermissive )
