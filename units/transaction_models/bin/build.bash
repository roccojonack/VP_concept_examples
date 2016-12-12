#! /bin/bash -f
#
# test the tb_mod units;
# build the design
# iterating over all possibilities with testcases
# TODO: should become a perl program and generic for any unit
MODE=""
# MODE="-D CMAKE_BUILD_TYPE=Debug"
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
cd ${WORKAREA}/units/${UNIT}/build
cmake $MODE ../source/plain_C
if [ $clean -eq 1 ]; then
	gmake clean
fi
gmake
# gmake doc
# gmake eclipse




