#pragma once
#include "systemc.h"
#include "tlm.h"      // TLM headers
#include "tb_mod_init_options.h"
#include "lt_initiator.h"
//#include "boost/date_time/posix_time/posix_time.hpp"
namespace TLM2_COMMON {

template<unsigned int BUSWIDTH = 32>
class lt_initiator_verification : public TLM2_COMMON::lt_initiator<BUSWIDTH>
{
public:

    /** Constructor.
     * @param nm Module name
     * @param ID indentifier for initiator
     */
    lt_initiator_verification                    // constructor
    	( sc_core::sc_module_name name  // module name
    	, unsigned int  		ID 		= 0 ///< initiator ID
        , bool 					thread 	= true
   );
    /** Destructor
     */
    ~lt_initiator_verification  ();
    // SC_HAS_PROCESS(lt_initiator_verification);

    /** trace interface */
    void trace(sc_trace_file*);
    virtual const char *kind() const
    {
         return "sc_module_master";
    };

private:

    // Method Declarations =========================================================
    bool update_transaction_ptr(tlm::tlm_generic_payload *trans, unsigned int counter);

    tb_mod_init_options*		InitSingleton;
    sc_attribute<unsigned int> 	m_ID;
	unsigned char  				*m_Data_ptr;
	unsigned char  				*m_BE_ptr;
	bool 						m_read;
	unsigned long long int 		m_address;
    unsigned int                m_length;
};
};
