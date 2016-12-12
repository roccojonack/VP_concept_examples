# - Find SCML

message(STATUS "Searching for SCML")

# The HINTS option should only be used for values computed from the system.
SET(_SCML_HINTS
  ${SCML_HOME}/include
  ${SCML_HOME}/lib-linux64
  $ENV{SCML_HOME}/include
  $ENV{SCML_HOME}/lib-linux64
  )
# Hard-coded guesses should still go in PATHS. This ensures that the user
# environment can always override hard guesses.
SET(_SCML_PATHS
  /usr/include/systemc
  /usr/lib
  /usr/lib-linux
  /usr/lib-linux64
  /usr/local/lib
  /usr/local/lib-linux
  /usr/local/lib-linux64
  )

set(SCML_VERSION 2.3.1)

FIND_PATH(SCML_INCLUDE_DIRS
  NAMES scml.h
  HINTS ${_SCML_HINTS}
  PATHS ${_SCML_PATHS}
)

find_library(SCML_BASE_LIBRARY
  NAMES scml2
  HINTS ${_SCML_HINTS}
  PATHS ${_SCML_PATHS}
)

find_library(SCML_LOG_LIBRARY
  NAMES scml2_logging
  HINTS ${_SCML_HINTS}
  PATHS ${_SCML_PATHS}
)

find_library(SCML_TEST_LIBRARY
  NAMES scml2_testing
  HINTS ${_SCML_HINTS}
  PATHS ${_SCML_PATHS}
)

find_library(SCML_MODEL_LIBRARY
  NAMES ModelingObjects
  HINTS ${_SCML_HINTS}
  PATHS ${_SCML_PATHS}
)

set (SCML_LIBRARIES ${SCML_BASE_LIBRARY} ${SCML_LOG_LIBRARY} ${SCML_TEST_LIBRARY} ${SCML_MODEL_LIBRARY})

FIND_PATH(SCML_LIBRARY_DIRS
  NAMES libscml2.a
  HINTS ${_SCML_HINTS}
  PATHS ${_SCML_PATHS}
)

message(STATUS "SCML library = ${SCML_LIBRARIES}")
