#pragma once
#include "tlm_base.h"      // TLM headers
#include "tlm_utils/tlm_quantumkeeper.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "dmi_memory.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <tlm_genip/tlm2_interconnect.h>
#include <tlm_hbs.h>
#include <tlm_hbs/stb_clkgen.h>
//#include <emu_cpu.h>
//#include <emu_cpu/stb_clkgen.h>
#include <Adapter.h>
#include "tb_mod_init_options.h"


template<unsigned int BUSWIDTH = 32>
class emu_initiator : public TLM_BASE::vpCommon
{
public:

    /** Constructor.
     * @param nm Module name
     * @param ID indentifier for initiator
     */
    emu_initiator                    // constructor
    ( sc_core::sc_module_name name  // module name
      , unsigned int  ID = 0 ///< initiator ID
   );
    /** Destructor
     */
    ~emu_initiator  ();
    SC_HAS_PROCESS(emu_initiator);

    /** trace interface used by vpCommon routines */
    virtual void trace(sc_trace_file*);
    virtual const char *kind() const
     {
         return "sc_module_master";
     };

//tlm_utils::simple_initiator_socket<emu_initiator, BUSWIDTH> initiator_socket;
	tlm::tlm_initiator_socket<BUSWIDTH> initiator_socket;
    sc_in<sc_time>                    clkPeriod_i;
    sc_in<bool>                       reset_i;

private:

    //==============================================================================
    ///     @brief SC_THREAD that performs blocking call (lt call)
    //
    ///     @details
    ///        This SC_THREAD takes transactions from traffic generator method.
    ///        Performs the blocking call.
    ///        After completing the blocking call the status is checked.
    //
    //==============================================================================
    void executeThread ();

    virtual void end_of_simulation();
    virtual void end_of_elaboration();
    void print_summary();

    tlm_genip::tlm2_interconnect< BUSWIDTH >    *bus;
    emu_cpu::EmuCpuAddrDataTlm2BusMaster  		*emuCPU;
    TLM2_COMMON::Adapter<32, BUSWIDTH>              *Adapter1;

    sc_signal<bool>             interrupt;

    tb_mod_init_options*		InitSingleton;
    unsigned int           		m_ID;
    unsigned int           		m_transport_counter;
    unsigned int           		m_sync_counter;
    boost::posix_time::ptime  	sim_master_start_time, sim_master_end_time;
    TLM_BASE::Attribute<unsigned int> m_QuantumTime;// TODO: do we need this?
    std::string           tc_name;  // TODO: do we need this? test case name entered from the command line
    std::ofstream         logStream; // TODO should move to thread
    TLM_BASE::Attribute<std::string> m_testcaseName;

};
