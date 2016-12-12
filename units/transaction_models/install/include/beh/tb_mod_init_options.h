/* -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*- */
#pragma once
#include <string>

class tb_mod_init_options
{
	static tb_mod_init_options* instance;

	// arguments that can be passed when starting the simulation
	unsigned int QuantumTime;
	bool         useWaitSlave;
	unsigned int IntertransactionDelay;
	bool         showHelp;
	unsigned int TransactionType;
	unsigned int NumberOfRead;
	unsigned int NumberOfWrite;
	unsigned int LengthOfTransaction;
	int 		 CommandSequenceRepeat;
	bool         Verification;
	bool         Randomization;
	bool         Performance;
	bool         FileReader;
	std::string  testcaseName;
	// define memory size for Mem/HighMem/SparseMem targets [bits]
	uint64_t 		memory_size;
	unsigned int	NumberOfRegisters;
	unsigned int	NumberOfInstances;

	bool m_didConfigure; // indicates whether or not the configuration functions (parseOptions) was called
public:

	tb_mod_init_options() {m_didConfigure = false;};
	static tb_mod_init_options* getSingletonObject();
	unsigned int getQuantumTime()  			{return QuantumTime;};
	bool         getuseWaitSlave() 			{return useWaitSlave;};
	unsigned int getIntertransactionDelay()	{return IntertransactionDelay;};
	bool         getshowHelp()				{return showHelp;};
	unsigned int getTransactionType()		{return TransactionType;};
	unsigned int getNumberOfRead()			{return NumberOfRead;};
	unsigned int getNumberOfWrite()			{return NumberOfWrite  ;};
	unsigned int getLengthOfTransaction()	{return LengthOfTransaction;};
	int 		 getCommandSequenceRepeat()	{return CommandSequenceRepeat;};
	bool         getVerification()			{return Verification;};
	bool         getRandomization()			{return Randomization;};
	bool         getPerformance()			{return Performance;};
	bool         getFileReader()			{return FileReader;};
	std::string  gettestcaseName()			{return testcaseName;};
	uint64_t 	 getmemory_size()			{return memory_size;};
	unsigned int getNumberOfRegisters()		{return NumberOfRegisters;};
	unsigned int getNumberOfInstances()		{return NumberOfInstances;};

     /**
     * parses command line options
     *
     * resulting options can be retrieved from 'tb_options' struct
     *
     * @param argc argc as given to main()
     * @param argv argv as given to main()
     * @return true if successful and program should proceed, false if program should abort
     */
    bool parseOptions( int argc, char **argv );

    /**
     * dumps option setting to stdout
     */
    void dumpOptions();

    /**
     * use parsing of options from file
     */
    bool parseOptionsInFile( std::string fileName );

};

