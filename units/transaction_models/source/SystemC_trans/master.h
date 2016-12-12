#pragma once
#include <iostream>
#include <systemc.h>
#include <tlm.h>
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/tlm_quantumkeeper.h"

class master: public sc_module
{
public:

    master(sc_module_name nm)
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
      int quantum = 100000;
      int transactionCheckpoint = 50000000;
      int m_delayInt = 0;
      int m_sync_counter = 0;
      // m_delay = SC_ZERO_TIME;
      tlm_utils::tlm_quantumkeeper::set_global_quantum(
				sc_core::sc_time(quantum, SC_NS));
      while(1) {
	for (int i=0; i<transactionCheckpoint; ++i) {
	  initiator_socket->b_transport(*transaction_ptr, m_slave_delay);
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

};

