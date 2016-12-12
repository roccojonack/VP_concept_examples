/*
 * test_master.cpp
 *
  */

#include <signal_master.h>

signal_master::signal_master(sc_module_name nm)
    : sc_module(nm)
    , bool_port_o("bool_port_0")
    , uint_port_o("uint_port_0")
    , counter(0)
{
     mBusClockPeriod = SC_ZERO_TIME;
     SC_METHOD(executeMethod);
}

signal_master::~signal_master()
{
}

// ***************** executeRequest **********************
void signal_master::executeMethod()
{
    //DBG_NOTE( dbgLevel, dbg.note() << "Executing method " << endl );
	bool_port_o.write(! bool_port_o.read());
	uint_port_o.write(uint_port_o.read()+1);
	counter++;
	next_trigger(mBusClockPeriod);
};

void signal_master::setBusClockPeriod(const sc_core::sc_time &period)
{
    mBusClockPeriod = period;
    std::cout << "Clock period: " << period << std::endl;
}

void signal_master::end_of_elaboration()
{
  //  end_of_elaboration();
}

void signal_master::end_of_simulation()
{
  std::cout << "Information : sent " << counter << " signal events " << std::endl;
  //  	end_of_simulation();
}
