#pragma once

#include <custom_io_if.h>
#include "memory_if.h"
#include "sparsemem.h"
#include <vector>

#include <tlm_base/vp_bus_slaves.h>
#include <tlm_base/StorageAdapter.h>


namespace TLM2_COMMON {

struct memory_array_if;
namespace internal {
    struct storage_adapter_if;
};
class sparsemem_proxy: public TLM_BASE::BusSlave, public sparsemem::operation_listener {
public:
    sparsemem_proxy(const char* name, TLM_BASE::vpCommon* parent, sc_dt::uint64 memory_size);

   TLM_BASE::ret_t read(TLM_BASE::param_t& p);
   TLM_BASE::ret_t write(TLM_BASE::param_t& p);
   TLM_BASE::ret_t read(tlm::tlm_generic_payload& gp);
   TLM_BASE::ret_t write(tlm::tlm_generic_payload& gp);

   void setSize(sc_dt::uint64 size){this->mSize.value=size;}
   void setTargetMemory(memory_if* mem_if) {mem=mem_if;}

   virtual void notify(op_type type, sc_dt::uint64 addrs, sc_dt::uint64 size);

protected:
   TLM2_COMMON::memory_if* mem;
   friend struct internal::storage_adapter_if;
   friend class  sparsemem;
};
};
