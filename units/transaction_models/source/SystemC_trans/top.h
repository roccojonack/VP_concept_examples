#pragma once

#include <tlm.h>
#include "master.h"
#include "slave.h"

struct top: sc_module
{
  // instantiate modules
  master master1;
  slave  slave1;

  top(sc_module_name nm)
    : sc_module(nm)
    , master1("master1")
    , slave1("slave1")
  {
    cout <<"constructing " << name() << endl;
    // connect ports with channels to create the top level netlist
    master1.initiator_socket.bind(slave1.target_socket);
  };

};


