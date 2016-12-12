#! /usr/bin/csh -f

# main entry point for automated test runs on top level 
# enter all tests that should be run automatically in 
# subdirectory $REGRESSION; everything will be checked
# out clean in $REGRESSION and run from scratch
# result notification to anybody $MAILRECEIVER 
set REGRESSION   = regression
set MAILRECEIVER = rocco.jonack@gmail.com

\rm -rf $REGRESSION
cd $WORKAREA
mkdir $REGRESSION
setenv WORKAREA `pwd`/$REGRESSION
cd $WORKAREA

git init
git remote add examples https://github.com/roccojonack/supportLibs.git
git pull examples master

foreach UNIT (tb_mod xtensa_dsp)
    cd $WORKAREA/units/$UNIT/bin
    ./run_build.csh 2>& run_build.log
    echo "Hi Rocco, build for $UNIT is done" | mutt -s "build notification for $UNIT" $MAILRECEIVER
end
foreach TEST (1 2 3)
    cd $WORKAREA/units/tb_mod/bin
    ./run_test.csh -t $TEST 2>& run_test.$TEST.log
    echo "Hi Rocco, run for tb_mod test $TEST is done" | mutt -s "run notification for tb_mod $TEST" $MAILRECEIVER
end
foreach UNIT (xtensa_dsp)
    cd $WORKAREA/units/$UNIT/bin
    ./run_test.csh 2>& run_test.log
    echo "Hi Rocco, run for $UNIT is done" | mutt -s "run notification for $UNIT" $MAILRECEIVER
end
cd $WORKAREA


# evaluate results of the different runs    
cd $WORKAREA/bin
mkdir -p $WORKAREA/doc/result
foreach TEST (1 2 3)
    cd $WORKAREA/units/tb_mod/bin
    mkdir -p ../doc/result
    ./evaluate_result.pl -f run_test.$TEST.log > ../doc/result/run_test.$TEST.csv
    $WORKAREA/bin/csv_html.pl < ../doc/result/run_test.$TEST.csv > ../doc/result/run_test.$TEST.html
end
foreach UNIT (xtensa_dsp)
    cd $WORKAREA/units/$UNIT/bin
    mkdir -p ../doc/result
    ./evaluate_result.pl -f run_test.log > ../doc/result/run_test.csv
    $WORKAREA/bin/csv_html.pl < ../doc/result/run_test.csv > ../doc/result/run_test.html
end
cd $WORKAREA




