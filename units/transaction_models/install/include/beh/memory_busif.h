#pragma once

#include <systemc.h>
#include <tlm>
#include <tlm_utils/peq_with_get.h>                   // Payload event queue FIFO
#include <memory_if.h>
#include <sparsemem.h>

namespace TLM2_COMMON {

class memory_busif: public sc_module, virtual public tlm::tlm_fw_transport_if<> {
public:
  typedef tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types> bw_target_if;

  enum begin_resp {
    REQ_ACCEPT=0, REQ_ACCEPT_BEG_RESP, REQ_UPDATED_END, REQ_UPDATED_BEG, REQ_COMPLETED
  };
  enum end_resp {
    RESP_COMPLETED=0, RESP_ACCEPTED, RESP_RANDOM
  };

  //=====================================================================
  ///	@fn at_initiator_1_phase
  ///
  ///	@brief Constructor for Single Phase AT target
  ///
  ///	@details
  ///		Generic Single Phase target used in several examples.
  ///		Constructor offers several parameters for customization
  ///
  //=====================================================================
  memory_busif(
      sc_core::sc_module_name   module_name           ///< SC module name
      , sc_core::sc_port_b<bw_target_if>& memory_bw_port
      , TLM2_COMMON::memory_if*                mem
      , const begin_resp          bresp = REQ_ACCEPT
      , const end_resp            eresp = RESP_RANDOM
      , const tlm::tlm_dmi::dmi_access_e dmi_type = tlm::tlm_dmi::DMI_ACCESS_NONE
      , const bool enforce_blocking_wait = false
  );

  //=====================================================================
  ///	@brief Implementation of call from Initiator.
  //
  ///	@details
  ///		This is the ultimate destination of the nb_transport_fw call from
  ///		the initiator after being routed trough a Bus
  //
  //=====================================================================
  tlm::tlm_sync_enum nb_transport_fw(
      tlm::tlm_generic_payload &gp                    ///< generic payoad pointer
      , tlm::tlm_phase         &phase                 ///< transaction phase
      , sc_core::sc_time       &delay_time            ///< time taken for transport
  );

  //=====================================================================
  ///  @fn memory_busif::end_request_method
  ///
  ///  @brief End Request Processing
  ///
  ///  @details
  ///                   ????
  //=====================================================================
  void end_request_method( void );

  //=====================================================================
  ///  @fn memory_busif::begin_response_method
  ///
  ///  @brief Response Processing
  ///
  ///  @details
  ///    This routine takes transaction responses from the m_response_PEQ.
  ///    It contains the state machine to manage the communication path
  ///    back to the initiator. This method is registered as an SC_METHOD
  ///    with the SystemC kernal and is sensitive to m_response_PEQ.get_event()
  //=====================================================================
  void begin_response_method( void );

  const sc_core::sc_time& getAcceptDelay() const {
    return m_accept_delay;
  }

  void setAcceptDelay(const sc_core::sc_time& acceptDelay) {
    m_accept_delay = acceptDelay;
  }

  const TLM2_COMMON::memory_if* getTargetMemory() const {
    return m_target_memory;
  }

  void setTargetMemory(TLM2_COMMON::memory_if* targetMemory) {
    m_target_memory = targetMemory;
  }

  void setDmiType(tlm::tlm_dmi::dmi_access_e type){
    m_dmi_type=type;
  }
  void setMemoryInterface(TLM2_COMMON::sparsemem *mem)
   {
 	  m_verifmemory = mem;
   };

private:
  /// helper function for printing memory transactions
  //   void print_memory_transaction_helper(
  //		   const int 				  &ID
  //		   , std::ostringstream  	  &partial_msg
  //		   , tlm::tlm_generic_payload  &trans
  //   );

  //==============================================================================
  // Methods not Implemented for this Example
  /// b_transport() - Blocking Transport
  void b_transport(
      tlm::tlm_generic_payload  &payload                // ref to payload
      , sc_core::sc_time          &delay_time             // delay time
  );

  bool get_direct_mem_ptr(
      tlm::tlm_generic_payload   &payload,            // address + extensions
      tlm::tlm_dmi               &dmi_data            // DMI data
  );

  unsigned int transport_dbg( tlm::tlm_generic_payload  &payload);

  sc_core::sc_port_b<bw_target_if>& bw_port;


  sc_core::sc_time          m_accept_delay;         ///< accept delay
  unsigned long             m_request_count;        ///< used to calc synch transactions
  bool                      m_nb_trans_fw_prev_warning;
  bool                      m_nb_trans_bw_prev_warning;
  bool                      m_end_request_method_prev_warning;
  bool                      m_begin_resp_method_prev_warning;
  bool                      m_trans_dbg_prev_warning;
  bool                      m_get_dm_ptr_prev_warning;
  tlm_utils::peq_with_get<tlm::tlm_generic_payload>
  m_end_request_PEQ;      ///< response payload event queue
  sc_core::sc_event         m_end_resp_rcvd_event;
  tlm_utils::peq_with_get<tlm::tlm_generic_payload>
  m_response_PEQ;         ///< response payload event queue
  unsigned					 m_response_cnt;
  TLM2_COMMON::memory_if*                m_target_memory;
  const begin_resp          m_bresp;
  const end_resp            m_eresp;
  begin_resp                m_lbresp;
  end_resp                  m_leresp;
  bool                      resp_in_progress;
  tlm::tlm_dmi::dmi_access_e m_dmi_type;
  bool                      m_dmi_broadcasted;
  bool                      m_enforce_blocking_wait;
  TLM2_COMMON::sparsemem *m_verifmemory;
};
}
