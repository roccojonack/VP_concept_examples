#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: checks disk usage and prints ordered list
# example:
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
use File::Glob ':globally';
use File::Find;

my $NumberOfEntries = 10;
my $OutputFormat    = "MB";
GetOptions('NumberOfEntries=s'  => \$NumberOfEntries);

# main command to get the entries from OS
my @fullLog = `du -k --max 1`;

# main processing loop for files
foreach $line (@fullLog) {
  chomp $line;
  s/^\s+//;
  if ($line =~ /(\d+)\s+(\.\/.*)/) {
    # print "Debug: $1 $2\n";
    $Map{$1} = $2;
  }
  else {
    if ($line =~ /(\d+)\s+\.$/) {
      # print "Debug: total size $1\n";
      $summarySize = $1;
    }
    else {
      print "Warning: untreated line $line\n";
    };
  };
};

my $counter = 0;
LOOP: foreach $entry (reverse (sort { $a <=> $b } keys %Map) ) {
  if ($counter++ > $NumberOfEntries ) {
    next LOOP;
  };
  printf "Output: folder %30s has size %10d MB\n", $Map{$entry}, int($entry/1024);
};
print "Output: total size in folder is ".int($summarySize/1024)." MB\n";
