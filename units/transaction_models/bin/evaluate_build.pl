#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads the logs of build process and the run of simulations and
#        writes out the results in CSV format for error and warnings
# example:
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
use File::Glob ':globally';
use File::Find;

@DIRLIST = ('.');
my $FileName;
GetOptions('FileName=s' => \$FileName);
my $NumberOfErrors=0;
my $NumberOfWarnings=0;
my @ListOfSources = ("run_build.log");

sub process_file {
  if (! -d) {
    # print "Debug: found : $File::Find::name \n";
    if ($File::Find::name =~ /run_test\.\d/) {
      push (@ListOfSources, $File::Find::name);
      # print "Debug: found log : $File::Find::name \n";
    };
    if ($File::Find::name =~ /run_mem\.\d/) {
      push (@ListOfSources, $File::Find::name);
      # print "Debug: found log : $File::Find::name \n";
    };
   if ($File::Find::name =~ /run_profile\.\d/) {
      push (@ListOfSources, $File::Find::name);
      # print "Debug: found log : $File::Find::name \n";
    };
  };
};
find(\&process_file, @DIRLIST);

print "File,NumberOfErrors,NumberOfWarnings\n";
foreach $file (@ListOfSources) {
	$NumberOfErrors=0;
	$NumberOfWarnings=0;
	open (MYFILE, $file) || die "Couldn't open $file\n";
	while(<MYFILE>) {
    	chomp;
    	s/^\s+//;
#    	print $_;
    	if (/error/i || /fatal/i ) {
      		$NumberOfErrors++;
    	};
   		if (/warn/i) {
      		$NumberOfWarnings++;
    	};
    };
  	close MYFILE;
  	print "$file,$NumberOfErrors,$NumberOfWarnings\n";
};


