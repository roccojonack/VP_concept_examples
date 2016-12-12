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
#pragma once
#include "tlm.h"
#include "sparsemem.h"
#include "report.h"

namespace TLM2_COMMON
{
class Scoreboard: public sc_module
{
public:
	const unsigned int blocksize;
	unsigned int time_interval;
	unsigned int comparisonCounter;
	long long unsigned int comparisonSuccessCounter;
	sparsemem *MasterMem;
	sparsemem *SlaveMem;
	unsigned char *MasterData;
	unsigned char *SlaveData;
	tlm::tlm_generic_payload *gpMaster;
	tlm::tlm_generic_payload *gpSlave;
	void setMasterMemoryInterface(sparsemem *mem);
	void setSlaveMemoryInterface(sparsemem *mem);

	SC_HAS_PROCESS (Scoreboard);
	Scoreboard(sc_module_name nm);
	~Scoreboard();

	void runThread();
	bool compareRegions();
	void dumpRegion(unsigned int address, unsigned int length);
	void loadRegion(unsigned int address, std::string fileName);
	void printResults() {
		cout << name() << " : Result of scoreboard comarison is" << endl
				<< " counted " << comparisonCounter << " times" << endl
				<< " got successful value comparison " << comparisonSuccessCounter << " times" << endl;
	}
};
}; // namespace TLM2_COMMON
