#! /bin/bash -f

# test the  units in transaction_models;
# build the different testcases
# TODO: should become a perl program and generic for any unit
MODE="-D CMAKE_BUILD_TYPE=Release"
UNIT="connection_models"
ELEMENTS="boost_asio_usage boost_http_client simple_socket"
PWD=`pwd`
clean=0

# Parse command line options.
while getopts hcdr OPT; do
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
       	r)
            MODE="-D CMAKE_BUILD_TYPE=Release"
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

cd ${WORKAREA}/units/${UNIT}
if [ ! -d "build" ]; then
    mkdir build
fi

# compiling the different elements in the unit and execute tests
for test in ${ELEMENTS}; do
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
    # gmake test
done





