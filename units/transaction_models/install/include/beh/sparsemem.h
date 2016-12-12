#pragma once

#include <custom_io_if.h>
#include <memory_if.h>
#include <vector>
#include <boost/function.hpp>
#include <report.h>

namespace TLM2_COMMON {
namespace internal {
struct memory_array_if;
struct checkpoint_manager;
};

class sparsemem: public TLM2_COMMON::memory_if {
public:
    enum alloc_block_size {X1=1, X2=2, X4=4, X8=8, X16=16, X32=32, X64=64, X128=128, X256=256, X512=512, X1024=1024};

    struct operation_listener {
      enum op_type {READ_OP, WRITE_OP};
      virtual void notify(op_type type, sc_dt::uint64 addrs, sc_dt::uint64 size)=0;
    };
    //=====================================================================
    /// @fn sparsemem
    //
    ///  @brief sparsemem Constructor
    //
    ///  @details
    //       Initialize member variables, include allocating and initializing
    //       the actual memory
    //
    //=====================================================================
    sparsemem(sc_core::sc_time read_delay, sc_core::sc_time write_delay, sc_dt::uint64 memory_size,
            unsigned short memory_width, uint8_t pattern = 0, bool read_only=false,
            alloc_block_size alloc_size=X1, unsigned max_pages=0);
    //=====================================================================
    /// @fn ~sparsemem
    //
    ///  @brief sparsemem Destructor
    //
    ///  @details
    //       Free-up all resoruces
    //
    //=====================================================================
    ~sparsemem();
    //====================================================================
    /// @fn operation
    ///
    ///  @brief Performs the Memory Operation specified in the GP
    ///
    ///  @details
    ///    Performs the operation specified by the GP
    ///    Returns after updating the status of the GP (if required)
    ///    and updating the time based upon initialization parameters
    ///
    ///===================================================================
    void operation(tlm::tlm_generic_payload &gp, sc_core::sc_time &delay_time);

    //====================================================================
    /// @fn annotate_delay
    ///
    ///  @brief Looks at GP and returns delay without doing GP Operation
    ///
    ///  @details
    ///    Performs the operation specified by the GP
    ///    Returns after updating the status of the GP (if required)
    ///    and updating the time based upon initialization parameters
    ///
    ///===================================================================
    void annotate_delay(tlm::tlm_generic_payload &gp, sc_core::sc_time &delay_time);

    //====================================================================
    /// @fn get_delay
    ///
    ///  @brief Looks at GP and returns delay without doing GP Operation
    ///
    ///  @details
    ///    Performs the operation specified by the GP
    ///    Returns after updating the status of the GP (if required)
    ///    and updating the time based upon initialization parameters
    ///
    ///===================================================================
    virtual sc_core::sc_time get_delay(tlm::tlm_command access_type);

    //==============================================================================
    ///  @fn get_mem_ptr
    //
    ///  @brief Method to return pointer to memory in this object
    //
    ///  @details
    ///    This routine used during dmi example
    //
    //==============================================================================
    boost::tuple<unsigned char*, sc_dt::uint64, sc_dt::uint64> get_mem_ptr(tlm::tlm_generic_payload  &gp, access_type type);

    //==============================================================================
    ///  @fn set_expunge_callback
    //
    ///  @brief Method to provide a callback to be called if a page gets invalid
    //
    ///  @details
    ///    This routine used during dmi example
    //
    //==============================================================================
    void set_evict_callback(boost::function<void(const sc_dt::uint64, const sc_dt::uint64)> const &callback);

    //==============================================================================
    ///  @fn setCustomIO
    //
    ///  @brief sets a custom io processor for paging
    //
    ///  @details
    ///    This routine used during dmi example
    //
    //==============================================================================
   void setCustomIO(custom_io_if* customIO);

   //==============================================================================
   ///  @fn setListener
   //
   ///  @brief sets a listener being notified upon each read/write operation
   //
   ///  @details
   ///    This routine used during dmi example
   //
   //==============================================================================
   void setListener(operation_listener* listener){m_listener=listener;}

   sc_dt::uint64 createReverseCheckpoint();
   bool mergeReverseCheckpoints(sc_dt::uint64 to, sc_dt::uint64 from);
   bool rollbackReverseCheckpoints(sc_dt::uint64 id);
   void createDiskCheckpoint(std::ostream& outstream, bool compress=false);
   void revertToDiskCheckpoint(std::istream& instream, bool compres=false);
   bool getOpenPages(std::vector<unsigned int> &pages, unsigned int &blocksize) {
	   pages     = m_pagesInUseVerification;
	   blocksize = 1024*1024;
	   // m_pagesInUseVerification.clear();
	   return true;
   };
   bool addToUsedPages(unsigned int index) {
	   std::vector<unsigned int>::iterator it;
	   for(it=m_pagesInUseVerification.begin(); it < m_pagesInUseVerification.end(); it++) {
		   if (index==*it)
			   return false;
	   };
	   if (tlm_enable_info_reporting) {
		   std::ostringstream     msg;
		   msg.str("");
		   msg << "adding pages " << index;
		   REPORT_INFO("sparsemem", __FUNCTION__, msg.str());
	   };
	   m_pagesInUseVerification.push_back(index);
	   std::sort (m_pagesInUseVerification.begin(), m_pagesInUseVerification.end());
	   return true;
   }
protected:
    sc_core::sc_time 			m_read_delay;    ///< read delay
    sc_core::sc_time 			m_write_delay;   ///< write delay
    internal::memory_array_if* 		m_memory;  ///< memory
    bool 				m_previous_warning; ///< limits to one message
    unsigned char 			m_pattern;
    operation_listener* 		m_listener;
    internal::checkpoint_manager* 	chkpt_mgr;
    std::vector<unsigned int>           m_pagesInUseVerification;
    bool                                m_trackPages;
};
}
