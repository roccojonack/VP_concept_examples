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

my $FileName = "log";

GetOptions('FileName=s'  => \$FileName);

my $NumberOfEntries;
my @TimeBuffer = ();
my @RTFBuffer  = ();
my $time_base = 0;
my $min_time_base = 0;
my $max_time_base = 0;
my %profileEntry;
my %profileScale;
my %profileCounter;
my $insideProfile = 0;

open (MYFILE, $FileName) || die "Couldn't open $FileName  \n";
$NumberOfEntries = 0;
LOOP:while(<MYFILE>) {
  chomp;
  s/^\s+//;
  @elements = split(/\s+/, $_);
  if ($insideProfile==1) {
    if (/^\s*(\S+) \(\S+\) : \(\'(\d+\.\d+)/) {
      print "DEBUG: profile1 entry $1 $2 $time_base\n";
      $profileEntry{$1}{$time_base} = $2;
      $thread = $1;
    };
    if (/(\S+)\'\, (\d+)/) {
      print "DEBUG: profile2 entry $1 $2 $time_base $thread\n";
      if ($1 eq "s") {
	$profileEntry{$thread}{$time_base} *= (1000*1000)
      }
      else {
	if ($1 eq "ms") {
	$profileEntry{$thread}{$time_base} *= (1000);
	}
	else {	
	if ($1 ne "us") {
	  print "ERROR: unknown time scale $1 \n";
	};
      };
      };
      $profileScale{$thread}{$time_base} = $1;
      $profileCounter{$thread}{$time_base} = $2;
    };
  };
  if (/^Process profiler result.*:/) {
    $insideProfile = 1;
    print "DEBUG: profile start found\n";
  };
  if (length($_)==0 && $insideProfile==1) {
    $insideProfile = 0;
    print "DEBUG: profile end found\n";
  };
  if (/^cnl\.mb\.cpu0\.core\[0\]\[0\]\s+\d+\s+\d+\s+(\S+)/) {
    if ($time_base==0) {
      $min_time_base = 1000 * $1;
      # $min_time_base = $1;
    };
    # $time_base =  $1;
    $time_base = 1000 * $1; # time base in ms
    if ($time_base>=$max_time_base) {
      $max_time_base = $time_base;
    };
    print "Debug: found line $1 $time_base $max_time_base $min_time_base / $_\n"; 
  };
};

close(MYFILE);

open (OUTFILE, " >$FileName.out") || die "Couldn't open $FileName.out \n";
open (OUTFILE_DIFF, " >$FileName.diff.out") || die "Couldn't open $FileName.diff.out \n";
print OUTFILE "# printing the RTF and wall time values over time\n";
my $timeStep = 0;
my %prev_profileEntry;
print OUTFILE "date";
print OUTFILE_DIFF "date";
foreach $threadEntry (keys %profileEntry) {
    print OUTFILE ",$threadEntry";
    print OUTFILE_DIFF ",$threadEntry";
};
print OUTFILE "\n";
print OUTFILE_DIFF "\n";
# for ($timeStep=$min_time_base; $timeStep<=$max_time_base; $timeStep+=0.1) {
for ($timeStep=$min_time_base; $timeStep<=$max_time_base; $timeStep+=100) {
  print OUTFILE "$timeStep";
  print OUTFILE_DIFF "$timeStep";
  foreach $threadEntry (keys %profileEntry) {
    if (exists($profileEntry{$threadEntry}{$timeStep})) {
      if (exists($prev_profileEntry{$threadEntry})) {
	printf OUTFILE_DIFF ",%d", ($profileEntry{$threadEntry}{$timeStep}-$prev_profileEntry{$threadEntry});
      }
      else {
	print OUTFILE_DIFF ",$profileEntry{$threadEntry}{$timeStep}";
      };
      print OUTFILE ",$profileEntry{$threadEntry}{$timeStep}";
      $prev_profileEntry{$threadEntry} = $profileEntry{$threadEntry}{$timeStep};
    }
    else {
      print OUTFILE_DIFF ",0";
      if (exists($prev_profileEntry{$threadEntry})) {
	print OUTFILE ",$prev_profileEntry{$threadEntry}"
      }
      else {
	print OUTFILE ",0"
      };
    };
  };
  print OUTFILE "\n";
  print OUTFILE_DIFF "\n";
};
close(OUTFILE);


