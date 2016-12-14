#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads a CSV file and reformats the CSV into summary CSV files which are
#        easier to read and for data visualisation post processing;
# example: summary_result.pl -f my_csv_file.csv
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;

# default values
my $FileName     = "run_test.log";
# read command line options
GetOptions( 'FileName=s' => \$FileName
	       );

open (MYFILE, $FileName) || die "Couldn't open $FileName \n";
my %workload_ach;
my $first = 1;
my $lineCounter = 2;

# loop over input CSV file and put interesting values into array
LOOP:while(<MYFILE>) {
  chomp;
  s/^\s+//;
  @elements = split(/,/, $_);
  if ($first==1) { # remove first line
    $first = 0;
    $counter = 0;
    foreach $element (@elements) {
        push(@keys, $element);
        if ($element eq "NumberOfFSInstances") {
            $numberOfInstancesKey = $counter;
        };
        if ($element eq "QuantumTime") {
            $quantumKey = $counter;
        };
        if ($element eq "IntertransactionDelay") {
            $delayKey = $counter;
        };
        if ($element eq "Runtime") {
            $runtimeKey = $counter;
        };
        if ($element eq "SimulationTime") {
            $simtimeKey = $counter;
        };
        if ($element eq "Transactions") {
            $transactionsKey = $counter;
        };
        if ($element eq "TransactionType") {
            $transactionTypeKey = $counter;
        };
        if ($element eq "Workload") {
            $workloadKey = $counter;
        };
        # print "Debug: pushed new key $element at $counter\n";
        $counter++;
    };
    next LOOP;
  };
  $currentDesign    = "$elements[0]$elements[1]$elements[2]$elements[3]$elements[4]$elements[5]$elements[6]$elements[7]";
  $currentInstances = $elements[$numberOfInstancesKey];
  $Quantum          = $elements[$quantumKey];
  $type             = $elements[$transactionTypeKey];
  $simtime          = $elements[$simtimeKey];
  $workload_request = 1000000000/$elements[$delayKey];
  $runtime          = $elements[$runtimeKey];
  $cpu_frequenz     = $elements[$#elements-2];
  $restarts     = $elements[$#elements-1];
  # print "Debug: $cpu_frequenz\n";
  if ($runtime < 10) {
    print "Warning: runtime $runtime is very small for $Quantum $currentDesign $currentInstances $simtime $type $workload_request in line $lineCounter\n"
  };
  if ($runtime > 25) {
    print "Warning: runtime $runtime is very large for $Quantum $currentDesign $currentInstances $simtime $type $workload_request in line $lineCounter\n"
  };
  if ($restarts > 10) {
    print "Warning: a lot of restarts to achieve runtime ($restarts) for $Quantum $currentDesign $currentInstances $simtime $type $workload_request in line $lineCounter\n"
  };
  # print "Debug: pushed for $Quantum $currentDesign $currentInstances $type $workload_request : $elements[$workloadKey]\n";
  if (exists $workload_ach{$Quantum}{$currentDesign}{$currentInstances}{$type}{$workload_request}) {
    print "Warning: already found element for $Quantum $currentDesign $currentInstances $type $workload_request in line $lineCounter\n";
  };
  # $workload_ach{$Quantum}{$currentDesign}{$currentInstances}{$type}{$workload_request} = $elements[$workloadKey]/($cpu_frequenz/1000);
  $workload_ach{$Quantum}{$currentDesign}{$currentInstances}{$type}{$workload_request} = $elements[$workloadKey];
  $lineCounter++;
};
close(MYFILE);

# iterating over the main array to see which design variations exist
foreach $element (sort keys %workload_ach) {
    print ",$element";
    push(@Quantums, $element) unless grep{$_ == $element} @Quantums;
    foreach $element1 (sort keys %{$workload_ach{$element}}) {
	$key_entry = $element1;
        push(@Designs, $element1) unless grep{$_ == $element1} @Designs;
	foreach $element2 (sort keys %{$workload_ach{$element}{$element1}}) {
	  print ",$element2";
	  $key_entry2 = $element2;
	  push(@Instances, $element2) unless grep{$_ == $element2} @Instances;
	  foreach $element3 (sort keys %{$workload_ach{$element}{$element1}{$element2}}) {
	    push(@Types, $element3) unless grep{$_ == $element3} @Types;
	  };
	};
    };
};
print "\n";

#foreach $type (sort @Types) {
#  print "Debug type $type\n";
#};
#foreach $design (sort @Designs) {
#  print "Debug design $design\n";
#};
#foreach $instance (sort @Instances) {
#  print "Debug instances $instance\n";
#};
$instance = 1;
$type = 0;

# iterate over all design variations
foreach $type (sort @Types) {
foreach $design (sort @Designs) {
	$myfile = "run_test.$design.$instance.$type.sum.csv";
	open (MYFILE, "> $myfile") || die "Couldn't open $myfile\n";
    print "# result for design $design with type $type\n";
    printf MYFILE "# result for design $design with type $type\n";
    print "date";
    printf MYFILE "date";
    foreach $quantum (sort @Quantums) {
        print ",$quantum";
     	printf MYFILE ",$quantum";
    };
    print "\n";
    printf MYFILE "\n";
    foreach $request (sort { $a <=> $b } keys %{ $workload_ach{$Quantums[0]}{$design}{$instance}{$type} }) {
        # print "Debug $request $design $instance $type\n";
        print "$request";
     	printf MYFILE "$request";
        foreach $quantum (sort keys %workload_ach) {
            if (exists $workload_ach{$quantum}{$design}{$instance}{$type}{$request}) {
                print ",$workload_ach{$quantum}{$design}{$instance}{$type}{$request}";
                printf MYFILE ",$workload_ach{$quantum}{$design}{$instance}{$type}{$request}";
            }
            else {
                print ",0";
                printf  MYFILE ",0";
            };
        };
        print "\n";
        printf MYFILE "\n";
    };
    close (MYFILE);
};
};