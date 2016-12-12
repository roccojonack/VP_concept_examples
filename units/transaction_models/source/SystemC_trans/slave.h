#pragma once
#include <iostream>
#include <systemc.h>
#include <tlm.h>
#include "tlm_utils/simple_target_socket.h"

class slave : public sc_module
{
public:

    slave(sc_module_name nm) : sc_module(nm)
      , m_trans_counter(0)
    {
      std::cout << "Construction of target : " << basename() << std::endl;
      target_socket.register_b_transport(this, &slave::custom_b_transport);
    };

    ~slave() {};

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
    void setBusClockPeriod(const sc_core::sc_time &period);

    /** Get the bus clock time period.
     *
     * @return period Clock period.
     */
    const sc_core::sc_time &busClockPeriod() const
    {
        return mBusClockPeriod;
    };

     /** Standard SystemC. */
    SC_HAS_PROCESS( slave );

    tlm_utils::simple_target_socket<slave, 32> target_socket;

    /** customized b_transport function
     */
    void  custom_b_transport(tlm::tlm_generic_payload &payload
			     , sc_core::sc_time &delay_time
			)
    {
      m_trans_counter++;

      payload.set_dmi_allowed(false);
      payload.set_response_status(tlm::TLM_OK_RESPONSE);
      return;
    };

    /** Standard SystemC function. */
    void end_of_elaboration() {};

    /** My bus clock period.
     * @see busClockPeriod
     * @see setBusClockPeriod
     */
    sc_core::sc_time mBusClockPeriod;
    unsigned int m_trans_counter;
    // sc_core::sc_time      		m_accept_delay;

};

