# - Find XTENSA libraries and headers

message(STATUS "Searching for Xtensa header and libraries")

# The HINTS option should only be used for values computed from the system.
SET(_XTENSA_HINTS
  ${XTENSA_HOME}/XtensaTools/include
#  ${XTENSA_HOME}/XtensaTools/lib
#  ${XTENSA_HOME}/XtensaTools/lib/iss-GCC-4.8/systemc-2.3.1
  ${XTENSA_HOME}/XtensaTools/lib64
  ${XTENSA_HOME}/XtensaTools/lib64/iss-GCC-4.8
  ${XTENSA_HOME}/XtensaTools/lib64/iss-GCC-4.8/systemc-2.3.1
  $ENV{XTENSA_HOME}/XtensaTools/include
#  $ENV{XTENSA_HOME}/XtensaTools/lib
#  $ENV{XTENSA_HOME}/XtensaTools/lib/iss-GCC-4.8/systemc-2.3.1
  $ENV{XTENSA_HOME}/XtensaTools/lib64
  $ENV{XTENSA_HOME}/XtensaTools/lib64/iss-GCC-4.8
  $ENV{XTENSA_HOME}/XtensaTools/lib64/iss-GCC-4.8/systemc-2.3.1
  )
# Hard-coded guesses should still go in PATHS. This ensures that the user
# environment can always override hard guesses.
SET(_XTENSA_PATHS
  /usr/include/systemc
  /usr/lib
  /usr/lib-linux
  /usr/lib-linux64
  /usr/local/lib
  /usr/local/lib-linux
  /usr/local/lib-linux64
  )

FIND_FILE(_XTENSA_VERSION_FILE
  NAMES xtensa-versions.h
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
  PATH_SUFFIXES .
)

EXEC_PROGRAM("grep '#define XTENSA_RELEASE_NAME' ${_XTENSA_VERSION_FILE} | cut -d ' ' -f 2"
             OUTPUT_VARIABLE XTENSA_VERSION)

set(XTENSA_FOUND TRUE)

message(STATUS "XTENSA version = ${XTENSA_VERSION}")

FIND_PATH(XTENSA_INCLUDE_DIRS
  NAMES xtensa-params.h
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

find_library(XTENSA_BASE_LIBRARY
  NAMES xtsc
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

FIND_PATH(XTENSA_BASE_LIBRARY_DIRS
  NAMES libxtsc.a
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

find_library(XTENSA_COMP_LIBRARY
  NAMES xtsc_comp
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

FIND_PATH(XTENSA_COMP_LIBRARY_DIRS
  NAMES libxtsc_comp.a
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

find_library(XTENSA_MP_LIBRARY
  NAMES xtmp
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

FIND_PATH(XTENSA_MP_LIBRARY_DIRS
  NAMES libxtmp.so
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

find_library(XTENSA_LOG_LIBRARY
  NAMES log4xtensa
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

FIND_PATH(XTENSA_LOG_LIBRARY_DIRS
  NAMES liblog4xtensa.so
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

find_library(XTENSA_LUA_LIBRARY
  NAMES xtlua
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

FIND_PATH(XTENSA_LUA_LIBRARY_DIRS
  NAMES libxtlua.so
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

find_library(XTENSA_PARAM_LIBRARY
  NAMES xtparams
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)

FIND_PATH(XTENSA_PARAM_LIBRARY_DIRS
  NAMES libxtparams.so
  HINTS ${_XTENSA_HINTS}
  PATHS ${_XTENSA_PATHS}
)
set(XTENSA_LIBRARIES ${XTENSA_BASE_LIBRARY} ${XTENSA_COMP_LIBRARY} ${XTENSA_MP_LIBRARY} ${XTENSA_LOG_LIBRARY} ${XTENSA_LUA_LIBRARY}  ${XTENSA_PARAM_LIBRARY})

message(STATUS "XTENSA BASE library  = ${XTENSA_BASE_LIBRARY}")
message(STATUS "XTENSA comp library  = ${XTENSA_COMP_LIBRARY}")
message(STATUS "XTENSA MP library    = ${XTENSA_MP_LIBRARY}")
message(STATUS "XTENSA log library   = ${XTENSA_LOG_LIBRARY}")
message(STATUS "XTENSA lua library   = ${XTENSA_LUA_LIBRARY}")
message(STATUS "XTENSA param library = ${XTENSA_PARAM_LIBRARY}")
message(STATUS "XTENSA libraries     = ${XTENSA_LIBRARIES}")
