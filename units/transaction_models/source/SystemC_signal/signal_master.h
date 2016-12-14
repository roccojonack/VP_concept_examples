#pragma once
#include <iostream>
#include <systemc.h>

class signal_master: public sc_module
{
public:

    signal_master(sc_module_name nm);
    virtual ~signal_master();

    /** Get my type (standard systemc).
     *
     * @return 
     */
    virtual const char *kind() const
    {
        return "master";
    }

     /** Standard SystemC. */
    SC_HAS_PROCESS( signal_master );

    sc_in<bool> 		clk;
    sc_out<bool> 		bool_port_o;
    sc_out<sc_uint<8> > uint_port_o;

    /** Standard SystemC function. */
    void end_of_simulation();
    void executeMethod();

    unsigned long long int m_counter; // counting number of events

};

