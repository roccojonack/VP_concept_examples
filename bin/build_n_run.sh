#!/bin/sh

USAGE="Usage: `basename $0` [-hv] [-c ] [-d] [-t] [-r] [-a] [-p <portnum>] [-l <trlen>] [-f <finish time>] arg [arg ....]"

MODE="Release"
# MODE="Debug"
VERBOSE=""
TRLEN=4
HOST="localhost"
FINISH_TIME=2
TRANSTYPE=0
QUANTUM=10
UNIT=tb_mod

###############################################################################
# Parse command line options.
while getopts hvdrl:f:q: OPT; do
    case "$OPT" in
        h)
            echo $USAGE
            exit 0
            ;;
        v)
            VERBOSE=" --Print"
            ;;
        c)
            CLEAN="-c"
            ;;
        d)
            MODE="Debug"
            ;;
        r)
            HOST=`hostname -f`
            ;;
        l)
            TRLEN=$OPTARG
            ;;
        f)
            FINISH_TIME=$OPTARG
            ;;
        q)
            QUANTUM=$OPTARG
            ;;
        \?)
            # getopts issues an error message
            echo $USAGE >&2
            exit 1
            ;;
    esac
done
# Remove the switches we parsed above.
shift `expr $OPTIND - 1`

###############################################################################
# set some default command line arguments
cd $WORKAREA/units/$UNIT/bin
./run_test.csh 2>&1 | tee run_test.log
cd $CurrentDir
