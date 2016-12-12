/*
 * test_master.cpp
 *
  */

#include <signal_slave.h>

signal_slave::signal_slave(sc_module_name nm)
    : sc_module(nm)
    , bool_port_i("bool_port_i")
	, uint_port_i("uint_port_i")

{
     mBusClockPeriod = SC_ZERO_TIME;
     SC_METHOD(executeMethod);
     sensitive << bool_port_i << uint_port_i;
}

signal_slave::~signal_slave()
{
}

// ***************** executeRequest **********************
void signal_slave::executeMethod()
{
    //DBG_NOTE( dbgLevel, dbg.note() << "Executing method " << endl );
	bool_port_i.read();
	uint_port_i.read();
};

/*
void test_master::setReset(bool reset)
{
    if (reset)
    {
        getDefaultResetDomain().resetStart();
    }
    else
    {
        getDefaultResetDomain().resetEnd();
    }
}
*/
void signal_slave::setBusClockPeriod(const sc_core::sc_time &period)
{
    mBusClockPeriod = period;
    //DBG_NOTE( dbgLevel, dbg.note() << "Clock period: " << period << endl );
}


void signal_slave::end_of_elaboration()
{
    //vpCommon::end_of_elaboration();
}
