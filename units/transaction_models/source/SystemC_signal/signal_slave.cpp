/*
 * 
 *
  */
#include <signal_slave.h>

signal_slave::signal_slave(sc_module_name nm)
    : sc_module(nm)
    , clk("clk")
    , bool_port_i("bool_port_i")
    , uint_port_i("uint_port_i")

{
  SC_METHOD(executeMethod);
  sensitive << bool_port_i << uint_port_i;
}

signal_slave::~signal_slave()
{
}

// ***************** executeRequest **********************
void signal_slave::executeMethod()
{
  bool_port_i.read();
  uint_port_i.read();
};

void signal_slave::end_of_elaboration()
{
    sc_module::end_of_elaboration();
}
