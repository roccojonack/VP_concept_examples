#pragma once
#include <iostream>
#include <systemc.h>
#include <tlm.h>
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/tlm_quantumkeeper.h"
#define HAS_SCV
#ifdef HAS_SCV
#include <scv.h>
#include "tlm_gp_data_ext.h"
#include "tlm_gp_data.h"
#endif



class master: public sc_module
{
public:

 master(sc_module_name nm)
    : sc_module       ( nm )
    , pipelined_stream( "pipelined_stream", "transactor")
#ifdef HAS_SCV
    , test_gen        ( "test" ,pipelined_stream ,"test")
    , tlm_gen         ( "TLM2" ,pipelined_stream ,"TLM2")
    , read_gen        ( "read" ,pipelined_stream ,"addr" ,"data")
    , write_gen       ( "write",pipelined_stream ,"addr" ,"data")
#endif
  {
	std::cout << "Construction of initiator : " << basename() << std::endl;
	SC_THREAD(executeThread);
	init();
	setBusClockPeriod(sc_time(1, SC_NS));
      };

    ~master() {};

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
    void setBusClockPeriod(const sc_core::sc_time &period)
    {
      mBusClockPeriod = period;
    };

    /** Get the bus clock time period.
     *
     * @return period Clock period.
     */
    const sc_core::sc_time &busClockPeriod() const
    {
        return mBusClockPeriod;
    }

     /** Standard SystemC. */
    SC_HAS_PROCESS( master );

    //sc_in<sc_time> clk_i;
    tlm_utils::simple_initiator_socket<master, 32> initiator_socket;
    tlm::tlm_generic_payload 	*transaction_ptr;
    unsigned char 	       	*WrData;
    sc_core::sc_time      	m_slave_delay;

    void init()
    {
      unsigned long long int address = 0;
      m_slave_delay = SC_ZERO_TIME;
      WrData   = new unsigned char[4];

      for (unsigned int i = 0; i < 4; ++i) {
    	  WrData[i] = i;
      }

      transaction_ptr = new tlm::tlm_generic_payload;
      transaction_ptr->set_data_ptr(&WrData[0]);
      transaction_ptr->set_byte_enable_ptr(NULL);
      transaction_ptr->set_command(tlm::TLM_WRITE_COMMAND);
      transaction_ptr->set_address(address);
      transaction_ptr->set_data_length(4);
      transaction_ptr->set_streaming_width(4);
      transaction_ptr->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

    };

    /** Standard SystemC function. */
    void end_of_elaboration() {};
    void executeThread()
    {
      int j=0;
      int quantum = 1;
      int transactionCheckpoint = 50000000;
      int m_delayInt = 0;
      int m_sync_counter = 0;
      // m_delay = SC_ZERO_TIME;
      tlm_utils::tlm_quantumkeeper::set_global_quantum(
				sc_core::sc_time(quantum, SC_NS));
      while(1) {
	for (int i=0; i<transactionCheckpoint; ++i) {
	  initiator_socket->b_transport(*transaction_ptr, m_slave_delay);
#ifdef HAS_SCV
	  scv_tr_handle h = read_gen.begin_transaction(transaction_ptr->get_address());
	  TracePacket tmp;
	  tmp.address = transaction_ptr->get_address();
	  tmp.data    = transaction_ptr->get_data_ptr()[0];
	  tmp.isRead  = transaction_ptr->is_read();
	  scv_tr_handle h1 = test_gen.begin_transaction(tmp);
	  scv4tlm::tlm_gp_data tmp1(*transaction_ptr);
	  scv_tr_handle h2 = tlm_gen.begin_transaction(tmp1);
	  unsigned int data = 0xdeadbeef;
	  read_gen.end_transaction(h, data);
	  test_gen.end_transaction(h1);
	  tlm_gen.end_transaction(h2);
#endif
	  //if ((i%quantum) == 0)
	  //  wait(quantum*mBusClockPeriod);
	  //m_delay += sc_core::sc_time(1, SC_NS);
	  m_delayInt++;
	  if (m_delayInt==quantum) {
	    m_quantum_keeper.set(m_delayInt*mBusClockPeriod);
	    // m_quantum_keeper.set(m_delay);
	    //if (m_quantum_keeper.need_sync()) {
	    m_quantum_keeper.sync();
	    // resetting the local time offset?
	    //m_delay = SC_ZERO_TIME;
	    m_delayInt=0;
	    //cout << "sync point " << m_sync_counter++ << endl;
	  };
	};
	cout << "checkpoint number " << j++
	     << " after " << transactionCheckpoint
	     << " transactions" << endl;
      };
    };

    /** My bus clock period.
     * @see busClockPeriod
     * @see setBusClockPeriod
     */
    sc_core::sc_time mBusClockPeriod;
    // sc_core::sc_time m_delay;
    tlm_utils::tlm_quantumkeeper 	m_quantum_keeper;
#ifdef HAS_SCV
    scv_tr_stream                                  pipelined_stream;
    scv_tr_generator< TracePacket >                test_gen;
    scv_tr_generator< scv4tlm::tlm_gp_data>        tlm_gen;
    scv_tr_generator< unsigned int, unsigned int > read_gen;
    scv_tr_generator< unsigned int, unsigned int > write_gen;
#endif

};

