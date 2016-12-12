#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads the output of RTF values from different simulations and creates one CSV file for all RTF results
# example:
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
use File::Glob ':globally';
use File::Find;

@DIRLIST = ('.');

my $FileNameRTFOut = "RTF.csv";
my $FileNameWallTimeOut = "WT.csv";

GetOptions('FileName=s'  => \$FileName);

my $TestName;
my @ListOfSources = ();
my %RTF;
my %WallTime;
my $validLog;

use File::Find;
sub process_file {
  if (! -d) {
    # print "Debug: found : $File::Find::name \n";
    if ($File::Find::name =~ /log\.out/) {
      push (@ListOfSources, $File::Find::name);
      # print "Debug: found log : $File::Find::name \n";
    };
  };
};
find(\&process_file, '.');

FILE_LOOP: foreach $file (@ListOfSources) {
  # initialize values
  print "handle file $file \n";
  
  open (MYFILE, $file) || die "Couldn't open $file \n";
  $validLog = 0;
  @elements = split(/\//, $file);
  foreach $parts (@elements) {
    # print "Debug: split the path to $parts\n";
    if (($parts=~/stub/ || $parts=~/full/ || $parts=~/reference/) && 
	($parts !~ "\.log\.out")) {
      $TestName = $parts;
      # print "Debug: found test name $TestName\n";
      $validLog = 1;
    };
  };

  if ($validLog==0) {
      print "Debug: log is not valid $file\n";
      next FILE_LOOP;
  };
  LOOP:while(<MYFILE>) {
    chomp;
    s/^\s+//;
    @elements = split(/,/, $_);
    if (/^#/) {
      # print "Debug: found comment line $_\n";
      next LOOP;
    };
    if (/^date/) {
      # print "Debug: found legend line $_\n";
      next LOOP;
    };
    # print "Debug: found line to be parsed $elements[0],$elements[1] $_\n";
    $RTF{$TestName}{$elements[0]} = $elements[1];
    $WallTime{$TestName}{$elements[0]} = $elements[2];
  };
  close(MYFILE);
};

foreach $testcase (sort keys %RTF) {
    print "Debug: adding test $testcase to legend\n";
    push(@Legend, $testcase);
}

# write out the RTF result
open (OUTFILE, " >$FileNameRTFOut") || die "Couldn't open $FileNameRTFOut \n";
foreach $line (@Comments) {
    print "Debug: comment is $line \n";
    print OUTFILE "$line\n";
}
print OUTFILE "# Title: RTF measured over virtual time\n";
print OUTFILE "# xTitle: virtual time in 0.1 sec\n";
print OUTFILE "# yTitle: RTF (wall time/virtual time)\n";
print OUTFILE "date";
foreach $line (@Legend) {
    print "Debug: legend is $line \n";
    print OUTFILE ",$line";
}
print OUTFILE "\n";
$counter = 0;
foreach $time (sort { $a <=> $b } keys %{$RTF{'reference'}}) {
    # print "Debug: time is $time\n";
    print OUTFILE "$time";
    foreach $testcase (sort keys %RTF) {
       # print ", $RTF{$testcase}{$time}";
       print OUTFILE ",$RTF{$testcase}{$time}";
    };
    # print "\n";
    print OUTFILE "\n";
};
close(OUTFILE);

# write out the wall time result
open (OUTFILE, " >$FileNameWallTimeOut") || die "Couldn't open $FileNameWallTimeOut \n";
foreach $line (@Comments) {
    print "Debug: comment is $line \n";
    print OUTFILE "$line\n";
}
print OUTFILE "# Title: Wall time measured Rover virtual time\n";
print OUTFILE "# xTitle: virtual time in 0.1 sec\n";
print OUTFILE "# yTitle: Wall time in ns\n";
print OUTFILE "date";
foreach $line (@Legend) {
    print "Debug: legend is $line \n";
    print OUTFILE ",$line";
}
print OUTFILE "\n";
$counter = 0;
foreach $time (sort { $a <=> $b } keys %{$RTF{'reference'}}) {
    # print "Debug: time is $time\n";
    print OUTFILE "$time";
    foreach $testcase (sort keys %RTF) {
       # print ", $RTF{$testcase}{$time}";
       print OUTFILE ",$WallTime{$testcase}{$time}";
    };
    # print "\n";
    print OUTFILE "\n";
};
close(OUTFILE);
