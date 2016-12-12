// ------------------------------------------------------------------------------
//
//         Project
//          Module    Adapter
//          Model Intend    The module is providing a TLM2 to TLM2 adapter which allows
//                          first of all forwarding of all TLM2 conform transfers
//                          Since the input and output are different sockets a width
//                          adaptation is possible
//                          There is also a number of interfaces to intercept and adapt
//                          transfers. Options are
//                          - providing an address offset
//                          - convert b_transport to transport_dbg
//                          - do endianess conversion
//                          - do tracing of transactions as text a
//
// ------------------------------------------------------------------------------
#pragma once
#include <tlm.h>
#include <report.h>
#include <common_defs.h>
//#include "boost/algorithm/string.hpp"
//#include "boost/date_time/posix_time/posix_time.hpp"
#define CLASSNAME Adapter
#define CLASSNAME_IMPL AdapterImpl

namespace TLM2_COMMON {
template<unsigned int INPUT_BUSWIDTH = 32, unsigned int OUTPUT_BUSWIDTH = 32,
		typename INPT = tlm::tlm_base_protocol_types,
		typename OUTPT = tlm::tlm_base_protocol_types>
class CLASSNAME_IMPL: public sc_module,
		public tlm::tlm_fw_transport_if<INPT>,
		public tlm::tlm_bw_transport_if<OUTPT> {
public:
	//! The target socket of the recorder to be bound to the initiator
	tlm::tlm_target_socket<INPUT_BUSWIDTH, INPT, 1> target_socket;
	//! The initiator to be bound to the target socket
	tlm::tlm_initiator_socket<OUTPUT_BUSWIDTH, OUTPT, 1> initiator_socket;

	/*! \brief The constructor of the component
	 *  \param name is the name given to the adapter instance.
	 *  \param addressOffset is an offset to be added to forwarded transactions (defaults to zero when not given).
	 */
	CLASSNAME_IMPL(sc_core::sc_module_name name
			, sc_dt::int64 addressOffset = 0
			, sc_dt::int64 id = -1
			, bool doRemoveByteEn = false);
    ~CLASSNAME_IMPL();
	SC_HAS_PROCESS(CLASSNAME_IMPL);

	// function to be overloaded for instance for dynamic routing; default implementation simply return true
	//and let's the access be handled by default call back functions
	/*! \brief The route function to allow dynamic routing
	 *
	 * This function is called in the beginning of default callbacks in order to allow dynamic prerouting is
	 * neseccary. Otherwise the transfer is simply handled by forwarding as is.
	 * \param trans is the generic payload of the transaction
	 * \return whether rerouting hasbeen performed. True means no prerouting!
	 */
	bool virtual route(tlm::tlm_generic_payload& trans) {
		return true;
	};

	// TLM-2.0 interface methods for initiator and target sockets, surrounded with Tx Recording
	/*! \brief The non-blocking forward transport function
	 *
	 * This type of transaction is forwarded and recorded to a transaction stream named "nb_fw" with current timestamps.
	 * \param trans is the generic payload of the transaction
	 * \param phase is the current phase of the transaction
	 * \param delay is the annotated delay
	 * \return the sync state of the transaction
	 */
	virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans,
			tlm::tlm_phase& phase, sc_core::sc_time& delay);

	/*! \brief The non-blocking backward transport function
	 *
	 * This type of transaction is forwarded and recorded to a transaction stream named "nb_bw" with current timestamps.
	 * \param trans is the generic payload of the transaction
	 * \param phase is the current phase of the transaction
	 * \param delay is the annotated delay
	 * \return the sync state of the transaction
	 */
	virtual tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload& trans,
			tlm::tlm_phase& phase, sc_core::sc_time& delay);

	/*! \brief The blocking transport function
	 *
	 * This type of transaction is forwarded and recorded to a transaction stream named "b_tx" with current timestamps. Additionally a "b_tx_timed"
	 * is been created recording the transactions at their annotated delay
	 * \param trans is the generic payload of the transaction
	 * \param delay is the annotated delay
	 */
	virtual void b_transport(tlm::tlm_generic_payload& trans,
			sc_core::sc_time& delay);

	/*! \brief The direct memory interface forward function
	 *
	 * This type of transaction is just forwarded and not recorded.
	 * \param trans is the generic payload of the transaction
	 * \param dmi_data is the structure holding the dmi information
	 * \return if the dmi structure is valid
	 */
	virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans,
			tlm::tlm_dmi& dmi_data);

	/*! \brief The direct memory interface backward function
	 *
	 * This type of transaction is just forwarded and not recorded.
	 * \param start_addr is the start address of the memory area being invalid
	 * \param end_addr is the end address of the memory area being invalid
	 */
	virtual void invalidate_direct_mem_ptr(sc_dt::uint64 start_addr,
			sc_dt::uint64 end_addr);

	/*! \brief The debug transport function
	 *
	 * This type of transaction is just forwarded and not recorded.
	 * \param trans is the generic payload of the transaction
	 * \return the sync state of the transaction
	 */
	virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans);

	/*! \brief A function to convert the payload in cases of different input and output width
	 *
	 * The function converts the payload depending on input and output width
	 *
	 * \param transfer_type
	 * \param address
	 * \param trans
	 * \param delay
	 */
	void do_conversion(std::string transfer_type, sc_dt::sc_uint<64> address,
			tlm::tlm_generic_payload& trans, sc_core::sc_time& delay);

	/*! \brief The setAddressOffset function
	 *
	 * The function is setting the address offset
	 * \param addr is the new address offset
	 */
	void setAddressOffset(sc_dt::int64 addr) {
		_addressOffset  = addr;
	};

	/*! \brief The getAddressOffset function
	 *
	 * The function is returning the address offset
	 */
	sc_dt::int64 getAddressOffset() {
		return _addressOffset ;
	};

	/*! \brief The setID function
	 *
	 * The function is setting the ID
	 * \param ID to be set
	 */
	void setID(sc_dt::uint64 id) {
		_ID = id;
	};

	/*! \brief The getPTTrace function
	 *
	 * The function is returning the value of _doPTTrace
	 */
	bool getPTTrace() {
		return _doPTTracing;
	};

	/*! \brief The setPTTrace function
	 *
	 *
	 * \param trace to be set
	 */
	void setPTTrace(bool trace) {
		_doPTTracing = trace;
	};

	/*! \brief The getLTConvert function
	 *
	 * The function is returning the value of _convertLT2DBG
	 */
	bool getLTConvert() {
		return _convertLT2DBG ;
	};

	/*! \brief The setLTConvert function
	 *
	 *
	 * \param trace to be set
	 */
	void setLTConvert(bool trace) {
		_convertLT2DBG  = trace;
	};

	/*! \brief The getDBGConvert function
	 *
	 * The function is returning the value of _convertDBG2LT
	 */
	bool getDBGConvert() {
		return _convertDBG2LT ;
	};

	/*! \brief The setDBGConvert function
	 *
	 *
	 * \param trace to be set
	 */
	void setDBGConvert(bool trace) {
		_convertDBG2LT  = trace;
	};

	/*! \brief The setLT2ATConvert function
	 *
	 *
	 * \param trace to be set
	 */
	void setLT2ATConvert(bool trace) {
		_convertLT2AT = trace;
	};

	/*! \brief The getLT2ATConvert function
	 *
	 *
	 */
	bool getLT2ATConvert() {
		return _convertLT2AT ;
	};

	/*! \brief The setfixeStreamingWidth function
	 *
	 *
	 * \param trace to be set
	 */
	void setfixeStreamingWidth(bool trace) {
	  _fixeStreamingWidth = trace;
	};

	/*! \brief The getfixeStreamingWidth function
	 *
	 *
	 */
	bool getfixeStreamingWidth() {
	  return _fixeStreamingWidth;
	};

	/*! \brief The getID function
	 *
	 * The function is returning the ID assinged to the current generic payload
	 */
	sc_dt::uint64 getID() {
		return _ID;
	};

	/*! \brief The get_b_transport_count function
	 *
	 * The function is returning the number of b_transport accesses
	 */
	sc_dt::uint64 get_b_transport_count() {
		return _b_transport_count;
	};

	/*! \brief The get_max_outstanding_trans function
	 *
	 * The function is returning the number of maximum outstanding transaction counter
	 */
	sc_dt::uint64 get_max_outstanding_trans() {
		return _max_outstanding_trans;
	};

	/*! \brief The set_max_outstanding_trans function
	 *
	 * The function is setting the number of maximum outstanding transaction counter
	 */
	void set_max_outstanding_trans(sc_dt::int64 trans) {
		_max_outstanding_trans = trans;
	};

	/*! \brief The get_transport_dbg_count function
	 *
	 * The function is returning the number of transport_dbg accesses
	 */
	sc_dt::uint64 get_transport_dbg_count() {
		return _transport_dbg_count;
	};

	/*! \brief The get_dmi_count function
	 *
	 * The function is returning the number of DMI accesses
	 */
	sc_dt::uint64 get_dmi_count() {
		return _dmi_count;
	};

	/*! \brief The print_counters function
	 *
	 * The function is returning the address offset
	 */
	void print_counters()
	{
		std::cout << "There are " << std::dec
				<< _b_transport_count << " b_transport calls, "
				<< _nb_transport_count << " nb_transport calls, "
				<< _transport_dbg_count << " transport_dbg calls, "
				<< _dmi_count << " DMI calls"
				<< " over socket: " << name() << std::endl;
		// std::cout << "Runtime for " << name() << " is " << sim_run_time.total_milliseconds() << " ms" << std::endl;
	};

	/*! \brief The add_extension function
	 *
	 * The function add_extension is reserved to setting extensions
	 * No extension is added in the base class; overload when needed
	 */
	virtual bool add_extension(tlm::tlm_generic_payload& trans);
	/*! \brief The trace_transaction function
	 *
	 */
	void trace_transaction(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, tlm::tlm_sync_enum& status, bool valid)
	{
		m_trace_transaction.address     = trans.get_address();
        m_trace_transaction.command     = trans.get_command();
        m_trace_transaction.data_length = trans.get_data_length();
        unsigned int trace_limit;
        if (m_trace_transaction.data_length>64) trace_limit = 64;
        else trace_limit = m_trace_transaction.data_length;
        for (unsigned char i=0; i<trace_limit; ++i)
        	m_trace_transaction.data_ptr[i] = *trans.get_data_ptr()+i;
        for (unsigned char i=trace_limit; i<64; ++i)
         	m_trace_transaction.data_ptr[i] = 0x42;
        m_trace_transaction.response_status    = trans.get_response_status();
        m_trace_transaction.streaming_width    = trans.get_streaming_width();
        m_trace_transaction.byte_enable_length = trans.get_byte_enable_length();
        if (m_trace_transaction.byte_enable_length>64) trace_limit = 64;
        else trace_limit = m_trace_transaction.byte_enable_length;
        for (unsigned char i=0; i<trace_limit; ++i)
        	m_trace_transaction.byte_enable_ptr[i] = *trans.get_byte_enable_ptr()+i;
        for (unsigned int i=trace_limit; i<64; ++i)
         	m_trace_transaction.byte_enable_ptr[i] = 0x42;
        m_trace_transaction.dmi_allowed 	= trans.is_dmi_allowed();
        m_trace_transaction.phase_id        = phase;
        m_trace_transaction.status          = status;
        m_trace_transaction.is_valid        = valid;
	};
	void update_trace_transaction(bool valid)
	{
        m_trace_transaction.is_valid        = valid;
	};
	void update_trace_transaction(tlm::tlm_sync_enum& status)
	{
        m_trace_resp_transaction.status         = status;
	};
	void update_trace_transaction(tlm::tlm_phase& phase)
	{
        m_trace_resp_transaction.phase_id       = phase;
	};

	/*! \brief The trace_transaction function
	 *
	 */
	void trace_resp_transaction(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, tlm::tlm_sync_enum& status, bool valid)
	{
		m_trace_resp_transaction.address     = trans.get_address();
        m_trace_resp_transaction.command     = trans.get_command();
        m_trace_resp_transaction.data_length = trans.get_data_length();
        unsigned int trace_limit;
        if (m_trace_resp_transaction.data_length>64) trace_limit = 64;
        else trace_limit = m_trace_resp_transaction.data_length;
        for (unsigned char i=0; i<trace_limit; ++i)
        	m_trace_resp_transaction.data_ptr[i] = *trans.get_data_ptr()+i;
        for (unsigned char i=trace_limit; i<64; ++i)
         	m_trace_resp_transaction.data_ptr[i] = 0x42;
        m_trace_resp_transaction.response_status    = trans.get_response_status();
        m_trace_resp_transaction.streaming_width    = trans.get_streaming_width();
        m_trace_resp_transaction.byte_enable_length = trans.get_byte_enable_length();
        if (m_trace_resp_transaction.byte_enable_length>64) trace_limit = 64;
        else trace_limit = m_trace_resp_transaction.byte_enable_length;
        for (unsigned char i=0; i<trace_limit; ++i)
        	m_trace_resp_transaction.byte_enable_ptr[i] = *trans.get_byte_enable_ptr()+i;
        for (unsigned int i=trace_limit; i<64; ++i)
         	m_trace_resp_transaction.byte_enable_ptr[i] = 0x42;
        m_trace_resp_transaction.dmi_allowed  	= trans.is_dmi_allowed();
        m_trace_resp_transaction.phase_id       = phase;
        m_trace_resp_transaction.status         = status;
        m_trace_resp_transaction.is_valid       = valid;
	};

   /*! \brief The remove_extension function
	 *
	 * The function add_extension is reserved to setting extensions
	 * No extension is added in the base class; overload when needed
	 */
	virtual bool remove_extension(tlm::tlm_generic_payload& trans);

	/*! \brief The end_of_simulation function
	 *
	 */
	virtual void end_of_simulation()
    {
		//sim_end_time = boost::posix_time::microsec_clock::universal_time();
		//sim_run_time += (sim_end_time - sim_start_time);
    	print_counters();
    };

	/*! \brief The end_of_elaboration function
	 *
	 */
	virtual void end_of_elaboration()
    {};

    //#define SC_TRACE_SIG(x) sc_trace(tf, x,       std::string(name()) + "." + #x)
    //#define SC_TRACE_VAR(x) sc_trace(tf, x,       std::string(name()) + "." + #x)
	//#define SC_TRACE_ATT(x) sc_trace(tf, x.value, std::string(name()) + "." + #x)
    void trace(sc_trace_file* tf)
    {
    	SC_TRACE_VAR(_doRemoveByteEn);
    	SC_TRACE_VAR(_addressOffset);
    	SC_TRACE_VAR(_upConvertion);
    	SC_TRACE_VAR(_downConvertion);
    	SC_TRACE_VAR(_ID);
    	SC_TRACE_VAR(_doWidthConversion);
    	SC_TRACE_VAR(_doPTTracing);
    	SC_TRACE_VAR(_convertLT2DBG);
    	SC_TRACE_VAR(_convertDBG2LT);
    	SC_TRACE_VAR(_convertLT2AT);
    	SC_TRACE_VAR(_fixeStreamingWidth);
    	SC_TRACE_VAR(_max_outstanding_trans);
    	//SC_TRACE_ATT(_convert_CMD_IOSF2TLM);
    	SC_TRACE_VAR(_b_transport_count);
    	SC_TRACE_VAR(_transport_dbg_count);
    	SC_TRACE_VAR(_nb_transport_count);
    	SC_TRACE_VAR(_outstanding_trans_counter);
    	SC_TRACE_VAR(_dmi_count);
    	SC_TRACE_VAR(_TransID);
    	//SC_TRACE_VAR(_RecordID);
    	//SC_TRACE_VAR(start_time);
    	//SC_TRACE_VAR(end_time);
    	report::sc_trace_trans(tf, std::string(name())+".m_trace_transaction", m_trace_transaction);
    	report::sc_trace_trans(tf, std::string(name())+".m_trace_resp_transaction", m_trace_resp_transaction);
   };

private:

    bool 			_doRemoveByteEn;
    unsigned int 	_addressOffset;
	sc_dt::uint64 	_upConvertion;
	sc_dt::uint64 	_downConvertion;
	sc_dt::int64 	_ID;
	bool 			_doWidthConversion;
	bool 			_doPTTracing;
	bool 			_convertLT2DBG;
	bool 			_convertDBG2LT;
	bool 			_convertLT2AT;
	bool 			_fixeStreamingWidth;
	unsigned int 	_max_outstanding_trans;
	bool 			_traceEnable;
	sc_dt::uint64 	_b_transport_count;
	sc_dt::uint64 	_nb_transport_count;
	sc_dt::uint64 	_transport_dbg_count;
    sc_dt::int64 	_outstanding_trans_counter;
	sc_dt::uint64 	_dmi_count;
 	unsigned int 	_TransID;
	double 			start_time, end_time;
	//boost::posix_time::ptime 	sim_start_time, sim_end_time;
	//boost::posix_time::time_duration sim_run_time;
	unsigned char* m_data;
	tlm::tlm_generic_payload*    m_gp_transaction;
	tlm_trace_payload    m_trace_transaction;
	tlm_trace_payload    m_trace_resp_transaction;
	// tlm_trace_phase    m_trace_phase;
    sc_time    		m_time;
    tlm::tlm_generic_payload ref_payload;
    uint64 repeat_counter;
    //sc_event  		e1;
    //class my_mm_interface:public tlm::tlm_mm_interface
    //{
    //	void free(tlm::tlm_generic_payload *my)
    //	{
    //		delete my;
    //	};
    //};
    //my_mm_interface my_mm;
};

template<unsigned int INPUT_BUSWIDTH = 32, unsigned int OUTPUT_BUSWIDTH = 32,
		typename INPT = tlm::tlm_base_protocol_types,
		typename OUTPT = tlm::tlm_base_protocol_types>
class CLASSNAME : public sc_module
{
public:
	tlm::tlm_target_socket<INPUT_BUSWIDTH, INPT, 1> target_socket;
	tlm::tlm_initiator_socket<OUTPUT_BUSWIDTH, OUTPT, 1> initiator_socket;

	CLASSNAME(sc_core::sc_module_name name, sc_dt::int64 addressOffset =
			0, sc_dt::int64 id = -1,
			bool doRemoveByteEn = false);
    virtual ~CLASSNAME() {
	  if (adapter1)
	    delete adapter1;
	};
	CLASSNAME_IMPL<INPUT_BUSWIDTH, OUTPUT_BUSWIDTH, INPT, OUTPT> *adapter1;
};

}; // namespace TLM2_COMMON
