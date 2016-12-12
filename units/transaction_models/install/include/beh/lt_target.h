#pragma once
#include "tlm.h"                                // TLM headers
#include "tlm_utils/simple_target_socket.h"
#include "tb_mod_init_options.h"
#include <iostream>
#include <fstream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "tlm2_sparsemem.h"
#include "constants.h"
#include "sparsemem.h"

namespace TLM2_COMMON {

template<unsigned int BUSWIDTH = 32>
class lt_target: public sc_module
{
public:
	SC_HAS_PROCESS(lt_target);
//=====================================================================
///	@fn lt_target
///
///	@brief Constructor for LT target
///
///	@details
///		Generic Single Phase target used in several examples.
///		Constructor offers several parameters for customization
///
//=====================================================================
	lt_target(sc_core::sc_module_name module_name      ///< SC module name
			, const sc_core::sc_time accept_delay = SC_ZERO_TIME///< accept delay (SC_TIME, SC_NS)
			);
	/** Destructor prints out the number of transactions received
	 */
	~lt_target()
	{
		print_summary();
	};

	/** trace interface used by vpCommon routines */
	virtual void trace(sc_trace_file*);

	virtual const char *kind() const
	{
		return "sc_module_slave";
	};


    void setMemoryInterface(sparsemem *mem)
    {
    	m_memory = mem;
    };

	tlm_utils::simple_target_socket<lt_target, BUSWIDTH> m_memory_socket; ///<  target socket


	/** customized b_transport function
	 */
	void                                                // returns nothing
	custom_b_transport(tlm::tlm_generic_payload &payload       // ref to payload
			, sc_core::sc_time &delay_time             // delay time
			);

	/** customized b_transport function
	 */
	void                                                // returns nothing
	custom_performance_b_transport(tlm::tlm_generic_payload &payload       // ref to payload
			, sc_core::sc_time &delay_time             // delay time
			);

	/** customized transport_dbg  function
	 */
	unsigned int                                              // returns nothing
	custom_transport_dbg(tlm::tlm_generic_payload &payload     // ref to payload
			);

	/** customized DMI function
	 */
	bool
	custom_get_direct_mem_ptr(tlm::tlm_generic_payload& trans,
			tlm::tlm_dmi& dmi_data);
	void doVerification(tlm::tlm_generic_payload& payload);
	void print_summary();
private:

	virtual void end_of_simulation();
	virtual void end_of_elaboration();

	tb_mod_init_options*		InitSingleton;
	const sc_core::sc_time 		m_accept_delay;      ///< accept delay
	unsigned char 				*m_mem;         ///< memory array
	unsigned char 				*m_gp_data;         ///< memory array
	sc_attribute<bool> 	m_verification;   ///< enabler for verification
	sc_attribute<bool> 	m_allowDMI;   ///<
	sc_attribute<bool> 	m_performance;   ///<
	sc_attribute<bool>	m_useWaitSlave;
	std::ofstream 				upstreamTrans;  ///< stream to log incoming transfers
	uint64 				        m_trans_counter;///< counter for incoming transfers
	tlm::tlm_generic_payload	m_gp_transaction;
	boost::posix_time::ptime 	sim_start_time, sim_end_time;
	boost::posix_time::time_duration sim_run_time;
	sc_event e1;
	sparsemem *m_memory;
};

}; // namespace TLM2_COMMON
