/*****************************************************************************

  main.cpp --

  Original Author: Rocco Jonack, Synopsys, Inc.

 *****************************************************************************/
#include <systemc.h>
#include "top.h"
//#include "boost/date_time/posix_time/posix_time.hpp"

int sc_main (int, char *[])
{
	top top1("top1");
 ifstream rd_in("my");
//	boost::posix_time::ptime  	sim_master_start_time, sim_master_end_time;
//	sim_master_start_time = boost::posix_time::microsec_clock::universal_time();
	cout << "starting simulation\n";
	for (int i=0; i<1; ++i) {
	  sc_start(1, SC_SEC);
	  cout << "simulation reached timing point" << endl;
	};
	cout << "stoping simulation at time " <<sc_time_stamp() << endl;
//	sim_master_end_time = boost::posix_time::microsec_clock::universal_time();
//	boost::posix_time::time_duration master_elapsed_time = sim_master_end_time
//    - sim_master_start_time;
//	std::cout << "Total execution time is "
//			  << boost::posix_time::to_simple_string(master_elapsed_time) << std::endl;
	return 0;
}

