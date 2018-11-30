# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
set(EXEC_NAME testbench)
set(SRC_DIR "${CMAKE_SOURCE_DIR}")

FILE(GLOB MyCSources ${SRC_DIR}/*.cpp)
add_executable ( ${EXEC_NAME} ${MyCSources})
LIST(APPEND CMAKE_MODULE_PATH "$ENV{WORKAREA}/etc/modules")
INCLUDE_DIRECTORIES   ( ${CMAKE_SOURCE_DIR}       ) 

if (USE_SYSTEMC STREQUAL yes)
   FIND_PACKAGE(SystemC)
   INCLUDE_DIRECTORIES   ( ${SystemC_INCLUDE_DIRS}   ) 
   target_link_libraries( ${EXEC_NAME}  /workarea/tools/systemc-2.3.1-install/lib-linux64/libscv.a ${SystemC_LIBRARIES} )
endif()

if (USE_BOOST STREQUAL yes)
   find_package( Boost REQUIRED COMPONENTS iostreams program_options serialization thread system)
   INCLUDE_DIRECTORIES   ( ${Boost_INCLUDE_DIRS}   ) 
   target_link_libraries( ${EXEC_NAME} ${Boost_LIBRARIES})
endif()

set (CMAKE_CXX_FLAGS "-std=c++0x -DSC_INCLUDE_DYNAMIC_PROCESSES ${CMAKE_CXX_FLAGS}")
