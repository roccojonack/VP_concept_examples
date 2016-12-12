# - Find headers for AMBA extensions 

SET(UNIT amba)
message(STATUS "Searching for headers for AMBA extensions")

# The HINTS option should only be used for values computed from the system.
SET(_AMBA_HINTS
  $ENV{AMBA_HOME}
  $ENV{AMBA_HOME}/dependencies
  $ENV{AMBA_HOME}/dependencies/AMBA-PV/include
  )
# Hard-coded guesses should still go in PATHS. This ensures that the user
# environment can always override hard guesses.
SET(_AMBA_PATHS
  )

set(AMBA_FOUND TRUE)

# message(STATUS "XTENSA version = ${XTENSA_VERSION}")

FIND_PATH(AMBA_INCLUDE_DIR1
  NAMES ${UNIT}.h
  HINTS ${_AMBA_HINTS}
  PATHS ${_AMBA_PATHS}
)
FIND_PATH(AMBA_INCLUDE_DIR2
  NAMES ${UNIT}_pv.h
  HINTS ${_AMBA_HINTS}
  PATHS ${_AMBA_PATHS}
)

set(AMBA_INCLUDE_DIRS ${AMBA_INCLUDE_DIR1} ${AMBA_INCLUDE_DIR2} $ENV{AMBA_HOME}/dependencies)
message(STATUS "AMBA include = ${AMBA_INCLUDE_DIRS}")
