// ------------------------------------------------------------------------------
//
//     Project
//     Module
//
// ------------------------------------------------------------------------------
//
//
//                      $Workfile::   $
//                      $Revision:$
//    Last changed on:  $Date:   $
//    Last changed by:  $Author:  $
//
// ------------------------------------------------------------------------------
// ToDo: can probably be retired; sparsemem should become the main memory entry
#pragma once
#include "tlm.h"
#include "sparsemem.h"

namespace TLM2_COMMON {
template<unsigned int SZ, uint64 BUS_AWIDTH = 32, uint64 BUS_DWIDTH = 32>
class CommonMem: public sc_module
{
public:

	//sc_core::sc_time 				clkPeriod;
	tlm::tlm_target_socket<BUS_DWIDTH> tsock;	///< target socket
	TLM2_COMMON::tlm2_sparsemem <BUS_DWIDTH>	*mem;
	unsigned char 		*m_char_ptr;

	SC_HAS_PROCESS(CommonMem);
	CommonMem(sc_module_name nm, uint64 base = 0) :
			sc_module(nm)
		//, clkPeriod("clkPeriod")
	    , tsock("tsock" )
	{

		mem = new TLM2_COMMON::tlm2_sparsemem <BUS_DWIDTH>("CommonMemArray");
		//dont_initialize();
		tsock.bind(mem->target);
	    // set the default memory size
	    mem->memory_size.value = 0x1000;
	    // set some write delay
	    mem->write_delay.value =
	    		sc_core::sc_time (25, sc_core::SC_NS); //todo magic number
	    // set some accept delay
	    mem->accept_delay.value =
	        sc_core::sc_time (15, sc_core::SC_NS); //todo magic number
		std::cout << "Construction of target : " << basename()
				  << " from address " << base << std::endl;
	};

	~CommonMem() {
	};

	void dumpRegion(unsigned int address, unsigned int length) {
		m_char_ptr = new unsigned char[length];
		std::ostringstream msg;
		if (mem->read(m_char_ptr, address, length)) {
			msg << "found region starting at address " << address
					<< " with length " << length << " to be : ";
			for (unsigned int i = 0; i < length; ++i)
				msg << *m_char_ptr++;
			msg << endl;
			REPORT_INFO("CommonMem", __FUNCTION__, msg.str() );
		}
		else {
			REPORT_WARNING("CommonMem", __FUNCTION__,"couldn't read\n");
		};
	};

	void loadRegion(unsigned int address, std::string fileName) {
		ifstream ifile;
		std::string line;
		ifile.open(fileName.c_str());
		if (!ifile.is_open()) {
			std::ostringstream msg;
			msg << " Could not open " << fileName << std::endl;
			REPORT_ERROR("CommonMem", __FUNCTION__,	msg.str());
		}
		else {
			std::cout << "Opening file " << fileName << std::endl;
			unsigned int counter = address;
			while (!ifile.eof()) {
				std::getline(ifile, line);
				std::cout << "Reading line " << line << std::endl;
				mem->write(line.c_str(), counter, line.length());
				counter += line.length();
			};
		};
	};
};
};// namespace TLM2_COMMON
