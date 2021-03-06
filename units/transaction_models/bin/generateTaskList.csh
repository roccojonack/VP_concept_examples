#! /bin/bash -f
#
# test the tb_mod units;
# iterating over all possibilities with testcases
# variable test_version defines which of the 3 variations of test are being run
MODE="Release"
# MODE="Debug"
COMPILER="gcc_4.9.3"
UNIT="tb_mod"
myPWD=`pwd`
sim_time=0.25
runtime_limit=10
test_version=1
performance=
verification=
output_marker=
count=1
transaction_type=0
# distinguish between runtime test(0); test for memory leakage(1); test for profiling(2); test for hierarchy(3)
test_type=0
scan=
command=
log_prefix="run_test"

# Parse command line options.
while getopts hi:pt:r:s:v OPT; do
    case "$OPT" in
        h)
            echo "usage: run_test.csh -t [1-3] -i [1-] -p -c -h"
            exit 0
            ;;
        i)
            count=$OPTARG
            ;;
        p)
            performance=--Performance
	    	output_marker="p"
            ;;
        t)
            test_version=$OPTARG
            ;;
        r)
            test_type=$OPTARG
            ;;
        s)
            sim_time=$OPTARG
            ;;
        v)
            verification=--Verification --Random
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

# running the executable while iterating over different configurations
if [ $test_version == "1" ]; then
    # for Interconnect in 0; do
    for Interconnect in 0 1; do
    	for transaction_type in 0 1 2; do
    	    for InitType in 1; do
    		for SlaveType in 1; do
		    # for time in 10 100 1000 10000 100000; do
		    for time in 1000; do
			# for delay in 1 5 10 50 100 500 1000 5000 10000 50000 100000; do
			for delay in 100; do
			    if [[ ( $test_type -eq 3 ) && ( ( $time -ne 10 ) || ( $delay -ne 1 ) ) ]]; then
				continue
			    fi
			    sim_time=1
			    if [ $[$delay/$count] -gt 10 ]; then
				sim_time=10
			    fi
			    if [ $[$delay/$count] -gt 100 ]; then
				sim_time=100
			    fi
			    if [ $[$delay/$count] -gt 1000 ]; then
				sim_time=1000
			    fi
			    if [ $[$delay/$count] -gt 10000 ]; then
				sim_time=10000
			    fi
			    if [ $time -eq 10 ]; then
				sim_time=$(echo "scale=4; $sim_time/6" | bc -l)
			    fi
			    if [ $time -eq 100 ]; then
				sim_time=$(echo "scale=4; $sim_time/5" | bc -l)
			    fi
			    if [ $time -eq 1000 ]; then
				sim_time=$(echo "scale=4; $sim_time/4" | bc -l)
			    fi
			    if [ $time -eq 10000 ]; then
				sim_time=$(echo "scale=4; $sim_time/3" | bc -l)
			    fi
			    if [ $time -eq 100000 ]; then
				sim_time=$(echo "scale=4; $sim_time/2" | bc -l)
			    fi
			    if [ $InitType -eq 3 ]; then
				sim_time=$(echo "scale=4; $sim_time/10" | bc -l)
			    fi
			    if [ $InitType -eq 4 ]; then
				sim_time=$(echo "scale=4; $sim_time/20" | bc -l)
			    fi
			    if [ $test_type -eq 1 ]; then
				sim_time=$(echo "scale=4; $sim_time/10" | bc -l)
				runtime_limit=1
				MODE="Debug"
				command="/nfs/imu/proj/dbb/vpmuc/third_party/tools/valgrind/bin/valgrind --leak-check=full"
				log_prefix="run_mem"
			    fi
			    if [ $test_type -eq 2 ]; then
				sim_time=$(echo "scale=4; $sim_time/10" | bc -l)
				command="/nfs/imu/proj/dbb/vpmuc/third_party/tools/valgrind/bin/valgrind --tool=callgrind"
				MODE="Debug"
				log_prefix="run_profile"
			    fi
			    if [ $test_type -eq 3 ]; then
				sim_time=0.000001
				runtime_limit=0
				scan="--scan"
				log_prefix="run_scan"
			    fi
			    # echo "options are: $sim_time $delay $time $InitType $SlaveType $count $performance"
       			    # echo "lscpu >& logs/run_test.$delay.$transaction_type.$time.$InitType.$SlaveType.$Interconnect.$count.$performance; \
			    echo "$command \$WORKAREA/units/${UNIT}/build/tb/testbench_${UNIT} \
	    	      		--Simulation $sim_time \
                    		--RuntimeLimit $runtime_limit \
	       			--IntertransactionDelay $delay \
       				--TransactionType $transaction_type \
	  			--QuantumTime $time \
	    			--InitType $InitType \
	       			--SlaveType $SlaveType \
	  			--Interconnect $Interconnect \
	    		    	--NumberOfFSInstances $count \
	   		     	$performance $scan $verification >>& \
	   		     	logs/$log_prefix.$delay.$transaction_type.$time.$InitType.$SlaveType.$Interconnect.$count.$performance"
			done
		    done
		done
	    done
	done
    done
fi

