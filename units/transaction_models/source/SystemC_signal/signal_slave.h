#pragma once
#include <iostream>
#include <systemc.h>

class signal_slave : public sc_module
{
public:

    signal_slave(sc_module_name nm);
    virtual ~signal_slave();

    /** Get my type (standard systemc).
     *
     * @return "EmuCpuTlm2BusMasterAdaptor"
     */
    virtual const char *kind() const
    {
        return "master";
    }

     /** Set the bus clock time period.
     * @todo: Map clock period to master
     *
     * @param period Clock period.
     */
    void setBusClockPeriod(const sc_core::sc_time &period);

    /** Get the bus clock time period.
     *
     * @return period Clock period.
     */
    const sc_core::sc_time &busClockPeriod() const
    {
        return mBusClockPeriod;
    }

     /** Standard SystemC. */
    SC_HAS_PROCESS( signal_slave );

    sc_in<bool> bool_port_i;
    sc_in<sc_uint<8> > uint_port_i;

    /** Standard SystemC function. */
    void end_of_elaboration();
    void executeMethod();

    /** My bus clock period.
     * @see busClockPeriod
     * @see setBusClockPeriod
     */
    sc_core::sc_time mBusClockPeriod;

};

