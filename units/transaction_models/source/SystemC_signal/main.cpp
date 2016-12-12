/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2006 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  main.cpp --

  Original Author: Rocco Jonack, Synopsys, Inc.

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

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

