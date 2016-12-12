# - Find ISCTLM libraries and headers
#

message(STATUS "Searching for ISCTLM header and libraries")

# The HINTS option should only be used for values computed from the system.
SET(_ISCTLM_HINTS
  ${SWYTLM}/incl
  ${SWYTLM}/lib
  ${SWYTLM}/lib64
  $ENV{SWYTLM}/incl
  $ENV{SWYTLM}/lib
  $ENV{SWYTLM}/lib64
  )
# Hard-coded guesses should still go in PATHS. This ensures that the user
# environment can always override hard guesses.
SET(_ISCTLM_PATHS
  /usr/include/systemc
  /usr/lib
  /usr/lib-linux
  /usr/lib-linux64
  /usr/lib-macos
  /usr/local/lib
  /usr/local/lib-linux
  /usr/local/lib-linux64
  /usr/local/lib-macos
  )
FIND_FILE(_ISCTLM_VERSION_FILE
  NAMES isctlm_version.h
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
  PATH_SUFFIXES .
)

# SystemC < 2.3.1
#EXEC_PROGRAM("cat ${_SYSTEMC_VERSION_FILE} |grep '#define SC_API_VERSION_STRING' | cut -d '_' -f 7 "
#             OUTPUT_VARIABLE SystemC_MAJOR)
#EXEC_PROGRAM("cat ${_SYSTEMC_VERSION_FILE} |grep '#define SC_API_VERSION_STRING' | cut -d '_' -f 8 "
#             OUTPUT_VARIABLE SystemC_MINOR)
#EXEC_PROGRAM("cat ${_SYSTEMC_VERSION_FILE} |grep '#define SC_API_VERSION_STRING' | cut -d '_' -f 9 "
#             OUTPUT_VARIABLE SystemC_REV)

# SystemC >= 2.3.1
if("${SystemC_MAJOR}" MATCHES "")
EXEC_PROGRAM("grep '#define SC_VERSION_MAJOR' ${_SYSTEMC_VERSION_FILE} | cut -d ' ' -f 8"
             OUTPUT_VARIABLE SystemC_MAJOR)
EXEC_PROGRAM("grep '#define SC_VERSION_MINOR' ${_SYSTEMC_VERSION_FILE} | cut -d ' ' -f 8"
             OUTPUT_VARIABLE SystemC_MINOR)
EXEC_PROGRAM("grep '#define SC_VERSION_PATCH' ${_SYSTEMC_VERSION_FILE} | cut -d ' ' -f 8"
             OUTPUT_VARIABLE SystemC_REV)
endif("${SystemC_MAJOR}" MATCHES "")

set(ISCTLMVERSION "bla")

# if("${SystemC_MAJOR}" MATCHES "2")
  set(ISCTLM_FOUND TRUE)
# endif("${SystemC_MAJOR}" MATCHES "2")

message(STATUS "ISCTLM version = ${ISCTLM_VERSION}")

FIND_PATH(ISCTLM_INCLUDE_DIRS
  NAMES tlm_base.h
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

find_library(ISCTLM_BASE_LIBRARIES
  NAMES tlm_base
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

FIND_PATH(ISCTLM_BASE_LIBRARY_DIRS
  NAMES libtlm_base.a
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

find_library(ISCTLM_GENIP_LIBRARIES
  NAMES tlm_genip
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

FIND_PATH(ISCTLM_GENIP_LIBRARY_DIRS
  NAMES libtlm_genip.a
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

find_library(ISCTLM_IA_LIBRARIES
  NAMES tlm_ia
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

FIND_PATH(ISCTLM_IA_LIBRARY_DIRS
  NAMES libtlm_ia.a
  HINTS ${_ISCTLM_HINTS}
  PATHS ${_ISCTLM_PATHS}
)

message(STATUS "ISCTLM BASE library  = ${ISCTLM_BASE_LIBRARIES}")
message(STATUS "ISCTLM GENIP library = ${ISCTLM_GENIP_LIBRARIES}")
message(STATUS "ISCTLM GENIP library = ${ISCTLM_IA_LIBRARIES}")
