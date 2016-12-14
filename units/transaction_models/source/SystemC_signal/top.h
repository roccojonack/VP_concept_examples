#pragma once

#include "signal_master.h"
#include "signal_slave.h"

struct top: sc_module
{
	// instantiate modules
	signal_master tg_inst;
	signal_slave  display_inst;

	// instantiate channels
	sc_signal<sc_uint<8> > sig1;
	sc_signal<bool > sig2;
	sc_clock clock;

	SC_CTOR(top):
	tg_inst("tg_inst")
	, display_inst("display_inst")
	, sig1("sig1")
	, sig2("sig2")
	, clock("CLOCK", 10, SC_NS, 0.5, 0.0, SC_NS)
	{
	  // connect ports with channels to create the top level netlist
	  tg_inst.clk(clock);
	  display_inst.clk(clock);
	  tg_inst.uint_port_o(sig1);
	  display_inst.uint_port_i(sig1);
	  tg_inst.bool_port_o(sig2);
	  display_inst.bool_port_i(sig2);
	};
};
