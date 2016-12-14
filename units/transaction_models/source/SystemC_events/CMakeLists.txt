# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_COMPILER g++)
set(USE_SYSTEMC yes)
set(USE_BOOST yes)
project ( SystemC_events )

include (${CMAKE_SOURCE_DIR}/../CMakeLists.txt)

enable_testing()
add_test( test1 ${EXEC_NAME} )
