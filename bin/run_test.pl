#!/usr/bin/perl
# ToDo: needs to be generalized
# ---------------------------------------------------------------------------------------------------
#
# usage: run_test.pl -f <file> -n <number> file defines the file which list the jobs to be distributed;
# 			number defines the number of CPUs to be used (length of file / number is the number of jobs
# 			per CPU)
# example: run_test.pl -f task_list.txt -n 10 using the file task_list.txt line by as commands and
#			distribute over 10 CPUs
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;

my $FileName = "task_list.txt";
my $NumberOfJobs = 10;

GetOptions('FileName=s'     => \$FileName
           ,'NumberOfJobs=s' => \$NumberOfJobs);

my @Commands;
my $NumberOfCommands;
open (MYFILE, $FileName) || die "Couldn't open $FileName \n";

LOOP:while(<MYFILE>) {
    chomp;
    s/^\s+//;
    # print "Debug: $_\n";
    if (/^#/i) {
    	# print "Debug1: found comment\n";
      next LOOP;
    };
    # print "Debug:2 $_\n";
    push(@Commands, $_);
};
$NumberOfCommands = $#Commands+1;
$NumberOfSeqJobs =  int($NumberOfCommands/$NumberOfJobs);
print "found $NumberOfCommands commands to submit on $NumberOfJobs Jobs, that means $NumberOfSeqJobs commands per Job\n";
$counter = 0;
$FileNameCounter = 0;
foreach $command (@Commands) {
	if ($counter==0) {
		open (MYOUTFILE, "> _tmpCmdFile$FileNameCounter") || die "Couldn't open _tmpCmdFile$FileNameCounter \n"; # TODO: check if file already exists
		print MYOUTFILE "#! /bin/tcsh -f\n\n";
	}
	print MYOUTFILE "$command\n";
	
	$counter++;
	if ($counter>=$NumberOfSeqJobs) {
		$counter = 0;
		$submit_command = "nbjob run --qslot /imc/hw/generic --target imu_normal --mail E _tmpCmdFile$FileNameCounter\n";
		print "submitting $submit_command\n";
		chmod 0755, "_tmpCmdFile$FileNameCounter";
		system($submit_command);
		close MYOUTFILE;
		$FileNameCounter++;
	};
};
# handle left over commands
if (-e "_tmpCmdFile$FileNameCounter") {
	$submit_command = "nbjob run --qslot /imc/hw/generic --target imu_normal --mail E _tmpCmdFile$FileNameCounter\n";
	print "submitting left over $submit_command\n";
	chmod 0755, "_tmpCmdFile$FileNameCounter";
	system($submit_command);
};
