#pragma once
#include <systemc.h>

const unsigned int           MAX_DATA_LENGTH         = 64;
// static values in order to allow VCD tracing; initiator has to feed the values
struct tlm_trace_payload
{
	sc_dt::uint64 		address; // address in transaction object
	sc_dt::sc_uint<3> 	command; // command
	sc_dt::sc_uint<8> 	data_length; // length of data in transaction in byte
	char 		data_ptr[MAX_DATA_LENGTH]; // limited to 64 byte pretty arbitrary for the moment
	sc_dt::sc_uint<3> 	response_status; // response type
	sc_dt::sc_uint<8> 	streaming_width; // streaming width for transaction
	sc_dt::sc_uint<8> 	byte_enable_length; //
	char 		byte_enable_ptr[MAX_DATA_LENGTH]; //limited to 64 byte pretty arbitrary for the moment
	bool 		dmi_allowed; // identifies whether DMI is allowed for transaction
	sc_dt::sc_uint<3> 	phase_id; // phase value
	sc_dt::sc_uint<2> 	status; // sync status
	bool 		is_valid; // helper value ot identify when transaction is valid
	sc_dt::uint64 		RecordID; //

	tlm_trace_payload()
	{
		address = 0; // address in transaction object
		command = 0; // command
		data_length = 0; // length of data in transaction in byte
		// data_ptr[MAX_DATA_LENGTH]; // limited to 64 byte pretty arbitrary for the moment
		response_status = 0; // response type
		streaming_width = 0; // streaming width for transaction
		byte_enable_length = 0; //
 		//byte_enable_ptr[MAX_DATA_LENGTH]; //limited to 64 byte pretty arbitrary for the moment
		dmi_allowed = false; // identifies whether DMI is allowed for transaction
		phase_id = 0; // phase value
		status = 0; // sync status
 		is_valid = false; // helper value ot identify when transaction is valid
		RecordID = 0; //

	};
};

void
sc_trace (sc_trace_file* _tf,
		const sc_time& _t,
		std::string _name)
{
	sc_trace(_tf, _t.to_default_time_units(), _name);
}

// the size of address range the target socket occupies
const unsigned long long int TARGET_ADDRESS_RANGE       = 0x100000;
const unsigned long long int DEFAULT_DATA_OFFSET        = 42;
const unsigned long long int MAX_INTERTRANSACTION_DELAY = 100;
const unsigned int           UINT_SIGNAL_WIDTH          = 16;
const unsigned int           TRANSACTION_LENGTH_RANGE   = 64;

// used in lt_initator
const int MAX_LENGTH = 128; // maximum length of burst
const int NUMBER_OF_COMMANDS = 2; // number of default commands
