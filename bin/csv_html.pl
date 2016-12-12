#! /p/inway_arch/tools/opensource/perl/5.8.8/bin/perl

use HTML::Entities;
 
sub row {
    my $elem = shift;
    my @cells = map {"<$elem>$_</$elem>"} split ',', shift;
    print '<tr>', @cells, "</tr>\n";
}
 
my ($first, @rest) = map
    {my $x = $_; chomp $x; encode_entities $x}
    <STDIN>;

print "<table>\n";
row @ARGV ? 'th' : 'td', $first;
row 'td style=\'color:#000; background:#8FF; border:1px #000 solid; padding:0.6em;\'', $_ foreach @rest;
print "</table>\n";
