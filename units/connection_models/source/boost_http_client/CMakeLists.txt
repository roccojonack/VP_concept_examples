#
cmake_minimum_required (VERSION 2.8.11)
project (testbench_tcp4tlm2)
set(CMAKE_CXX_COMPILER g++)
set(UNIT_DIR tcp4tlm2)
set(EXEC_NAME testbench_tcp4tlm2)

FILE(GLOB MyCSources *.cpp)
add_executable (${EXEC_NAME} ${MyCSources})

LIST(APPEND CMAKE_MODULE_PATH "$ENV{WORKAREA}/etc/modules")
find_package( Boost REQUIRED COMPONENTS iostreams program_options serialization thread system)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries( ${EXEC_NAME} ${Boost_LIBRARIES} )
# target_compile_options    ( ${EXEC_NAME} PUBLIC -std=-fpermissive )
