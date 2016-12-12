#pragma once
#include <iostream>
#include <systemc.h>
#include <tlm.h>
#include <tb_mod_init_options.h>
#include <constants.h>
#include "tlm_utils/tlm_quantumkeeper.h"
#include "boost/date_time/posix_time/posix_time.hpp"

class signal_initiator : public sc_module
{
public:

    signal_initiator(sc_module_name nm, bool thread = false);
    virtual ~signal_initiator();

    /** Get my type (standard systemc).
     *
     * @return "EmuCpuTlm2BusMasterAdaptor"
     */
    virtual const char *kind() const
    {
        return "sc_module_master";
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
    SC_HAS_PROCESS( signal_initiator );

    // todo : for now there is no clock input port; should be added consistently
    //sc_out<sc_time> 					time_port_o;
    sc_out<bool> 						bool_port_o;
    sc_out<sc_uint<UINT_SIGNAL_WIDTH> > uint_port_o;

    /** Standard SystemC function. */
    void end_of_elaboration();
    void end_of_simulation();
    void executeCore();
    void executeMethod();
    void executeThread();
    void print_summary();
    void trace(sc_trace_file* tf);

    /** input to define clock period.
     * @see busClockPeriod
     * @see setBusClockPeriod
     */
	tb_mod_init_options*		InitSingleton;
    sc_core::sc_time 					mBusClockPeriod;
    sc_attribute<unsigned int> 	intertransaction_delay;
    sc_attribute<unsigned int> 	m_QuantumTime;
    tlm_utils::tlm_quantumkeeper 	 	m_quantum_keeper;
    unsigned int           		      	m_sync_counter;
    unsigned int           		      	m_transport_counter;
    boost::posix_time::ptime  			sim_master_start_time, sim_master_end_time;

};

