#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads the logs of simulation runs and writes out the results in CSV format
# example:
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
use File::Glob ':globally';
use File::Find;

@DIRLIST = ('.');

my $FileName = "run_test.log";

GetOptions('FileName=s'  => \$FileName
	       ,'TestName=s' => \$TestName);

my $QuantumTime;
my $IntertransactionDelay;
my $NumberOfTransactionsMaster = 0;
my $NumberOfTransactionsSlave = 0;
my $TransactionType;
my $host;
my $NumberOfFSInstances;
my $sim_time;
my $RunTimeInSec;
my $Workload;
my $Initiator;
my $Interconnect;
my $Target;
my $InitConnSocket;
my $TargetConnSocket;
my $InitMonitor;
my $TargetMonitor;
my $NumberOfRestarts;

use File::Find;
sub process_file {
  if (! -d) {
    # print "Debug: found : $File::Find::name \n";
    if ($File::Find::name =~ /run_test\.\d/) {
      push (@ListOfSources, $File::Find::name);
      # print "Debug: found log : $File::Find::name \n";
    };
  };
};
find(\&process_file, @DIRLIST);

print "Initiator,Performance,InitConnectorSocket,InitMonitor,Interconnect,TargetMonitor,TargetConnectorSocket,Target,QuantumTime,IntertransactionDelay,Transactions,TransactionType,NumberOfFSInstances,Runtime,SimulationTime,Workload\n";
foreach $file (@ListOfSources) {
	# initialize values
	$QuantumTime = "unknown";
	$IntertransactionDelay = "unknown";
	$NumberOfTransactionsMaster = 0;
	$NumberOfTransactionsSlave = 0;
	$TransactionType = "unknown";
	$host = "unknown";
	$NumberOfFSInstances = "unknown";
	$sim_time = "unknown";
	$RunTimeInSec = "unknown";
	$Workload = 0;
	$Initiator = "unknown";
    $Performance = "unknown";
	$Interconnect = "unknown";
	$Target = "unknown";
	$InitConnSocket = "unknown";
	$TargetConnSocket = "unknown";
	$InitMonitor = "unknown";
	$TargetMonitor = "unknown";
	$CPU = 0;
	$NumberOfRestarts = 0;

	open (MYFILE, $file) || die "Couldn't open $file \n";
	while(<MYFILE>) {
  	    chomp;
    	s/^\s+//;
  		@elements = split(/\s+/, $_);
  		if (/^QuantumTime/) { # taken from testbench option output
    		$QuantumTime = $elements[2];
  		};
  		if (/^InitType/) {   # taken from testbench option output
    		$Initiator = $elements[2];
  		};
        if (/^Performance/) {   # taken from testbench option output
            $Performance = $elements[2];
        };
        if (/^CPU MHz/) {   # taken from testbench option output
            $CPU = $elements[2];
        };
   		if (/^Interconnect/) { # taken from testbench option output
    		$Interconnect = $elements[2];
  		};
   		if (/^SlaveType/) { # taken from testbench option output
    		$Target = $elements[2];
  		};
  		if (/^InitConnector/) { # taken from testbench option output
    		$InitConnSocket = $elements[2];
  		};
  		if (/^SlaveConnector/) { # taken from testbench option output
    		$TargetConnSocket = $elements[2];
  		};
  		if (/^InitMonitor/) { # taken from testbench option output
    		$ InitMonitor= $elements[2];
  		};
   		if (/^SlaveMonitor/) { # taken from testbench option output
    		$SlaveMonitor = $elements[2];
  		};
   		if (/^IntertransactionDelay/) { # taken from testbench option output
    		$IntertransactionDelay = $elements[2];
  		};
  		#if (/There are (\d+) b_transport calls, (\d+) transport_dbg calls, (\d+) DMI calls over socket: (\S+)/) { #
  		#  $NumberOfTransactions += $1 + $2 + $3;
  		#};
  		if (/Information: summary transaction counter : (\d+) and number of quantum sync events : (\d+) for master (\S+)/) { #
    		$NumberOfTransactionsMaster += $1;
  		};
  		if (/Information: summary transaction counter : (\d+) for slave (\S+)/) { #
    		$NumberOfTransactionsSlave += $1;
  		};
  		if (/TransactionType/) { # taken from testbench option output
    		$TransactionType = $elements[2];
  		};
  		if (/running .* on host\s+(\S+)/) { # taken from script output
    		$host = $1;
  		};
  		if (/Information: simulation ended at time (\d+) s/) { # taken from testbench option output
    		$sim_time = $1;
  		};
        if (/Information: simulation ended at time (\d+) ms/) { # taken from testbench option output
            $sim_time = $1/1000;
        };
  		if (/Total execution time in (\S+) is (\S+)/) { # taken from output of models
    		my $Runtime = $2;
  			my @tmp = split(/:/, $Runtime);
    		$RunTimeInSec = ($tmp[0]*60*60)+($tmp[1]*60)+$tmp[2];
    		if ($RunTimeInSec>0) {
	    		$WorkLoad = $NumberOfTransactionsMaster/$RunTimeInSec;
			}
			else {
	    		printf "arithmetic error; divide by 0 $RunTimeInSec\n"
  			};
  		};
  		if (/NumberOfFSInstances/) { # taken from testbench option output
    		$NumberOfFSInstances = $elements[2];
  		};
  		if (/Information: starting simulation for/) { # taken from testbench option output
    		$NumberOfRestarts++;
  		};
  		if (/^Bye/) { # last statement in sc_main, so we are garanteed to be finished
    		printf "$Initiator,$Performance,$InitConnSocket,$InitMonitor,$Interconnect,$SlaveMonitor,$TargetConnSocket,$Target,$QuantumTime,$IntertransactionDelay,$NumberOfTransactionsMaster,$TransactionType,$NumberOfFSInstances,$RunTimeInSec,$sim_time,$WorkLoad,$CPU,$NumberOfRestarts,$file\n";
     		$NumberOfTransactionsMaster = 0;
     		$NumberOfTransactionsSlave = 0;
		$CPU = 0;
  		};
	};
	close(MYFILE);
};

