#! /bin/bash -f
#
# test the tb_mod units;
# build the design
# iterating over all possibilities with testcases
# TODO: should become a perl program and generic for any unit
MODE=""
# MODE="-D CMAKE_BUILD_TYPE=Debug"
UNIT="tb_mod"
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

# main entry point for automated test runs on this module
# build the excutable
# enter all tests that should be run automatically in
# evaluate all results

./build.bash 
$WORKAREA/bin/run_test.pl -f task_list.txt -n 20

# analysis steps after regression runs
# ./evaluate_build.pl > evaluate_build.csv
# $WORKAREA/bin/csv_html.pl < evaluate_build.csv > evaluate_build.html
# $WORKAREA/bin/analyze_code.pl
# $WORKAREA/bin/csv_html.pl < statistics.txt > statistics.html
