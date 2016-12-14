# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project ( test )
set(CMAKE_CXX_COMPILER g++)
set(SRC_DIR "${CMAKE_SOURCE_DIR}")

add_executable ( test_server chat_server.cpp  )
add_executable ( test_client chat_client.cpp  )
LIST(APPEND CMAKE_MODULE_PATH "$ENV{WORKAREA}/etc/modules")
find_package( Boost REQUIRED COMPONENTS iostreams program_options serialization thread system)

INCLUDE_DIRECTORIES   ( ${CMAKE_SOURCE_DIR}     ) 
INCLUDE_DIRECTORIES   ( ${Boost_INCLUDE_DIRS}   ) 
target_link_libraries ( test_server ${Boost_LIBRARIES}   )
target_link_libraries ( test_client ${Boost_LIBRARIES}   )
target_compile_options( test_server PUBLIC -std=c++11 -fpermissive)
target_compile_options( test_client PUBLIC -std=c++11 -fpermissive)

