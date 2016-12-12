#pragma once
#include "tlm.h"                // TLM headers
#include "at_initiator.h"       // AT initiator
#include "traffic_generator.h"  // traffic generator

class initiator_top
: public sc_module
{
//Member Methods  =====================================================

  public:

//=====================================================================
///  @fn initiator_top::initiator_top
//
///  @brief initiator_top constructor
//
///  @details
///    Initiator top module contains a traffic generator and an example
///    unique initiator module
//
//=====================================================================
  initiator_top
  ( sc_core::sc_module_name name                ///< module name
  , const unsigned int  ID                      ///< initiator ID
  , sc_dt::uint64       address          ///< base address
  , unsigned int        active_txn_count        ///< Max number of active transactions
  );

private:

/// Not Implemented for this example but required by the initiator socket
  void
  invalidate_direct_mem_ptr
  ( sc_dt::uint64      start_range
  , sc_dt::uint64      end_range
  );

/// Not Implemented for this example but require by the initiator socket
  tlm::tlm_sync_enum
  nb_transport_bw
  ( tlm::tlm_generic_payload  &payload
  , tlm::tlm_phase            &phase
  , sc_core::sc_time          &delta
  );

//Member Variables/Objects  ===========================================

  public:

  tlm::tlm_initiator_socket<> initiator_socket;	///< processor socket

  private:

  typedef tlm::tlm_generic_payload  *gp_ptr;   ///< Generic Payload pointer

  sc_core::sc_fifo <gp_ptr>  m_request_fifo;   ///< request SC FIFO
  sc_core::sc_fifo <gp_ptr>  m_response_fifo;  ///< response SC FIFO

  const unsigned int         m_ID;             ///< initiator ID
  bool                       m_enable_target_tracking; ///< track target timing

  at_initiator           m_initiator;      ///< TLM initiator instance
  traffic_generator          m_traffic_gen;    ///< traffic generator instance

};

