#! /bin/bash -f

# test the  units in transaction_models;
# build the different testcases
# TODO: should become a perl program and generic for any unit
MODE=""
UNIT="transaction_models"
PWD=`pwd`
clean=0

# Parse command line options.
while getopts hcd OPT; do
    case "$OPT" in
        h)
            echo "usage: "
            exit 0
            ;;
        c)
            clean=1
            echo "make a clean before building"
            ;;
       	d)
            MODE="-D CMAKE_BUILD_TYPE=Debug"
            ;;
        \?)
            # getopts issues an error message
            echo "unknown options" >&2
            exit 1
            ;;
    esac
done
# Remove the switches we parsed above.
shift `expr $OPTIND - 1`

# compiling the library and the test VP executable
for test in plain_C SystemC_events SystemC_signal SystemC_trans; do
    cd ${WORKAREA}/units/${UNIT}/build
    if [ ! -d "$test" ]; then
	mkdir $test
    fi
    cd $test
    if [ $clean -eq 1 ]; then
	\rm -rf *
	# gmake clean
    fi
    cmake $MODE ${WORKAREA}/units/${UNIT}/source/$test
    gmake
done





