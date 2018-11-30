/*****************************************************************************

  main.cpp --

  Original Author: Rocco Jonack, Synopsys, Inc.

 *****************************************************************************/
#include <systemc.h>
#include <scv.h>
#include "top.h"
//#include "boost/date_time/posix_time/posix_time.hpp"

int sc_main (int, char *[])
{
  scv_startup();

  scv_tr_text_init();
  scv_tr_db db("my_db.txlog");
  scv_tr_db::set_default_db(&db); 
  // boost::posix_time::ptime  	sim_start_time, sim_end_time;
  top top1("top1");
  cout << "starting simulation\n";
  //sim_start_time = boost::posix_time::microsec_clock::universal_time();
  for (int i=0; i<1; ++i) {
    sc_start(0.00001, SC_SEC);
    cout << "simulation reached timing point " << sc_time_stamp() << endl;
  };
  //sim_end_time = boost::posix_time::microsec_clock::universal_time();
  //cout << "stoping simulation at time " << sc_time_stamp() << " with a runtime of " << (sim_end_time-sim_start_time) << endl;
  return 0;
}

