#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads the logs of simulation runs that contain TLM2 trace produced by report::print()
#        and writes out the files which contain the transactions for different interfaces in a CSV format. This CSV file can be used for replay
# example:
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
use File::Glob ':globally';
use File::Find;

@DIRLIST = ('.');

my $FileName = "run_test.log";
my $TestName = "PrimCfgSpy";

GetOptions('FileName=s'  => \$FileName
	   ,'TestName=s' => \$TestName);

my $QuantumTime;
my $IntertransactionDelay;
my $NumberOfTransactionsMaster = 0;
my $NumberOfTransactionsSlave = 0;
push (@ListOfSources, $FileName);

# ToDo: make this generic bylooking through all interface that appear
push (@ListOfTest, "PrimCfgSpy\.ForwardingSocket_0");
push (@ListOfTest, "PrimMmrSpy\.ForwardingSocket_0");
push (@ListOfTest, "PrimDmmrSpy\.ForwardingSocket_0");
push (@ListOfTest, "audioIosfPrimIf");
push (@ListOfTest, "audioIosfSbIf");
push (@ListOfTest, "DSPs_0\.pif0_out_dbgadpt");
push (@ListOfTest, "DSPs_0\.pif1_out_dbgadpt");

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
# find(\&process_file, @DIRLIST);

foreach $file (@ListOfSources) {
    # initialize values
  
    foreach $TestName (@ListOfTest) {
	open (OUTFILE, " >$TestName.out") || die "Couldn't open $TestName.out \n";
	open (MYFILE, $file) || die "Couldn't open $file \n";
	$NumberOfTransfers = 0;
      LOOP:while(<MYFILE>) {
	  chomp;
	  s/^\s+//;
	  @elements = split(/\s+/, $_);
	  if (/^\[.+$TestName info\]\s+b_transport.* got\s+COMMAND: (\d+) LENGTH: (\d+) ADDR: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) RSP_STATUS: ([0-9A-F]+) STREAMING_WIDTH: (\d+) DMI_ALLOWED: (\d+) BYTE_ENABLE_LENGTH: (\d+).* at time (\d+) (\w+) duration (\d+)/) { 
	      $factor = 0;
	      if ($13 eq "us") {
		  $factor = 1000;
	      };
	      if ($13 eq "ms") {
		  $factor = 1000*1000;
	      };
	      if ($13 eq "ns") {
		  $factor = 1;
	      };
	      if($factor==0) {
		  print "Error: no timing factor found for $13 \n";
	      };
	      $time = $12*$factor;
	      # print "Debug: found line to be parsed $1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$time,$14 $_\n";
	      print OUTFILE "$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$time,$14\n";
	      $NumberOfTransfers++;
	      next LOOP;
	  };
	  if (/^\[.+$TestName info\]\s+b_transport.* got\s+COMMAND: (\d+)/) { 
	      print "ERROR: found unhandled line to be parsed or interface $TestName : $_\n";
	  };
      };
	print "$TestName has $NumberOfTransfers b_transport transfers\n";
	close(MYFILE);
    };
};

