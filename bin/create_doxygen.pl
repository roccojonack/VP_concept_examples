#!/usr/bin/perl
# ---------------------------------------------------------------------------------------------------
#
# usage: 
# example: 
#
# ---------------------------------------------------------------------------------------------------
use Template;
my $tt = Template->new({ABSOLUTE=>1,});

#$units = findUnits("Makefile");
#$name  = findName();
# print "got for unit $name the subunits $units\n";
my %data = (
	    NAME => "rocco",
	    UNITS => "bla"
	   );
my $filename = "$ENV{'WORKAREA'}/doc/templates/doxyConfig.template";
$tt->process($filename, \%data) || die $tt->error;

sub findUnits {
	my $filename = shift(@_);
	open (MYFILE, $filename) || die "Couldn't open $filename \n";
	LOOP: while (<MYFILE>) {
		chomp;
		if (/ADD_UNITS\s*=\s*(\S+)(.*)/) {
                        $units = "$1$2";
		};
	};
	return $units;
};
sub findName {
	my $dirname = `pwd`;
	my @splitdirname = split('/', $dirname);
	my $shortName = $splitdirname[-4];
	# print "Information: found @splitdirname ; $shortName ;\n";
	return $shortName;
};

