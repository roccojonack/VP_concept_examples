#!/usr/bin/perl

# ---------------------------------------------------------------------------------------------------
#
# usage: reads the logs of simulation runs for Audio VP and writes out a historgram of transacion \
#        in time buckets as CSV formated file; there are individual colomns for read/write dbg and \
#        normal transafers and in which address backet the transactions fall (reg/host mem/HPRAM/LPRAM/ROM)
# example:
#
# ---------------------------------------------------------------------------------------------------
use Getopt::Long;
use File::Glob ':globally';
use File::Find;

@DIRLIST = ('.');

#default name for input file
my $FileName = "run_test.log";

GetOptions('FileName=s'  => \$FileName,
	   'OutputFileName=s'  => \$FileNameOut);
#default name for output file
my $FileNameOut = ${FileName}.".out";
my $FileNameRepeatOut = "repeat.out";

my $repeat_counter = 0;
my $bucket = 0;
my $AddrBucket = 0;
my $min_bucket = -1;
my $max_bucket = 0;
my $time_interval = 100000000; # 0.1 second
my %BTransfers;
my %DBGTransfers;
my %RepeatCounter;
my $DRAM_start  = 0x80000000;
my $HPRAM_start = 0xBE000000;
my $LPRAM_start = 0xBE800000;
my $ROM_start   = 0xBEFE0000;

push (@ListOfSources, $FileName);

# main processing loop for files
foreach $file (@ListOfSources) {
  # initialize values
  open (MYFILE, $file) || die "Couldn't open $file \n";
  LOOP:while(<MYFILE>) {
    chomp;
    s/^\s+//;
    @elements = split(/\s+/, $_);
    if (/^\[.+ info\]\s+.*b_transport.* got\s+COMMAND: (\d+) LENGTH: (\d+) ADDR: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) RSP_STATUS: ([0-9A-F]+) STREAMING_WIDTH: (\d+) DMI_ALLOWED: (\d+) BYTE_ENABLE_LENGTH: (\d+).* at time (\d+) (\w+)/) { 
      checkForFactor($13);
      $time = $12*$factor;
      checkForRepeat($1,$2,$3,$time);
      $AddrBucket = checkForAddress($3);
      $bucket = int($time / $time_interval);
      if ($min_bucket==-1) {
	$min_bucket = $bucket;
	# print "DEBUG: new min bucket $min_bucket\n";
      };
      if ($max_bucket<$bucket) {
	$max_bucket = $bucket;
	# print "DEBUG: new max bucket $max_bucket\n";
      };
      $prev_address = $3;
      $prev_length  = $2;
      $BTransfers{$bucket}{$1}{$AddrBucket}++;
      # print "Debug: found line to be parsed $1,$bucket,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$time,$14 $_\n";
      next LOOP;
    };
    if (/^\[.+ info\]\s+.*transport_dbg.* got\s+COMMAND: (\d+) LENGTH: (\d+) ADDR: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) Data\[\d\]: (0x[0-9A-F]+) RSP_STATUS: ([0-9A-F]+) STREAMING_WIDTH: (\d+) DMI_ALLOWED: (\d+) BYTE_ENABLE_LENGTH: (\d+).* at time (\d+) (\w+)/) { 
      checkForFactor($13);
      $time = $12*$factor;
      checkForRepeat($1,$2,$3,$time);
      $AddrBucket = checkForAddress($3);
      $bucket = int($time / $time_interval);
      if ($min_bucket==-1) {
	$min_bucket = $bucket;
	# print "DEBUG: new min bucket $min_bucket\n";
      };
      if ($max_bucket<$bucket) {
	$max_bucket = $bucket;
	# print "DEBUG: new max bucket $max_bucket\n";
      };
      $DBGTransfers{$bucket}{$1}{$AddrBucket}++;
      # print "Debug: found line to be parsed $1,$bucket,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$time,$14 $_\n";
      next LOOP;
    };
    if (/^\[.+ info\]\s+.* got\s+COMMAND: (\d+)/) { 
      print "ERROR: found unhandled line to be parsed : $_\n";
    };
  };
  close(MYFILE);
};

open (OUTFILE, " >$FileNameOut") || die "Couldn't open $FileNameOut \n";
print OUTFILE "# Title: Number of transactions in 0.1 s time buckets; seperated into target regions and transaction type\n";
print OUTFILE "# xTitle: virtual time in 0.1 sec steps\n";
print OUTFILE "# yTitle: number of transactions\n";
print OUTFILE "date,transport_dbg reg read,b_transport reg read,transport_dbg hostmem read,b_transport hostmem read,transport_dbg HPRAM read,b_transport HPRAM read,transport_dbg LPRAM read,b_transport LPRAM read,transport_dbg ROM read,b_transport ROM read,transport_dbg reg write,b_transport reg write,transport_dbg hostmem write,b_transport hostmem write,transport_dbg HPRAM write,b_transport HPRAM write,transport_dbg LPRAM write,b_transport LPRAM write,transport_dbg ROM write,b_transport ROM write\n";
for ($count=$min_bucket; $count<=$max_bucket; $count++) {
  for ($i=0; $i<2;$i++) {
    if ($i==0) {
      print OUTFILE "$count";
    };
    for ($j=1; $j<6;$j++) {
      if (exists($DBGTransfers{$count}{$i}{$j})) {
	print "found in bucket $count $DBGTransfers{$count}{$i}{$j} $j $i dbg transfers";
	print OUTFILE ",$DBGTransfers{$count}{$i}{$j}";
      }
      else {
	print "found in bucket $count 0 $j $i dbg transfers";
	print OUTFILE ",0";
      };
      if (exists($BTransfers{$count}{$i}{$j})) {
	print " and $BTransfers{$count}{$i}{$j} $j $i b transfers\n";
	print OUTFILE ",$BTransfers{$count}{$i}{$j}";
      }
      else {
	print " and 0 $j $i b transfers\n";
	print OUTFILE ",0";
      };
    };
    if ($i==1) {
      print OUTFILE "\n";
    };
  };
};
close(OUTFILE);

open (OUTFILE, " >$FileNameRepeatOut") || die "Couldn't open $FileNameRepeatOut \n";
print OUTFILE "# Title: Number of repeat transactions in 0.1 s time buckets\n";
print OUTFILE "# xTitle: virtual time in 0.1 sec steps\n";
print OUTFILE "# yTitle: number of transactions\n";
print OUTFILE "date,repeat transactions\n";
foreach $entry (sort keys %RepeatCounter) {
  print OUTFILE "$entry,$RepeatCounter{$entry}\n";
};
close(OUTFILE);

# testing if the transaction is the same as the previous one
sub checkForRepeat {
  my $command = shift(@_);
  my $length  = shift(@_);
  my $address = shift(@_);
  my $time    = shift(@_);
  if ($command==0) {
    if ($prev_length==$length) {
      if ($prev_address==$address) {
	$repeat_counter++;
      }
      else {
	if ($repeat_counter>10) {
	  print "Debug: found a repeat transaction with $repeat_counter repeats at time $time\n";
	  $RepeatCounter{$time}=$repeat_counter;
	};
	$repeat_counter=0;
      };
    }
    else {
      if ($repeat_counter>10) {
	print "Debug: found a repeat transaction with $repeat_counter repeats at time $time\n";
	$RepeatCounter{$time}=$repeat_counter;
      };
      $repeat_counter=0;
    };
  }
  else {
    if ($repeat_counter>10) {
      print "Debug: found a repeat transaction with $repeat_counter repeats at time $time\n";
      $RepeatCounter{$time}=$repeat_counter;
    };
    $repeat_counter=0;
  };
};

# sets the value of the time factor
sub checkForFactor {
  my $input = shift(@_);
  $factor = 0;
  if ($input eq "us") {
    $factor = 1000;
  };
  if ($input eq "ms") {
    $factor = 1000*1000;
  };
  if ($input eq "ns") {
    $factor = 1;
  };
  if($factor==0) {
    print "Error: no timing factor found for $13 \n";
  };
};

# returns a value which indicates the address target
sub checkForAddress {
  my $addr = shift(@_);
  if (hex($addr)<$DRAM_start) {
    return 1;
  };
  if (hex($addr)<$HPRAM_start) {
    return 2;
  };
  if (hex($addr)<$LPRAM_start) {
    return 3;
  };
  if (hex($addr)<$ROM_start) {
    return 4;
  };
  return 5;
}
