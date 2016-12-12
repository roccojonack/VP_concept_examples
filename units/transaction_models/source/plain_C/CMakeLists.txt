# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.7)
project ( test )
set(CMAKE_CXX_COMPILER g++)
set(SRC_DIR "${CMAKE_SOURCE_DIR}")

FILE(GLOB MyCSources *.cpp)
add_executable ( test ${MyCSources})
LIST(APPEND CMAKE_MODULE_PATH "$ENV{WORKAREA}/etc/modules")
# FIND_PACKAGE(SystemC)
find_package( Boost REQUIRED COMPONENTS iostreams program_options serialization thread system)

INCLUDE_DIRECTORIES   ( ${CMAKE_SOURCE_DIR}       ) 
# INCLUDE_DIRECTORIES   ( ${SystemC_INCLUDE_DIRS}   ) 
INCLUDE_DIRECTORIES   ( ${Boost_INCLUDE_DIRS}   ) 
target_link_libraries      ( test ${Boost_LIBRARIES}   )
# target_compile_definitions ( test PUBLIC -DSC_INCLUDE_DYNAMIC_PROCESSES )
