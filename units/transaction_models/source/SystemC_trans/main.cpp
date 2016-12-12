/*****************************************************************************

  main.cpp --

  Original Author: Rocco Jonack, Synopsys, Inc.

 *****************************************************************************/
#include <systemc.h>
#include "top.h"
//#include "boost/date_time/posix_time/posix_time.hpp"

int sc_main (int, char *[])
{
 // boost::posix_time::ptime  	sim_start_time, sim_end_time;
  top top1("top1");
  cout << "starting simulation\n";
  //sim_start_time = boost::posix_time::microsec_clock::universal_time();
  for (int i=0; i<10; ++i) {
    sc_start(0.1, SC_SEC);
    cout << "simulation reached timing point " << sc_time_stamp() << endl;
  };
  //sim_end_time = boost::posix_time::microsec_clock::universal_time();
  //cout << "stoping simulation at time " << sc_time_stamp() << " with a runtime of " << (sim_end_time-sim_start_time) << endl;
  return 0;
}

