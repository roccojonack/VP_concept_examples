//******************************************************************************
//------------------------------------------------------------------------------
//
//        Project
//         Module      Debug Register Testing Component
//
//------------------------------------------------------------------------------
//
//                     $Workfile:   debugReg.h	$
//                     $Revision:			$
//   Last changed on:  $Date:			$
//   Last changed by:  $Author:
//
//------------------------------------------------------------------------------

#ifndef DEBUGREG_H
#define DEBUGREG_H

#include <systemc.h>
#include <tlm_base.h>
#include <tlm_utils.h>

/*! \brief the debugReg class.
*
* This class models a debug 64b-Register. Every write to register
* from bus translates bitwise into output signal triggerings. The
* input and output signal arrays are of configurable (same) size ( up to 64 ).
* the internally triggered signal after reg writes combines via OR-gate
* to the incoming signals to generate the output counterpart.
*/
// ToDo : make this a template class in order to be more flexible with size and consistent
// between register size and bool array size
class debugReg : public TLM_BASE::vpCommon
{
public:

	SC_HAS_PROCESS( debugReg );

	debugReg( sc_module_name nm, TLM_BASE::uint32 signals_size );

	/*!
	* \brief Low active reset.
	*/
	sc_core::sc_in< bool >	reset_n_i;

	/*!
	* \brief clock input.
	*/
	sc_core::sc_in< sc_core::sc_time >	clkPeriod_i;

	// Signal input/output.
	scb_utils::SystemcPortArray<sc_in< bool > >		signals_i;
	scb_utils::SystemcPortArray<sc_out< bool > >	signals_o;

	// Socket.
	TLM_BASE::BaseProtocolTargetSocket< 32 >		target_socket;

private:
	TLM_BASE::RegisterN< TLM_BASE::uint32 >		trigger;
	TLM_BASE::uint32							signals_size_;
	bool										signals_o_internal[ 32 ];

	void				reset_CB();
	void				clkPeriod_CB();
	void				genORedSignalOutput();
	TLM_BASE::ret_t		triggerWriteCB( TLM_BASE::param_t &p );
};

#endif // DEBUGREG_H
