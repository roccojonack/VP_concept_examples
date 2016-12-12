#!/usr/bin/perl
###############################################################################################
#
# Description: analysis of a database for some consistency and generate some stats about files
# Author     : rocco.jonack@gmail.com
#
# ToDo: add support to analyze also statistics on scripts/Makefile etc
###############################################################################################
## override the core glob (CORE::glob() does this automatically
## by default anyway, since v5.6.0)
use File::Glob ':globally';
use File::Find;
use Getopt::Long;

@DIRLIST = ('.');
my @ListOfSources;
my @ListOfMakefile;
my @ListOfDoxygen;
my @ListOfXML;
my @ListOfReadme;
my @ListOfIgnore;
my @ListOfPython;
my @ListOfPerl;
my @ListOfShell;
my @ListOfAllFiles;
%NrOfLines;
%NrOfCommentLines;
%NrOfPragmaLines;
%NrOfEmptyLines;
%NrOfRegisters;
%NrOfFields;
%NrOfCommonLines;
my $OutputFileName = "statistics.csv";
my $FileType   = "source";
my $AnalyzeDML2SystemC = "0";
GetOptions('FileType=s'           => \$FileType,
           'AnalyzeDML2SystemC=s' => \$AnalyzeDML2SystemC);

sub process_file {
  if (! -d) {	
    print "found : $File::Find::name \n";
    if ($File::Find::name =~ /\.cpp$/ || $File::Find::name =~ /\.cc$/ || $File::Find::name =~ /\.h$/) {
      push (@ListOfSources, $File::Find::name);
      print "found source : $File::Find::name \n";
    };
    if ($File::Find::name =~ /\-dml\.cc$/ || $File::Find::name =~ /\-dml\.h$/) {
      push (@ListOfDMLSCSources, $File::Find::name);
      print "found DML SystemC output source : $File::Find::name \n";
    };
    if ($File::Find::name =~ /GNUmakefile/ || $File::Find::name =~ /Makefile/) {
      push (@ListOfMakefile, $File::Find::name);
      print "found Makefile : $File::Find::name \n";
    };
    if ($File::Find::name =~ /doxyConfig/ ) {
      push (@ListOfDoxygen, $File::Find::name);
      print "found Doxygen : $File::Find::name \n";
    };
    if ($File::Find::name =~ /\.xml$/ || $File::Find::name =~ /.rdl$/ ) {
      push (@ListOfXML, $File::Find::name);
      print "found XML : $File::Find::name \n";
    } ;
    if ($File::Find::name =~ /README/ ) {
      push (@ListOfReadme, $File::Find::name);
      print "found readme : $File::Find::name \n";
    };
    if ($File::Find::name =~ /\.gitignore/ || $File::Find::name =~ /\.launch/ ) {
      push (@ListOfIgnore, $File::Find::name);
      print "found Ignore : $File::Find::name \n";
    }; 
    if ($File::Find::name =~ /\.py$/ ) {
      push (@ListOfPython, $File::Find::name);
      print "found Python script : $File::Find::name \n";
    }; 
    if ($File::Find::name =~ /\.pl$/ ) {
      push (@ListOfPerl, $File::Find::name);
      print "found Perl script : $File::Find::name \n";
    }; 
    if ($File::Find::name =~ /\.csh$/  || $File::Find::name =~ /\.sh$/ || 
        $File::Find::name =~ /\.tcsh$/ || $File::Find::name =~ /\.bash$/ ) {
      push (@ListOfShell, $File::Find::name);
      print "found Shell script : $File::Find::name \n";
    }; 
    push (@ListOfAllFiles, $File::Find::name);
  };
};
find(\&process_file, @DIRLIST);

if ($FileType == "source") {
  if ($AnalyzeDML2SystemC ne "0") {
    foreach $file (@ListOfDMLSCSources) {
      print "Information: found file $file \n";
      RecordStats($file);
      CountRegistersDML($file);
    };
  }
  else {
    foreach $file (@ListOfSources) {
      print "Information: found file $file \n";
      checkForDebugSetting($file);
      checkForAbsolutPath($file);
      RecordStats($file);
    };
  };
}
else {
  print "Warning: file types other then source are not yet supported\n";
};

printSummary();

###############################################################################################
#
# subroutines below
#
###############################################################################################
# print the summary
sub printSummary {
open (MYOUTFILE, "> $OutputFileName") || die "Couldn't open $OutputFileName\n";
print MYOUTFILE "file,NrOfLines,NrOfCommentLines,NrOfPragmaLines,NrOfEmptyLines";
if ($AnalyzeDML2SystemC ne "0") {
  print MYOUTFILE ",NrOfRegisters,NrOfFields,NrOfCommonCodeLines";
};
print MYOUTFILE "\n";
my $sumNrOfLines        = 0;
my $sumNrOfCommentLines = 0;
my $sumNrOfPragmaLines  = 0;
my $sumNrOfEmptyLines   = 0;
foreach $tmp (sort keys %NrOfLines) {
  print MYOUTFILE "$tmp";
  print "Statistics: lines in $tmp is $NrOfLines{$tmp} \n";
  print MYOUTFILE ",$NrOfLines{$tmp}";
  $sumNrOfLines+=$NrOfLines{$tmp};
  print "Statistics: comments in $tmp is $NrOfCommentLines{$tmp} \n";
  print MYOUTFILE ",$NrOfCommentLines{$tmp}";
  $sumNrOfCommentLines=$NrOfCommentLines{$tmp};
  print "Statistics: pragma in $tmp is $NrOfPragmaLines{$tmp} \n";
  print MYOUTFILE ",$NrOfPragmaLines{$tmp}";
  $sumNrOfPragmaLines+=$NrOfPragmaLines{$tmp};
  print "Statistics: empty lines in $tmp is $NrOfEmptyLines{$tmp} \n";
  print MYOUTFILE ",$NrOfEmptyLines{$tmp}";
  $sumNrOfEmptyLines+=$NrOfEmptyLines{$tmp};
  if ($AnalyzeDML2SystemC ne "0") {
    print "Statistics: registers in $tmp is $NrOfRegisters{$tmp} \n";
    print MYOUTFILE ",$NrOfRegisters{$tmp}";
    print "Statistics: fields in $tmp is $NrOfFields{$tmp} \n";
    print MYOUTFILE ",$NrOfFields{$tmp}";
    print "Statistics: common code in $tmp is $NrOfCommonLines{$tmp} \n";
    print MYOUTFILE ",$NrOfCommonLines{$tmp}";
  };
  print MYOUTFILE "\n";
};
# print MYOUTFILE "Total,$sumNrOfLines,$sumNrOfCommentLines,$sumNrOfPragmaLines,$sumNrOfEmptyLines\n";
close (MYOUTFILE);
};
sub checkForDebugSetting {
  my $filename = shift(@_);
  open (MYFILE, $filename) || die "Couldn't open $filename \n";
  LOOP: while (<MYFILE>) {
    chomp;
    if (/^\s*\/\//) {
      next LOOP;
    };
    if (/\s+cout/) {
      print "Warning: found access to cout in file $filename: $_ \n";
    };
    if (/#ifdef/) {
      print "Warning: found access an ifdef in file $filename: $_ \n";
    };
    if (/#define/) {
      print "Warning: found access a define in file $filename: $_ \n";
    };
  };
};

sub RecordStats {
  my $filename = shift(@_);
  open (MYFILE, $filename) || die "Couldn't open $filename \n";
  my $NrOfLines = 0;	
  my $NrOfCommentLines = 0;	
  my $NrOfPragmaLines = 0;	
  my $NrOfEmptyLines = 0;	
  my $inside_comment = 0;
  my $NrOfCommon = 0;
 LOOP: while (<MYFILE>) {
    chomp;
    $NrOfLines++;
    if ($inside_comment==1) {
      $NrOfCommentLines++;
      if (/\*\//) {
	$inside_comment=0;
      };
      next LOOP;
    };	
    if (/^\s*\/\*/) {
      $NrOfCommentLines++;
      $inside_comment=1;
      if (/\*\//) {
	$inside_comment=0;
      };
      next LOOP;
    };	
    if (/^\s*\/\//) {
      $NrOfCommentLines++;	
      next LOOP;
    };
    if (/^\s*#/) {
      $NrOfPragmaLines++;	
      next LOOP;
    };
    if (/^\s*$/) {
      $NrOfEmptyLines++;	
      next LOOP;
    };
    if ($AnalyzeDML2SystemC ne "0") {
      if (/^}\s+ \/\/\s+namespace dml/) {
	# reset counters since end of common code line
	$NrOfCommon = $NrOfLines;
	$NrOfLines = 0;	
	$NrOfCommentLines = 0;	
	$NrOfPragmaLines = 0;	
	$NrOfEmptyLines = 0;	
      };
    };
  };
  close (MYFILE);
  $NrOfLines{$filename}        = $NrOfLines;
  $NrOfCommentLines{$filename} = $NrOfCommentLines;
  $NrOfPragmaLines{$filename}  = $NrOfPragmaLines;
  $NrOfEmptyLines{$filename}   = $NrOfEmptyLines;
  $NrOfCommonLines{$filename}  = $NrOfCommon;
  print "Information: found in file $filename: $NrOfLines lines of code and $NrOfCommentLines lines of comment and $NrOfEmptyLines empty lines\n";
};

sub checkForAbsolutPath {
  my $filename = shift(@_);
  open (MYFILE, $filename) || die "Couldn't open $filename \n";
  while (<MYFILE>) {
    chomp;
    if (/[A-Z]:vp-/) {
      print "Warning: found absolut path setting in file $filename: $_ \n";
    };
    if (/\/[a-zA-Z0-9]\//) {
      print "Warning: found absolut path setting in file $filename: $_ \n";
    };
    if (/\$\((\w+)\)/) {
      print "Warning: found setting for variable $1 in file $filename: $_ \n";
    };
  };
};
