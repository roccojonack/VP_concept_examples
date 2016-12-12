#!/p/inway_arch/tools/opensource/perl/5.8.8/bin/perl
# ---------------------------------------------------------------------------------------------------
#
# usage: 
# example: 
# purpose: the scripts reads a ISCTLM generated VCD file which doesn't contain any hierarchy
#          and converts the variable definitions into a scoped version, which shows up
#          in a waveform viewer as hierarchy
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
my $InFileName   = "trace_file.vcd";
my $OutFileName  = $InFileName.".out.vcd";
my $curentScope = 0;
GetOptions( 'InFileName=s'  => \$InFileName
	   ,'OutFileName=s' => \$OutFileName); 

open (MYINFILE,  $InFileName) || die "Couldn't open $InFileName\n";
open (MYOUTFILE, "> $OutFileName") || die "Couldn't open $OutFileName\n";
while(<MYINFILE>) {
  chomp;
  s/^\s+//;
  @elements = split(/\s+/, $_);
  # leave existing scope unmodified
  if (/^\$scope module (\S+) \$end/) {
    $name{$currentScope} = $1;
    $currentScope++;
    print ("Debug: 1 $currentScope ".$_."\n");
    printf MYOUTFILE $_."\n";
    next;
  };
  # for any variables check what the scope is by looking as the variables 
  if (/^\$var wire\s+(\d+)\s+(\S+)\s+(\S+)\s+(\S*)\s+\$end/) {
    $signalWidth    = $1;
    $signalShortcut = $2;
    $signalName     = $3;
    $signalWidthExt = $4;
    @NameElements = split(/\./, $signalName);
    $scope = $#NameElements;
    print ("Debug: 5 $signalWidth $signalShortcut $signalName $signalWidthExt $scope $currentScope $NameElements[1]\n");
    # looks like we are going down in scope
    if ($scope>$currentScope) {
      for ($i=$currentScope; $i<$scope; ++$i) {
	print ("Debug: 2 \$scope module $NameElements[$i] \$end\n");
	printf MYOUTFILE "\$scope module $NameElements[$i] \$end\n";
      };
    }
    else {
      # looks like we are going up in scope
      if ($scope<$currentScope) {
	for ($i=$currentScope; $i>$scope; --$i) {
	  print ("Debug: 3 \$upscope \$end\n"); 
	  printf MYOUTFILE "\$upscope \$end\n";
	};
      }
      else {
	# check if the hierachy remains the same
	for ($i=0; $i<$scope; ++$i) {
	  if ($CurrentHierachy[$i] ne $NameElements[$i]) {
	    print ("Debug: 7 difference in hierarchy $CurrentHierachy[$i] /= $NameElements[$i]\n");
	    printf MYOUTFILE "\$upscope \$end\n";
	    printf MYOUTFILE "\$scope module $NameElements[$i] \$end\n";
	  };
	};
      };
    };
    $currentScope = $scope;
    print ("Debug: 4 \$var wire $signalWidth $signalShortcut $NameElements[$scope] $signalWidthExt \$end\n");
    printf MYOUTFILE "\$var wire $signalWidth $signalShortcut $NameElements[$scope] $signalWidthExt \$end\n";
    for ($i=0; $i<$scope; ++$i) {
      $CurrentHierachy[$i] = $NameElements[$i];
    };
    next;
  };
  # correct the remaining outstanding scopes before leaving the section 
  if (/^\$enddefinitions\s+\$end/) {
      for ($i=$currentScope; $i>1; --$i) {
	print ("Debug: 6 \$upscope \$end\n"); 
	printf MYOUTFILE "\$upscope \$end\n";
      };
  };
  printf MYOUTFILE $_."\n";
};
