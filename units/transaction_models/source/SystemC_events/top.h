#pragma once
#include "systemc.h"

// testing the runtime for event generators
struct top: sc_module
{
	sc_clock clk;
	top(sc_module_name nm)
    : sc_module(nm)
	, clk("clk", 10, SC_NS)
  {
    cout <<"constructing " << name() << " with a clock period of 10 ns" << endl;
  };
};

