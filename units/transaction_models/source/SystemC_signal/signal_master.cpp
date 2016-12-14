/*
 * test_master.cpp
 *
  */
#include <signal_master.h>

signal_master::signal_master(sc_module_name nm)
    : sc_module(nm)
    , bool_port_o("bool_port_o")
    , uint_port_o("uint_port_o")
    , clk("clk")
    , m_counter(0)
{
     SC_METHOD(executeMethod);
     sensitive << clk.pos();
}

signal_master::~signal_master()
{
}

// ***************** executeRequest **********************
void signal_master::executeMethod()
{
	bool_port_o.write(! bool_port_o.read());
	uint_port_o.write(uint_port_o.read()+1);
	m_counter++;
};

void signal_master::end_of_simulation()
{
  std::cout << "Information : sent " << m_counter << " signal events " << std::endl;
  // sc_module::end_of_simulation();
}
