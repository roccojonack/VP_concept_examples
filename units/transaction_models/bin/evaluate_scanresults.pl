#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads the logs of build process and the run of dot file 
#        generation
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
    if ($File::Find::name =~ /run_scan\.\d/) {
      push (@ListOfSources, $File::Find::name);
      # print "Debug: found log : $File::Find::name \n";
    };
  };
};
find(\&process_file, @DIRLIST);

foreach $file (@ListOfSources) {
	$command = "\$WORKAREA/bin/processHierSimOutput.pl -i ${file} -outputFile ${file}.dot";
	print "executing $command\n";
	system ($command);
	$command = "/home/demo/tools/graphviz/bin/dot -Tsvg ${file}.dot > ${file}.html";
	print "executing $command\n";
	system ($command);
};


