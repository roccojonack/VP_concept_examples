// ------------------------------------------------------------------------------
//
//         Project
//          Module    Adapter_amba
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
#include <Adapter.h>
#include <amba.h>
#include <report.h>
#ifdef HAS_SCV
#include <tlm_genip/tlm2_scv_recorder.h>
#endif
//#include "boost/algorithm/string.hpp"
//#include "boost/date_time/posix_time/posix_time.hpp"
#define CLASSNAME_IMPL AdapterImpl

namespace TLM2_COMMON {

template<unsigned int INPUT_BUSWIDTH, unsigned int OUTPUT_BUSWIDTH>
class Adapter_amba : public Adapter<INPUT_BUSWIDTH, OUTPUT_BUSWIDTH>
{
public:
	Adapter_amba(sc_core::sc_module_name name
			, sc_dt::int64 addressOffset = 0
			, sc_dt::int64 id = -1
			, bool doRemoveByteEn = false);
    virtual ~Adapter_amba() {
	};
	bool add_extension(tlm::tlm_generic_payload& trans);
	bool remove_extension(tlm::tlm_generic_payload& trans);
	void populate_control_bits(
	 		amba_pv::amba_pv_extension* ctrl
	 		, bool priv
	 		, bool ns
	 		, bool inst
	 		, bool cacheable);
};
}; // namespace TLM2_COMMON
