# - Find libraries and headers from another unit

SET(UNIT tb_mod)
message(STATUS "Searching for header and libraries for unit ${UNIT}")

# The HINTS option should only be used for values computed from the system.
SET(_tb_mod_HINTS
  $ENV{WORKAREA}/units/${UNIT}/install/include/beh
  $ENV{WORKAREA}/units/${UNIT}/install/lib
  )
# Hard-coded guesses should still go in PATHS. This ensures that the user
# environment can always override hard guesses.
SET(_tb_mod_PATHS
  )

set(tb_mod_FOUND TRUE)

FIND_PATH(tb_mod_INCLUDE_DIRS
  NAMES ${UNIT}_init_options.h
  HINTS ${_tb_mod_HINTS}
  PATHS ${_tb_mod_PATHS}
)

find_library(tb_mod_LIBRARIES
  NAMES ${UNIT}
  HINTS ${_tb_mod_HINTS}
  PATHS ${_tb_mod_PATHS}
)
FIND_PATH(tb_mod_LIBRARY_DIRS
  NAMES lib${UNIT}.a
  HINTS ${_tb_mod_HINTS}
  PATHS ${_tb_mod_PATHS}
)
message(STATUS "tb_mod library = ${tb_mod_LIBRARIES}")
message(STATUS "tb_mod include = ${tb_mod_INCLUDE_DIRS}")

