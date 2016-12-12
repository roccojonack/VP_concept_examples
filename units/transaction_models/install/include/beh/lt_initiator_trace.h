#pragma once
#include "systemc.h"
#include "tlm.h"      // TLM headers
#include "tb_mod_init_options.h"
#include "tlm_utils/tlm_quantumkeeper.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "lt_initiator.h"
#include "report.h"
namespace TLM2_COMMON {

const sc_dt::uint64 NumberOfRepetitions = 100;
//const sc_dt::uint64 MaxTranactionLength = 64;
const sc_dt::uint64 RegisterOffset = 0x0;

struct command_struct {
	tlm::tlm_command 	cmd;
	sc_dt::uint64 		addr;
	sc_dt::uint64 		length;
	sc_dt::uint64 		value;
	double 				delay;
};
static struct command_struct DefaultCommands[] = {
		  { tlm::TLM_WRITE_COMMAND, (0xc  + RegisterOffset), 4, 0x1000,  500 }
		, { tlm::TLM_WRITE_COMMAND, (0x10 + RegisterOffset), 4, 0x1050,  5 }
		, { tlm::TLM_WRITE_COMMAND, (0x8  + RegisterOffset), 4,    0xc,  5 }
		, { tlm::TLM_WRITE_COMMAND, (0x4  + RegisterOffset), 4, 0x4005, 15 }
		, { tlm::TLM_WRITE_COMMAND, (0xc  + RegisterOffset), 4, 0x1050,  5 }
		, { tlm::TLM_WRITE_COMMAND, (0x10 + RegisterOffset), 4, 0x1100,  5 }
		, { tlm::TLM_WRITE_COMMAND, (0x8  + RegisterOffset), 4,    0xc,  5 }
		, { tlm::TLM_WRITE_COMMAND, (0x4  + RegisterOffset), 4, 0x2005, 45 }
};
const sc_dt::uint64 DefaultNumberOfCommands = sizeof(DefaultCommands)
		/ sizeof(DefaultCommands[0]);

template<unsigned int BUSWIDTH = 32>
class lt_initiator_trace : public TLM2_COMMON::lt_initiator<BUSWIDTH>
{
 public:

    /** Constructor.
     * @param nm Module name
     * @param ID indentifier for initiator
     */
    lt_initiator_trace ( sc_core::sc_module_name name
    		, unsigned int  		ID = 0
            , bool 					thread = true
    );
    /** Destructor
     */
    ~lt_initiator_trace  ();
    /** trace interface */
    void trace(sc_trace_file*);

protected:

    virtual void 			read_tracefile(ifstream &);
    virtual bool 			update_transaction_ptr(tlm::tlm_generic_payload *, unsigned int);
    virtual void 			end_of_elaboration();

    unsigned char 				*m_Data_ptr;
    unsigned char 				*m_BE_ptr;
    unsigned int 				m_numberOfCommands;
    vector<command_struct> 		m_commands;
    sc_attribute<std::string> 	m_filename;
    sc_attribute<unsigned int>  m_TraceFileType;
    sc_attribute<unsigned int>  m_maxNumberOfCachedCommands;

  };

};
