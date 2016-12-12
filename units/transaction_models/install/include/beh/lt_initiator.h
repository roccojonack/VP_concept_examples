#pragma once
#include "systemc.h"
#include "tlm.h"
#include "tlm_utils/tlm_quantumkeeper.h"
#include "tlm_utils/simple_initiator_socket.h"
#include "sparsemem.h"
#include "constants.h"
#include "tb_mod_init_options.h"
#include "boost/date_time/posix_time/posix_time.hpp"
namespace TLM2_COMMON {

struct COMMAND {
	unsigned int length;
	tlm::tlm_command cmd;
	unsigned char data[MAX_LENGTH];
};

template<unsigned int BUSWIDTH = 32>
class lt_initiator : public sc_module
{
public:
	COMMAND COMMANDS[NUMBER_OF_COMMANDS];

    /** Constructor.
     * @param nm Module name
     * @param ID indentifier for initiator
     * @param thread using a thread to drive traffic or a method
     */
    lt_initiator                    // constructor
    ( sc_core::sc_module_name 	name  // module name
      , unsigned int  			ID 		= 0 ///< initiator ID
      , bool 					thread 	= true
    );

    /** Destructor
     */
    ~lt_initiator  ();
    SC_HAS_PROCESS(lt_initiator);

    /** trace interface used by vpCommon routines */
    void trace(sc_trace_file*);

    void setMemoryInterface(sparsemem *mem)
    {
    	m_memory = mem;
    };
    /** specify the kind of the module */
    virtual const char *kind() const
    {
         return "sc_module_master";
    };

    tlm_utils::simple_initiator_socket<lt_initiator, BUSWIDTH> initiator_socket;

    /** print a summary of important performance information; called in destructor */
    void print_summary();

protected:

    // Method Declarations =========================================================
    //==============================================================================
    ///     @brief SC_METHOD that performs blocking call (lt call)
    //
    ///     @details
    ///        This SC_METHOD takes transactions from traffic generator method.
    ///        and performs the blocking call (careful since b_transport allows waits!) .
    ///        After completing the blocking call the status is checked.
    //
    //==============================================================================
    void executeMethod ();

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

    //==============================================================================
    ///     @brief SC_THREAD that performs blocking call (lt call) with limited
    ///            functionality for performance reasons
    //
    ///     @details
    ///        This SC_THREAD takes some default transactions and performs the blocking call.
    ///        After completing the blocking call the status is checked.
    //
    //==============================================================================
    void performanceThread ();

    //==============================================================================
    ///     @brief function that performs the core functionality of any transaction
    //
    ///     @details
    ///        Depending on parameter settings the method is generating either a randomized
    ///        transactions or a default transaction for more performance. Also a logging
    ///        in a log file is possible in order to do offine verification.
    ///
    //==============================================================================
    bool executeCore ();

    /** assign a transaction to a pointer, which will be sent
     * @param read_counter number of subsequent reads
     * @param write_counter number of subsequent writes
     * @param randomization randomize the values in transaction
     */
    virtual bool update_transaction_ptr(tlm::tlm_generic_payload *, unsigned int);

    virtual void end_of_simulation();

    virtual void end_of_elaboration();

    tb_mod_init_options*		InitSingleton;
    sc_core::sc_time      		m_slave_delay; // initialize delay which is passed to slave
    tlm::tlm_response_status 	m_gp_status; // holds response value for tracing
    tlm_utils::tlm_quantumkeeper 	m_quantum_keeper; // local quantum keeper
    uint64       				m_transport_counter; // number of transactions started
    uint64       				m_sync_counter; // number of synchronization events
    uint64       				m_address; // saving the current address
    sc_attribute<unsigned int>  m_ID; // an ID which can be provided during construction
    sc_attribute<unsigned int>  m_transaction_type; // transaction type to be used (b_transport,transport_dbg or DMI)
    sc_attribute<unsigned int> 	m_transaction_length; // transaction length
    sc_attribute<bool> 			m_verification; // defines whether or not to support hooks for verification
    sc_attribute<bool> 			m_performance; // defines whether or not to run performance simulations
    ofstream 					downstreamTrans;// should be retied
    boost::posix_time::ptime  	m_sim_master_start_time, m_sim_master_end_time; // measure processor time
public:
    sc_attribute<unsigned int> 	m_intertransaction_delay; // delay between 2 transactions
    sc_attribute<unsigned int> 	m_QuantumTime; // local quantum time
private:
 	tlm::tlm_generic_payload 	*m_transaction_ptr; // pointer to current transaction
	tlm::tlm_dmi 				*m_dmi_data; // DMI data structure; only used when m_transaction_type defines DMI
	sparsemem *m_memory;
	unsigned int m_startupDelay; // delay before first transaction starts in NS
};
}; // namespace TLM2_COMMON
