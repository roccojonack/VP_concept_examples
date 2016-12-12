#pragma once

#include <systemc.h>
#include <tlm>
#include <boost/tuple/tuple.hpp>
#include <stdint.h>

namespace TLM2_COMMON {

struct memory_if {
    enum access_type { ACCESS_READ = 0x01, ACCESS_WRITE = 0x02, ACCESS_RW = ACCESS_READ|ACCESS_WRITE};
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
	virtual void operation(tlm::tlm_generic_payload  &gp, sc_core::sc_time &delay_time)=0;

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
	virtual void annotate_delay(tlm::tlm_generic_payload  &gp, sc_core::sc_time &delay_time)=0;

    sc_dt::uint64  get_mem_size(){ return m_memory_size;}

    unsigned short  get_mem_width(){ return m_memory_width;}

    bool isReadOnly() const {return m_read_only;}

    virtual sc_core::sc_time get_delay(tlm::tlm_command access_type)=0;

	virtual boost::tuple<unsigned char*, sc_dt::uint64, sc_dt::uint64> get_mem_ptr(tlm::tlm_generic_payload  &gp, access_type access)=0;


	memory_if(sc_dt::uint64 memory_size, unsigned short memory_width, bool read_only=false)
    : m_memory_size(memory_size)
	, m_memory_width(memory_width)
	, m_read_only(read_only)
	, m_name("")
	{
    }

	virtual ~memory_if(){}
	std::string m_name;
	void setName(std::string name) {
		m_name = name;
	}
protected:
	//==============================================================================
	///  @fn ram::check_address
	//
	///  @brief Method to check if the gp is in the address range of this memory
	//
	///  @details
	///    This routine used to check for errors in address space
	//
	//==============================================================================
	tlm::tlm_response_status check_access( tlm::tlm_generic_payload  &gp){
	    sc_dt::uint64 address = gp.get_address();
	    if((address<0)||(address>=m_memory_size)) return tlm::TLM_ADDRESS_ERROR_RESPONSE; // operation response
	    if((address+gp.get_data_length())>m_memory_size) return tlm::TLM_ADDRESS_ERROR_RESPONSE; // operation response
	    if(m_read_only && gp.get_command()== tlm::TLM_WRITE_COMMAND && sc_core::sc_time_stamp().value())
	        return tlm::TLM_COMMAND_ERROR_RESPONSE;
	    return tlm::TLM_OK_RESPONSE;
	}

	sc_dt::uint64         m_memory_size;           ///< memory size (bytes)
	unsigned short        m_memory_width;          ///< memory width (bytes)
	bool                  m_read_only;
};
}
