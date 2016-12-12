#pragma once
#include <iostream>
#include <systemc.h>

class signal_master: public sc_module
{
public:

    signal_master(sc_module_name nm);
    virtual ~signal_master();

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
    SC_HAS_PROCESS( signal_master );

    sc_out<bool> 		bool_port_o;
    sc_out<sc_uint<8> > uint_port_o;

    /** Standard SystemC function. */
    void end_of_elaboration();
    void end_of_simulation();
    void executeMethod();

    /** My bus clock period.
     * @see busClockPeriod
     * @see setBusClockPeriod
     */
    sc_core::sc_time mBusClockPeriod;

    unsigned int counter;

};

