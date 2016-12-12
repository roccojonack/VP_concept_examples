#! /bin/bash -f

for Interconnect in 0 1; do
    for transaction_type in 0 1 2; do
	for InitType in 1; do
	    for SlaveType in 1; do
		for Instances in 1 10; do
$WORKAREA/units/tb_mod/build/tb/testbench_tb_mod \
    --Simulation 0.0001 \
    --IntertransactionDelay 100 \
    --TransactionType 0 \
    --QuantumTime 1000 \
    --InitType 1 \
    --SlaveType 1 \
    --Interconnect 0 \
    --NumberOfFSInstances 1
 		done
	    done
	done
    done
done
 

 
