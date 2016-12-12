#!/bin/sh

# this script is meant as a template; adapt to your needs
EXECUTABLE="$WORKAREA/units/tb_mod/sc_sim/bin-Linux_64/gcc_4.5.2/Debug/tb_mod-Debug.x"
PROFILE_NAME = "myprofile.txt"
OPTIONS =""

setenv HEAPPROFILE $PROFILE_NAME
setenv CPUPROFILE  $PROFILE_NAME

#run executable
$EXECUTABLE $OPTIONS

#run the analysis for memory profiling
/home/demo/tools/gperftools/bin/pprof $EXECUTABLE --text $PROFILE_NAME

