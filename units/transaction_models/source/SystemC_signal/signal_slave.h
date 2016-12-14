#pragma once
#include <iostream>
#include <systemc.h>

class signal_slave : public sc_module
{
public:

    signal_slave(sc_module_name nm);
    virtual ~signal_slave();

    /** Get my type (standard systemc).
     *
     * @return 
     */
    virtual const char *kind() const
    {
        return "master";
    }

     /** Standard SystemC. */
    SC_HAS_PROCESS( signal_slave );

    sc_in<bool> 		clk;
    sc_in<bool> bool_port_i;
    sc_in<sc_uint<8> > uint_port_i;

    /** Standard SystemC function. */
    void end_of_elaboration();
    void executeMethod();
};

