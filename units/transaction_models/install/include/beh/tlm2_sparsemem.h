#pragma once

#include "custom_io_if.h"
#include <memory_busif.h>
#include <sparsemem.h>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <stdexcept>

namespace TLM2_COMMON {

/*! \brief TLM2.0 compliant memory with adaptive allocation
 *
 * The tlm2_adaptivemem implements a memory with dynamic memory allocation
 * this allows to define memories being larger than the hosts memory - as
 * long as not all host memory is used during simulation.
 */
template<unsigned BUSWIDTH=32>
class tlm2_sparsemem: public sc_module {
public:
    //! The target socket of the memory
    tlm::tlm_target_socket<BUSWIDTH>  target;
    //! Configures the size of the memory, cfg name is MEMORY_SIZE, default 0
    sc_core::sc_attribute<sc_dt::uint64> memory_size;
    //! Configures DMI capability, cfg name is DMI_ALLOWED, default true
    sc_core::sc_attribute<bool> dmi_allowed;
    //! Configures the latency of the interface, cfg name is ACCEPT_DELAY, default 0ns
    sc_core::sc_attribute<sc_core::sc_time> accept_delay;
    //! Configures read access time of the memory, cfg name is READ_DELAY, default 0ns
    sc_core::sc_attribute<sc_core::sc_time> read_delay;
    //! Configures write access time of the memory, cfg name is WRITE_DELAY, default 0ns
    sc_core::sc_attribute<sc_core::sc_time> write_delay;
    //! Configures if the memory should use wait() to consume the annotated delay, cfg name is BLOCKING_WAIT,
    //! default false
    sc_core::sc_attribute<bool> blocking_wait;
    //! Configures if the memory is read only aka a ROM, cfg name is READ_ONLY, default false
    sc_core::sc_attribute<bool> read_only;
    //! Configures the block size of the memory allocation (which are the memory ranges used for DMI), valid values
    //! are 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
    sc_core::sc_attribute<unsigned short> alloc_size;
    //! Configures the pattern to be used for uninitialized memory
    sc_core::sc_attribute<unsigned short> pattern;
    //! Configures the pattern to be used for uninitialized memory
    sc_core::sc_attribute<sc_dt::uint64> max_pages;
    //! Configures if the checkpoints should be compressed
    sc_core::sc_attribute<bool> compress_ckpt;

    /*! \brief constructor of the tlm2_adaptivemem
     *
     * \param name instance name of the memory
     */
    tlm2_sparsemem(sc_core::sc_module_name name);

    void setCustomIO(TLM2_COMMON::custom_io_if* customIO){this->customIO=customIO;}

    bool read(unsigned char* data, sc_dt::uint64 start, unsigned char size) const;

    bool write(const unsigned char* data, sc_dt::uint64 start, unsigned char size);

    // checkpointing interface
    void createReverseCheckpoint(void*& handleOut){
        if(memory)
            handleOut=(void*)memory->createReverseCheckpoint();
    }

    void mergeReverseCheckpoints(const void *toHandle, const void *fromHandle){
        if(memory)
            if(!memory->mergeReverseCheckpoints((uint64)toHandle, (sc_dt::uint64)fromHandle)){
                throw std::runtime_error("Could not merge");
            }
    }

    void rollbackReverseCheckpoints(const void *handle){
        if(memory)
            if(!memory->rollbackReverseCheckpoints((sc_dt::uint64)handle)){
                throw std::runtime_error("Could not roll back");
            }
    }

    void createDiskCheckpoint(std::ostream& outstream){
        if(memory) memory->createDiskCheckpoint(outstream, compress_ckpt.value);
    }

    void revertToDiskCheckpoint(std::istream& instream){
        if(memory) memory->revertToDiskCheckpoint(instream, compress_ckpt.value);
    }
    void setMemoryInterface(sparsemem *mem)
      {
    	if (busif) busif->setMemoryInterface( mem);
      };

protected:
    /*! \brief sc kernel callback
     *
     */
    virtual void end_of_elaboration();

    void invalidate_region(const sc_dt::uint64 start, const sc_dt::uint64 end);
    TLM2_COMMON::sparsemem* memory;
    TLM2_COMMON::memory_busif* busif;
    TLM2_COMMON::custom_io_if* customIO;
};

}

