#
cmake_minimum_required (VERSION 2.8.11)
project (testbench_http_server)
set(CMAKE_CXX_COMPILER g++)
set(UNIT_DIR connection_models)
set(EXEC_NAME testbench_http_server)

FILE(GLOB MyCSources *.cpp)
add_executable (${EXEC_NAME} ${MyCSources})

LIST(APPEND CMAKE_MODULE_PATH "$ENV{WORKAREA}/etc/modules")
find_package( Boost REQUIRED COMPONENTS iostreams program_options serialization thread system)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries( ${EXEC_NAME} ${Boost_LIBRARIES} )

