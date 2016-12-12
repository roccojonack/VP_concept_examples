#pragma once
#include <iostream>
#include <systemc.h>
#include <tlm.h>
#include <constants.h>
#include "boost/date_time/posix_time/posix_time.hpp"

class signal_target : public sc_module
{
public:

    signal_target(sc_module_name nm);
    virtual ~signal_target();

    /** Get my type (standard systemc).
     *
     * @return "EmuCpuTlm2BusMasterAdaptor"
     */
    virtual const char *kind() const
    {
        return "sc_module_slave";
    }

     /** Set the bus clock time period.
     * @todo: Map clock period to master
     *
     * @param period Clock period.
     */
    void setBusClockPeriod();

    /** Get the bus clock time period.
     *
     * @return period Clock period.
     */
    const sc_core::sc_time &busClockPeriod() const
    {
        return mBusClockPeriod;
    }

     /** Standard SystemC. */
    SC_HAS_PROCESS( signal_target );

    //sc_in<sc_time> time_port_i;
    sc_in<bool> bool_port_i;
    sc_in<sc_uint<UINT_SIGNAL_WIDTH> > uint_port_i;

    /** Standard SystemC function. */
    void end_of_elaboration();
    void executeMethod();
    void trace(sc_trace_file* tf);
    void end_of_simulation();
    void print_summary();

    /** My bus clock period.
     * @see busClockPeriod
     * @see setBusClockPeriod
     */
    sc_core::sc_time mBusClockPeriod;
    unsigned int m_counter;
    boost::posix_time::ptime  			sim_master_start_time, sim_master_end_time;

};

