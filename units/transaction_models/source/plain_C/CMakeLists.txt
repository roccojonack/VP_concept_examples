# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
set(USE_SYSTEMC no)
set(CMAKE_CXX_COMPILER g++)
set(USE_BOOST yes)
project(plain_C)

include (${CMAKE_SOURCE_DIR}/../CMakeLists.txt)
