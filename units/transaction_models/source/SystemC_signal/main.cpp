#include <systemc.h>
#include "top.h"
#include "boost/date_time/posix_time/posix_time.hpp"

int sc_main (int argc, char *argv[])
{
	int NumberOfMS = 1;
	if (argc>1)
		NumberOfMS = atoi(argv[1]);
  	top top1("top1");
  	boost::posix_time::ptime  	sim_master_start_time, sim_master_end_time;
  	sim_master_start_time = boost::posix_time::microsec_clock::universal_time();
  	cout << "starting simulation\n";
  	sc_start(NumberOfMS, SC_MS);
  	cout << "stoping simulation at time " <<sc_time_stamp() << endl;
  	sc_stop();
  	sim_master_end_time = boost::posix_time::microsec_clock::universal_time();
  	boost::posix_time::time_duration master_elapsed_time = sim_master_end_time
  			- sim_master_start_time;
  	std::cout << "Total execution time is "
  			<< boost::posix_time::to_simple_string(master_elapsed_time) << std::endl;
  return 0;
}

