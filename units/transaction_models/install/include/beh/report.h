#pragma once
#include "systemc.h"                                     ///< TLM headers
#include "tlm.h"                                     ///< TLM headers
#include "constants.h"
#include "common_defs.h"
//#include <amba.h>

namespace report
{
  std::string print ( const tlm::tlm_sync_enum status );
  std::string print ( const tlm::tlm_phase phase );

  std::string print ( tlm::tlm_generic_payload& );
  std::string pretty_print ( tlm::tlm_generic_payload&, tlm::tlm_phase_enum phase = tlm::BEGIN_REQ, std::string StartString = "", std::string timeString = "");
  tlm::tlm_generic_payload* parse_command ( std::string   );
  //  std::string print ( amba_pv::amba_pv_extension& );

  std::string print ( tlm::tlm_dmi& );
  void sc_trace_trans (sc_trace_file*, std::string, tlm_trace_payload& );
  bool compare_gp 	(tlm::tlm_generic_payload&, tlm::tlm_generic_payload&, unsigned long long org_time = 0, unsigned long long ref_time = 0);
};

