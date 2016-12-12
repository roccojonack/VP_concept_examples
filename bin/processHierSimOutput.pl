#!/p/inway_arch/tools/opensource/perl/5.8.8/bin/perl
# ---------------------------------------------------------------------------------------------------
#
# usage:  
# example: 
# purpose: read the output of the scanHierachy class the analyze structure of SystemC 
#          components in design
# ---------------------------------------------------------------------------------------------------
use Template;
use Getopt::Long;
use File::Copy;

my $tt = Template->new({ABSOLUTE=>1,});
my $InputFile   = "scanHierachy.txt";
my $outputFile  = "scanHierachy.dot";
my $outputType  = "DOT";
my $maxHierachy = 0;
GetOptions(  'InputFile=s'  => \$InputFile
	   , 'outputFile=s' => \$outputFile
	   , 'outputType=s' => \$outputType); 
 
# print "got for unit $name the subunits $units\n";
my %data = (
	    NAME         => $modulename,
	    WRAPPER_NAME => $toplevelname
	   );
my $basedir = $ENV{'WORKAREA'};
my %Hierachy;
my %Type;
my %SignalConnection;
my %TlmConnection;
my %Signal;
my %Input;
my %Output;
my %InitiatorPort;
my %TargetPort;
my @ParentModules;

# $tt->process($filename, \%data) || die $tt->error;
&processInput($InputFile);
if ($outputType eq "TB") {
  &generateHierachyOutput($outputFile);
};
if ($outputType eq "WRAPPER") {
  &generateWrapperOutput($outputFile);
};
if ($outputType eq "DOT") {
  &generateDOTOutput($outputFile);
};

sub processInput {
  my $filename = shift(@_);
  my $currentHierachy = 0;
  my $parentModule = "root";
  my $skipBeginning = 1;
  open (MYFILE, $filename) || die "Couldn't open $filename \n";
  LOOP: while (<MYFILE>) {
    chomp;
    if (/^constructing DUT/) {
      $skipBeginning = 0;
    };
    if (/^\s*\/\// || $skipBeginning==1) {
      next LOOP;
    };
    if (/\[sc_module(.*)\]\s*(\S+)/) {
      @tmp = split(/\./, $2);
      print "found module name $tmp[$#tmp] on hierachy $currentHierachy with parent $tmp[$#tmp-1] in file $filename \n";  
      $parentModule = $tmp[$#tmp-1];
      if ($currentHierachy==0) {
	push(@{$Hierachy{"__topmodule__"}{$currentHierachy}}, $tmp[$#tmp]);
      }
      else {
	push(@{$Hierachy{$parentModule}{$currentHierachy}}, $tmp[$#tmp]);
      };
      $currentModule = $tmp[$#tmp];
      next LOOP;
    };
    if (/\[sc_signal\]\s*(\S+)/) {
      @tmp = split(/\./, $1);
      print "found signal name $tmp[$#tmp] in file $filename \n";
      push((@{$Signal{$parentModule}{$currentHierachy}}), $tmp[$#tmp]);
      next LOOP;
    };
    if (/\[sc_in\]\s*(\S+)/) {
      @tmp = split(/\./, $1);
      $port = "$tmp[$#tmp-1]\-\>$tmp[$#tmp]";
      print "found signal name $port in file $filename \n";
      push((@{$InputPort{$parentModule}{$currentHierachy}}), $port);
      next LOOP;
    };
    if (/\[sc_out\]\s*(\S+)/) {
      @tmp = split(/\./, $1);
      $port = "$tmp[$#tmp-1]\-\>$tmp[$#tmp]";
      print "found signal name $port in file $filename \n";
      push((@{$Output{$parentModule}{$currentHierachy}}), $port);
      next LOOP;
    };
    if (/\[tlm_target_socket\]\s*(\S+)/) {
      @tmp = split(/\./, $1);
      print "found target socket $tmp[$#tmp] in file $filename \n";
      push((@{$TargetPort{$currentModule}{$currentHierachy}}), $tmp[$#tmp]);
      next LOOP;
    };
    if (/\[tlm_initiator_socket\]\s*(\S+)/) {
      @tmp = split(/\./, $1);
      print "found initiator socket $tmp[$#tmp] in file $filename \n";
      push((@{$Hierachy{initiator}{$currentHierachy}}), $tmp[$#tmp]);
      push((@{$InitiatorPort{$currentModule}{$currentHierachy}}), $tmp[$#tmp]);
      next LOOP;
    };
    if (/SignalPort binding:\s+(\S+)\/(\S+)/) {
      @tmp1 = split(/\./, $1);
      @tmp2 = split(/\./, $2);
      $init = "$tmp1[$#tmp1-1]\-\>$tmp1[$#tmp1]";
      $targ = "$tmp2[$#tmp2-1]\-\>$tmp2[$#tmp2]";
      print "found port binding between $init and $targ in __topmodule__ in file $filename \n";
      push(@{$SignalConnection{"__topmodule__"}}, "$init:$targ");
      next LOOP;
    };
    if (/TlmPort binding:\s+(\S+)\/(\S+)/) {
      @tmp1 = split(/\./, $1);
      @tmp2 = split(/\./, $2);
      $top_mod = $tmp1[$#tmp1-2];
      $init = "$tmp1[$#tmp1-1]\-\>$tmp1[$#tmp1]";
      $targ = "$tmp2[$#tmp2-1]\-\>$tmp2[$#tmp2]";
      print "found port binding between $init and $targ in $top_mod in file $filename \n";
      push(@{$TlmConnection{$tmp1[$#tmp1-1]}{1}}, $tmp2[$#tmp2-1]);
      next LOOP;
    };
    if (/Type definition:\s+(\S+)\s+is\s+(\S+)/) {
      print "found type defintion between $1 and $2 in file $filename \n";
      $Type{$1} = $2;
      next LOOP;
    };
    if (/Type of Signal definition:\s+(\S+)\s+is\s+(\S+)/) {
      @tmp = split(/\./, $1);
      print "found signal type defintion between $tmp[$#tmp] and $2 in file $filename \n";
      $SignalType{$tmp[$#tmp]} = $2;
      next LOOP;
    };
    if (/\(/) {
      $currentHierachy++;$maxHierachy++;
      # push(@ParentModules, $parentModule);
      # $parentModule = $currentModule;
      print "found hierachy open $currentHierachy in file $filename \n";
      next LOOP;
    };
    if (/\)/) {
      $currentHierachy--;
      # $parentModule = pop(@ParentModules);
      print "found hierachy close $currentHierachy in file $filename \n";
      next LOOP;
    };
 
  };
  close(MYFILE);
  print "Bye from the input processing $filename!\n"
};

sub generateHierachyOutput  {
  my $outputFile = shift(@_);
  my $currentHierachy = 0;
  open (MYFILE, "> $outputFile") || die "Couldn't open $outputFile \n";
  # assuming for this function just one instantiation of module from top level to next level hierachy
  # for ($currentHierachy=0; $currentHierachy<$maxHierachy; $currentHierachy++) {
  my $topmodule = $Hierachy{"__topmodule__"}[0];
  print MYFILE "#include \"tlm_base.h\"\n";
  foreach $type (keys %Type) {
    @tmp = split(/</, $Type{$type});
    print MYFILE "#include \"$tmp[0].h\"\n";
  };
  print MYFILE "class $topmodule : public TLM_BASE::vpCommon\n";
  print MYFILE "{\n";
  print MYFILE "\tSC_HAS_PROCESS($topmodule);\n";
  print MYFILE "\t$topmodule(sc_module_name name)\n";
  print MYFILE "\t: vpCommon (name)\n";
  print MYFILE "\t{\n";
  foreach $module (@{$Hierachy{$topmodule}}) {
    print MYFILE "\t\t$module = new $Type{$module}(\"$module\");\n";
  };
  foreach $init (@{$TlmConnection{"__topmodule__"}}) {
    @tmp = split(/:/, $init);
     print MYFILE "\t\t$tmp[0].bind($tmp[1]);\n";
  };
  foreach $init (@{$SignalConnection{"__topmodule__"}}) {
    @tmp = split(/:/, $init);
    @tmp1 = split(/->/, $tmp[1]);
    print MYFILE "\t\t$tmp[0]($tmp1[1]);\n";
  };
  print MYFILE "\t};\n";
  print MYFILE "\t~$topmodule()\n";
  print MYFILE "\t{\n";
  print MYFILE "\t};\n";
  foreach $module (@{$Hierachy{$topmodule}}) {
    print MYFILE "\t$Type{$module}*\t$module;\n";
  };
  foreach $module (@{$Signal{$topmodule}}) {
    print MYFILE "\tsc_signal<$SignalType{$module} >\t$module;\n";
  };
  print MYFILE "};\n";
  # };
  print "Bye!\n"
};

# generating Simics wrapper based of connectivity definition
sub generateWrapperOutput  {
  my $outputFile = shift(@_);
  my $currentHierachy = 0;
  open (MYFILE, "> $outputFile") || die "Couldn't open $outputFile \n";
# assuming for this function just one instantiation of module from top level to next level hierachy
  my $topmodule = $Hierachy{module}{0}[0];
  print MYFILE "#include \"tlm_base.h\"\n";
  foreach $type (keys %Type) {
    @tmp = split(/</, $Type{$type});
    print MYFILE "#include \"$tmp[0].h\"\n";
  };
  print MYFILE "class Adapter : public scl::Adapter\n";
  print MYFILE "{\n";
  print MYFILE "\tpublic:\n";
  print MYFILE "\texplicit Adapter(simics::SimicsObjectRef o) : scl::Adapter(o)\n";
# looping
  foreach $initPort (@{$InitiatorPort{$topmodule}}) {
    print MYFILE "\t\t, MemoryPageUpdateGasketAdapter_$initPort(&systemc_memory_page_update_$initPort)\n";
  };
  print MYFILE "\t\t, DEV(this, \"DEV\")\n";
  print MYFILE "\t{\n";
# looping
  foreach $initPort (@{$InitiatorPort{$topmodule}}) {
    print MYFILE "\t\tsimics_memory_space_$initPort->set_gasket(scl::tlm2simics::createGasket(\n";
    print MYFILE "\t\t&DEV->$initPort, o));\n";
    print MYFILE "\t\tsystemc_memory_page_update_$initPort.set_gasket(simics_memory_space_$initPort->gasket());\n";
  };
  print MYFILE "\t\t};\n";
  print MYFILE "\t\tscl::Connector<scl::tlm2simics::MemorySpace> simics_memory_space_0;\n";
  print MYFILE "\tprivate:\n";
  foreach $initPort (@{$InitiatorPort{$topmodule}}) {
  print MYFILE "\t\tscl::simics2tlm::MemoryPageUpdate         systemc_memory_page_update_$initPort;\n";
  print MYFILE "\t\tscl::simics2tlm::MemoryPageUpdateGasketAdapter MemoryPageUpdateGasketAdapter$initPort;\n";
  };
  print MYFILE "\t\tscl::Device<$topmodule<32, 1> > DEV;\n";
  print MYFILE "\t};\n";
  print MYFILE "\textern \"C\" void init_local(void) {\n";
  print MYFILE "\t\tstatic scl::iface::MemoryPageUpdateSimicsAdapter<Adapter>\n";
  print MYFILE "\t\tmemory_page_simics_adapter;\n";
  print MYFILE "\tsimics::ClassDef<Adapter> def(\n";
  print MYFILE "\t\tDEVICE_CLASS, \"Sample SystemC TLM2 Device\",\n";
  print MYFILE "\t\t\"The <class>\" DEVICE_CLASS \"</class> is a Simics module\"\n";
  print MYFILE "\t\t\" encapsulating a SystemC TLM2-based device to demonstrate\"\n";
  print MYFILE "\t\t\" the use of the Simics SystemC Library.\");\n";
  print MYFILE "\tdef\n";
  foreach $initPort (@{$InitiatorPort{$topmodule}}) {
    print MYFILE "\t\t<< scl::ConnectorAttribute<Adapter>(\n";
    print MYFILE "\t\t\"phys_mem$initPort\",\n";
    print MYFILE "\t\t\"Physical memory, for outgoing transactions.\",\n";
    print MYFILE "\t\t&Adapter::simics_memory_space_$initPort)\n";
  };
  print MYFILE "\t\t<< memory_page_simics_adapter;\n";
  print MYFILE "\t\tscl::Adapter::initClass(&def);\n";
  print MYFILE "\t\tscl::awareness::isctlm::initClass();\n";
  print MYFILE "\t}\n";
  print "Bye!\n"
};

# generating dot output
sub generateDOTOutput  {
  my $outputFile = shift(@_);
  my $currentHierachy = 0;
  my $topmodule = $Hierachy{"__topmodule__"}{0}[0];
  open (MYFILE, "> $outputFile") || die "Couldn't open $outputFile \n";
  print MYFILE "digraph {\n";
  print "top module is $topmodule\n";
  foreach $module (@{$Hierachy{$topmodule}{1}}) {
    print "list for module $module\n";
    print MYFILE "\t$module [shape=box];\n";
    foreach $tlm_connection (@{$TlmConnection{$module}{1}}) {
      print MYFILE "\t$module -> $tlm_connection [style=bold,label=\"TLM2\"];\n";
    };
  };
  print MYFILE "}\n";
  print "Bye from dot output!\n"
};
