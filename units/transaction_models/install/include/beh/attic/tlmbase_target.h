#pragma once
#include "tlm_base.h"
#include "tlm_utils/simple_target_socket.h"
#include "tb_mod_init_options.h"
#include <iostream>
#include <fstream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "constants.h"
#define REGNAME(x, y) x_y

template<unsigned int BUSWIDTH = 32, unsigned int NUMBER_OF_REGISTERS = 4>
class tlmbase_target: public TLM_BASE::vpCommon
{
public:
	SC_HAS_PROCESS(tlmbase_target);
//=====================================================================
///	@fn tlmbase_target
///
///	@brief Constructor for LT target
///
///	@details
///		Generic Single Phase target used in several examples.
///		Constructor offers several parameters for customization
///
//=====================================================================
	tlmbase_target(sc_core::sc_module_name module_name);      ///< SC module name

	/** Destructor prints out the number of transactions received
	 */
	~tlmbase_target()
	{
		std::cout << name() << " received " << m_trans_counter
				<< " transactions" << std::endl;
	};
	/** trace interface used by vpCommon routines */
	virtual void trace(sc_trace_file*);

	virtual const char *kind() const
	{
		return "sc_module_slave";
	};

	TLM_BASE::BaseProtocolTargetSocket<BUSWIDTH>    target_socket;
	sc_in<sc_time> 									clkPeriod;

	void 			doVerification(tlm::tlm_generic_payload& payload);
	TLM_BASE::ret_t reg1WriteCb(tlm::tlm_generic_payload &gp);
	TLM_BASE::ret_t reg1ReadCb (tlm::tlm_generic_payload &gp);

private:

	virtual void end_of_simulation();
	virtual void end_of_elaboration();
	void setBusClockPeriod();

    tb_mod_init_options*		InitSingleton;
	TLM_BASE::Attribute<unsigned int> 	m_NumberOfRegisters;///<
	std::ofstream 				upstreamTrans;  ///< stream to log incoming transfers
	unsigned int 				m_trans_counter;///< counter for incoming transfers
	boost::posix_time::ptime 	sim_start_time, sim_end_time;
    std::vector<TLM_BASE::Register32 *> m_reg_ptr;
};
