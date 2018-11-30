#include "systemc.h"
#include "scv.h"
#include "scext/record/cwr_thread_trace.h"
#include "../HARDWARE.cpp"
namespace {

template <class T >
class sc_core_sc_signal_in_if_wrapper;
class sc_core_cwr_sc_signal_base_wrapper : public sc_core::cwr_sc_signal_base, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::cwr_sc_signal_base* cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_interface_as_sc_object
  int cwr_trace_id8; // readCosim
  int cwr_trace_id9; // readDebugNewValue
  int cwr_trace_id10; // readRaw
  int cwr_trace_id11; // register_port
  int cwr_trace_id12; // writeCosim
  int cwr_trace_id13; // writeRaw

 public:
  sc_core_cwr_sc_signal_base_wrapper(sc_core::cwr_sc_signal_base *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(cwr_p0);
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(cwr_p0);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_cwr_sc_signal_base_wrapper (dynamic_cast<sc_core::cwr_sc_signal_base * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< bool>  : public sc_core::sc_signal_in_if< bool> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< bool> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // negedge
  int cwr_trace_id10; // negedge_event
  int cwr_trace_id11; // posedge
  int cwr_trace_id12; // posedge_event
  int cwr_trace_id13; // read
  int cwr_trace_id14; // readCosim
  int cwr_trace_id15; // readDebugNewValue
  int cwr_trace_id16; // readRaw
  int cwr_trace_id17; // register_port
  int cwr_trace_id18; // value_changed_event
  int cwr_trace_id19; // writeCosim
  int cwr_trace_id20; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< bool>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"negedge");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"negedge_event");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"posedge");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"posedge_event");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id20 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(cwr_p0);
  }
  const bool & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    const bool & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  bool negedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->negedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & negedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->negedge_event();
  }
  bool posedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->posedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & posedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->posedge_event();
  }
  const bool & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    const bool & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(cwr_p0);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id20,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< bool>  (dynamic_cast<sc_core::sc_signal_in_if< bool>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< sc_dt::sc_logic>  : public sc_core::sc_signal_in_if< sc_dt::sc_logic> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // negedge
  int cwr_trace_id10; // negedge_event
  int cwr_trace_id11; // posedge
  int cwr_trace_id12; // posedge_event
  int cwr_trace_id13; // read
  int cwr_trace_id14; // readCosim
  int cwr_trace_id15; // readDebugNewValue
  int cwr_trace_id16; // readRaw
  int cwr_trace_id17; // register_port
  int cwr_trace_id18; // value_changed_event
  int cwr_trace_id19; // writeCosim
  int cwr_trace_id20; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< sc_dt::sc_logic>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"negedge");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"negedge_event");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"posedge");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"posedge_event");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id20 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(cwr_p0);
  }
  const sc_dt::sc_logic & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_logic & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  bool negedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->negedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & negedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->negedge_event();
  }
  bool posedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->posedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & posedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->posedge_event();
  }
  const sc_dt::sc_logic & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_logic & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(cwr_p0);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id20,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< sc_dt::sc_logic>  (dynamic_cast<sc_core::sc_signal_in_if< sc_dt::sc_logic>  * >(intf));
  }
};

template <class T >
class sc_core_sc_signal_write_if_wrapper;
template <class T >
class sc_core_sc_signal_inout_if_wrapper;
template<>
class sc_core_sc_signal_write_if_wrapper< bool>  : public sc_core::sc_signal_write_if< bool> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< bool> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< bool>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const bool & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< bool>  (dynamic_cast<sc_core::sc_signal_write_if< bool>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< bool>  : public sc_core::sc_signal_inout_if< bool> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< bool> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // negedge
  int cwr_trace_id10; // negedge_event
  int cwr_trace_id11; // posedge
  int cwr_trace_id12; // posedge_event
  int cwr_trace_id13; // read
  int cwr_trace_id14; // readCosim
  int cwr_trace_id15; // readDebugNewValue
  int cwr_trace_id16; // readRaw
  int cwr_trace_id17; // release_clamp
  int cwr_trace_id18; // value_changed_event
  int cwr_trace_id19; // write
  int cwr_trace_id20; // writeCosim
  int cwr_trace_id21; // writeRaw
  int cwr_trace_id22; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< bool>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"negedge");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"negedge_event");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"posedge");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"posedge_event");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id20 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id21 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id22 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< bool> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const bool * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< bool> * cwr_delegate = cwr_delegate_;
    const bool * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const bool & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    const bool & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  bool negedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->negedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & negedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->negedge_event();
  }
  bool posedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->posedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & posedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->posedge_event();
  }
  const bool & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,false);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    const bool & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::sc_signal_inout_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    snps::sc::signal_clamp_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    sc_core::sc_signal_in_if< bool> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const bool & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id20,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id21,true);
    sc_core::sc_signal_inout_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const bool & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id22,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< bool>  (dynamic_cast<sc_core::sc_signal_inout_if< bool>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< sc_dt::sc_logic>  : public sc_core::sc_signal_write_if< sc_dt::sc_logic> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< sc_dt::sc_logic> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< sc_dt::sc_logic>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const sc_dt::sc_logic & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< sc_dt::sc_logic>  (dynamic_cast<sc_core::sc_signal_write_if< sc_dt::sc_logic>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_logic>  : public sc_core::sc_signal_inout_if< sc_dt::sc_logic> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // negedge
  int cwr_trace_id10; // negedge_event
  int cwr_trace_id11; // posedge
  int cwr_trace_id12; // posedge_event
  int cwr_trace_id13; // read
  int cwr_trace_id14; // readCosim
  int cwr_trace_id15; // readDebugNewValue
  int cwr_trace_id16; // readRaw
  int cwr_trace_id17; // release_clamp
  int cwr_trace_id18; // value_changed_event
  int cwr_trace_id19; // write
  int cwr_trace_id20; // writeCosim
  int cwr_trace_id21; // writeRaw
  int cwr_trace_id22; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< sc_dt::sc_logic>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"negedge");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"negedge_event");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"posedge");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"posedge_event");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id20 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id21 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id22 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_logic * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_logic * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_dt::sc_logic & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_logic & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  bool negedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->negedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & negedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->negedge_event();
  }
  bool posedge() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->posedge();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & posedge_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->posedge_event();
  }
  const sc_dt::sc_logic & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,false);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_logic & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    sc_core::sc_signal_in_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const sc_dt::sc_logic & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id20,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id21,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const sc_dt::sc_logic & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id22,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_logic>  (dynamic_cast<sc_core::sc_signal_inout_if< sc_dt::sc_logic>  * >(intf));
  }
};

class sc_core_sc_clock_if_wrapper : public sc_core::sc_clock_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_clock_if* cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_duty_cycle
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // get_next_edge_offset
  int cwr_trace_id4; // get_period
  int cwr_trace_id5; // get_posedge_first
  int cwr_trace_id6; // get_start_time
  int cwr_trace_id7; // register_port

 public:
  sc_core_sc_clock_if_wrapper(sc_core::sc_clock_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_duty_cycle");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"get_next_edge_offset");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"get_period");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"get_posedge_first");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_start_time");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  double get_duty_cycle() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    double cwr_tmp = cwr_delegate->get_duty_cycle();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_time get_next_edge_offset(bool pos_edge) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("pos_edge", pos_edge);
    }
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_next_edge_offset(pos_edge);
  }
  sc_core::sc_time get_period() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_period();
  }
  bool get_posedge_first() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,false);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->get_posedge_first();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_time get_start_time() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_start_time();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_clock_if_wrapper (dynamic_cast<sc_core::sc_clock_if * >(intf));
  }
};

class sc_core_sc_event_queue_if_wrapper : public sc_core::sc_event_queue_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_event_queue_if* cwr_delegate_;
  int cwr_trace_id0; // cancel_all
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // notify
  int cwr_trace_id4; // notify
  int cwr_trace_id5; // register_port

 public:
  sc_core_sc_event_queue_if_wrapper(sc_core::sc_event_queue_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"cancel_all");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"notify");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"notify");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  void cancel_all()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_event_queue_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->cancel_all();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void notify(const sc_core::sc_time & when)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::sc_event_queue_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->notify(when);
  }
  void notify(double when, sc_core::sc_time_unit base)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("when", when);
    }
    sc_core::sc_event_queue_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->notify(when,base);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_event_queue_if_wrapper (dynamic_cast<sc_core::sc_event_queue_if * >(intf));
  }
};

template <class T >
class sc_core_sc_fifo_nonblocking_in_if_wrapper;
template <class T >
class sc_core_sc_fifo_blocking_in_if_wrapper;
template <class T >
class sc_core_sc_fifo_in_if_wrapper;
template <class T >
class sc_core_sc_fifo_nonblocking_out_if_wrapper;
template <class T >
class sc_core_sc_fifo_blocking_out_if_wrapper;
template <class T >
class sc_core_sc_fifo_out_if_wrapper;
class sc_core_sc_mutex_if_wrapper : public sc_core::sc_mutex_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_mutex_if* cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // lock
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // trylock
  int cwr_trace_id5; // unlock

 public:
  sc_core_sc_mutex_if_wrapper(sc_core::sc_mutex_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"lock");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"trylock");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"unlock");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  int lock()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_mutex_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->lock();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  int trylock()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_mutex_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->trylock();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  int unlock()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,false);
    sc_core::sc_mutex_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->unlock();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_mutex_if_wrapper (dynamic_cast<sc_core::sc_mutex_if * >(intf));
  }
};

class sc_core_sc_semaphore_if_wrapper : public sc_core::sc_semaphore_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_semaphore_if* cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_value
  int cwr_trace_id3; // post
  int cwr_trace_id4; // register_port
  int cwr_trace_id5; // trywait
  int cwr_trace_id6; // wait

 public:
  sc_core_sc_semaphore_if_wrapper(sc_core::sc_semaphore_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_value");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"post");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"trywait");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"wait");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  int get_value() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_semaphore_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->get_value();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  int post()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_semaphore_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->post();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  int trywait()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,false);
    sc_core::sc_semaphore_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->trywait();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  int wait()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    sc_core::sc_semaphore_if* cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->wait();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_semaphore_if_wrapper (dynamic_cast<sc_core::sc_semaphore_if * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< char>  : public sc_core::sc_signal_in_if< char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< char> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const char & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    const char & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const char & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    const char & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< char>  (dynamic_cast<sc_core::sc_signal_in_if< char>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< char>  : public sc_core::sc_signal_write_if< char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< char> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< char>  (dynamic_cast<sc_core::sc_signal_write_if< char>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< char>  : public sc_core::sc_signal_inout_if< char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< char> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< char> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const char * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< char> * cwr_delegate = cwr_delegate_;
    const char * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const char & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    const char & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const char & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    const char & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< char>  (dynamic_cast<sc_core::sc_signal_inout_if< char>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< unsigned char>  : public sc_core::sc_signal_in_if< unsigned char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< unsigned char> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< unsigned char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned char & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    const unsigned char & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const unsigned char & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    const unsigned char & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< unsigned char>  (dynamic_cast<sc_core::sc_signal_in_if< unsigned char>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< unsigned char>  : public sc_core::sc_signal_write_if< unsigned char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< unsigned char> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< unsigned char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const unsigned char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< unsigned char>  (dynamic_cast<sc_core::sc_signal_write_if< unsigned char>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< unsigned char>  : public sc_core::sc_signal_inout_if< unsigned char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< unsigned char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned char * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< unsigned char> * cwr_delegate = cwr_delegate_;
    const unsigned char * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const unsigned char & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    const unsigned char & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const unsigned char & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    const unsigned char & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned char> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const unsigned char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const unsigned char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< unsigned char>  (dynamic_cast<sc_core::sc_signal_inout_if< unsigned char>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< short>  : public sc_core::sc_signal_in_if< short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< short> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const short & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    const short & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const short & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    const short & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< short>  (dynamic_cast<sc_core::sc_signal_in_if< short>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< short>  : public sc_core::sc_signal_write_if< short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< short> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< short>  (dynamic_cast<sc_core::sc_signal_write_if< short>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< short>  : public sc_core::sc_signal_inout_if< short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< short> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< short> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const short * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< short> * cwr_delegate = cwr_delegate_;
    const short * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const short & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    const short & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const short & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    const short & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< short>  (dynamic_cast<sc_core::sc_signal_inout_if< short>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< unsigned short>  : public sc_core::sc_signal_in_if< unsigned short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< unsigned short> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< unsigned short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned short & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    const unsigned short & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const unsigned short & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    const unsigned short & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< unsigned short>  (dynamic_cast<sc_core::sc_signal_in_if< unsigned short>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< unsigned short>  : public sc_core::sc_signal_write_if< unsigned short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< unsigned short> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< unsigned short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const unsigned short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< unsigned short>  (dynamic_cast<sc_core::sc_signal_write_if< unsigned short>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< unsigned short>  : public sc_core::sc_signal_inout_if< unsigned short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< unsigned short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned short * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< unsigned short> * cwr_delegate = cwr_delegate_;
    const unsigned short * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const unsigned short & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    const unsigned short & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const unsigned short & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    const unsigned short & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned short> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const unsigned short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const unsigned short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< unsigned short>  (dynamic_cast<sc_core::sc_signal_inout_if< unsigned short>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< int>  : public sc_core::sc_signal_in_if< int> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< int> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< int>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const int & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    const int & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const int & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    const int & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< int>  (dynamic_cast<sc_core::sc_signal_in_if< int>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< int>  : public sc_core::sc_signal_write_if< int> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< int> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< int>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< int>  (dynamic_cast<sc_core::sc_signal_write_if< int>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< int>  : public sc_core::sc_signal_inout_if< int> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< int> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< int>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< int> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const int * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< int> * cwr_delegate = cwr_delegate_;
    const int * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const int & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    const int & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const int & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    const int & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< int> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< int>  (dynamic_cast<sc_core::sc_signal_inout_if< int>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< unsigned>  : public sc_core::sc_signal_in_if< unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< unsigned> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    const unsigned & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const unsigned & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    const unsigned & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< unsigned>  (dynamic_cast<sc_core::sc_signal_in_if< unsigned>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< unsigned>  : public sc_core::sc_signal_write_if< unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< unsigned>  (dynamic_cast<sc_core::sc_signal_write_if< unsigned>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< unsigned>  : public sc_core::sc_signal_inout_if< unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< unsigned> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< unsigned> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< unsigned> * cwr_delegate = cwr_delegate_;
    const unsigned * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const unsigned & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    const unsigned & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const unsigned & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    const unsigned & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< unsigned>  (dynamic_cast<sc_core::sc_signal_inout_if< unsigned>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< long>  : public sc_core::sc_signal_in_if< long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const long & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    const long & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const long & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    const long & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< long>  (dynamic_cast<sc_core::sc_signal_in_if< long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< long>  : public sc_core::sc_signal_write_if< long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< long>  (dynamic_cast<sc_core::sc_signal_write_if< long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< long>  : public sc_core::sc_signal_inout_if< long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< long> * cwr_delegate = cwr_delegate_;
    const long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const long & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    const long & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const long & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    const long & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< long>  (dynamic_cast<sc_core::sc_signal_inout_if< long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< unsigned long>  : public sc_core::sc_signal_in_if< unsigned long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< unsigned long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< unsigned long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned long & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    const unsigned long & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const unsigned long & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    const unsigned long & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< unsigned long>  (dynamic_cast<sc_core::sc_signal_in_if< unsigned long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< unsigned long>  : public sc_core::sc_signal_write_if< unsigned long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< unsigned long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< unsigned long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const unsigned long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< unsigned long>  (dynamic_cast<sc_core::sc_signal_write_if< unsigned long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< unsigned long>  : public sc_core::sc_signal_inout_if< unsigned long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< unsigned long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< unsigned long> * cwr_delegate = cwr_delegate_;
    const unsigned long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const unsigned long & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    const unsigned long & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const unsigned long & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    const unsigned long & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const unsigned long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const unsigned long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< unsigned long>  (dynamic_cast<sc_core::sc_signal_inout_if< unsigned long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< long long>  : public sc_core::sc_signal_in_if< long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< long long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::int64 & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::int64 & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const sc_dt::int64 & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::int64 & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< long long>  (dynamic_cast<sc_core::sc_signal_in_if< long long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< long long>  : public sc_core::sc_signal_write_if< long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< long long>  (dynamic_cast<sc_core::sc_signal_write_if< long long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< long long>  : public sc_core::sc_signal_inout_if< long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< long long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< long long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const long long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< long long> * cwr_delegate = cwr_delegate_;
    const long long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_dt::int64 & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::int64 & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const sc_dt::int64 & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::int64 & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< long long>  (dynamic_cast<sc_core::sc_signal_inout_if< long long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< unsigned long long>  : public sc_core::sc_signal_in_if< unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::uint64 & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::uint64 & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const sc_dt::uint64 & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::uint64 & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< unsigned long long>  (dynamic_cast<sc_core::sc_signal_in_if< unsigned long long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< unsigned long long>  : public sc_core::sc_signal_write_if< unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const unsigned long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< unsigned long long>  (dynamic_cast<sc_core::sc_signal_write_if< unsigned long long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< unsigned long long>  : public sc_core::sc_signal_inout_if< unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const unsigned long long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    const unsigned long long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_dt::uint64 & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::uint64 & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const sc_dt::uint64 & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    const sc_dt::uint64 & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const unsigned long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const unsigned long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< unsigned long long>  (dynamic_cast<sc_core::sc_signal_inout_if< unsigned long long>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< float>  : public sc_core::sc_signal_in_if< float> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< float> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< float>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const float & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    const float & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const float & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    const float & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< float>  (dynamic_cast<sc_core::sc_signal_in_if< float>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< float>  : public sc_core::sc_signal_write_if< float> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< float> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< float>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const float & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< float>  (dynamic_cast<sc_core::sc_signal_write_if< float>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< float>  : public sc_core::sc_signal_inout_if< float> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< float> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< float>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< float> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const float * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< float> * cwr_delegate = cwr_delegate_;
    const float * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const float & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    const float & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const float & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    const float & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< float> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const float & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const float & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< float>  (dynamic_cast<sc_core::sc_signal_inout_if< float>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< double>  : public sc_core::sc_signal_in_if< double> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< double> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< double>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const double & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    const double & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const double & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    const double & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< double>  (dynamic_cast<sc_core::sc_signal_in_if< double>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< double>  : public sc_core::sc_signal_write_if< double> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< double> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< double>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const double & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< double>  (dynamic_cast<sc_core::sc_signal_write_if< double>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< double>  : public sc_core::sc_signal_inout_if< double> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< double> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< double>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< double> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const double * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< double> * cwr_delegate = cwr_delegate_;
    const double * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const double & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    const double & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const double & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    const double & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< double> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const double & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const double & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< double>  (dynamic_cast<sc_core::sc_signal_inout_if< double>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< sc_core::sc_time>  : public sc_core::sc_signal_in_if< sc_core::sc_time> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< sc_core::sc_time>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_core::sc_time & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_data_ref();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const sc_core::sc_time & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->read();
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< sc_core::sc_time>  (dynamic_cast<sc_core::sc_signal_in_if< sc_core::sc_time>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< sc_core::sc_time>  : public sc_core::sc_signal_write_if< sc_core::sc_time> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< sc_core::sc_time> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< sc_core::sc_time>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const sc_core::sc_time & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_write_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< sc_core::sc_time>  (dynamic_cast<sc_core::sc_signal_write_if< sc_core::sc_time>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< sc_core::sc_time>  : public sc_core::sc_signal_inout_if< sc_core::sc_time> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< sc_core::sc_time>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_core::sc_time * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_clamp_value_ptr();
  }
  const sc_core::sc_time & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_data_ref();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const sc_core::sc_time & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->read();
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const sc_core::sc_time & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    sc_core::sc_signal_write_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const sc_core::sc_time & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< sc_core::sc_time>  (dynamic_cast<sc_core::sc_signal_inout_if< sc_core::sc_time>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< sc_dt::sc_bit>  : public sc_core::sc_signal_in_if< sc_dt::sc_bit> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< sc_dt::sc_bit>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_bit & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_bit & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const sc_dt::sc_bit & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_bit & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< sc_dt::sc_bit>  (dynamic_cast<sc_core::sc_signal_in_if< sc_dt::sc_bit>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< sc_dt::sc_bit>  : public sc_core::sc_signal_write_if< sc_dt::sc_bit> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< sc_dt::sc_bit> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< sc_dt::sc_bit>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const sc_dt::sc_bit & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< sc_dt::sc_bit>  (dynamic_cast<sc_core::sc_signal_write_if< sc_dt::sc_bit>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_bit>  : public sc_core::sc_signal_inout_if< sc_dt::sc_bit> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< sc_dt::sc_bit>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_bit * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_bit * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_dt::sc_bit & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_bit & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const sc_dt::sc_bit & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_bit & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const sc_dt::sc_bit & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const sc_dt::sc_bit & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_bit>  (dynamic_cast<sc_core::sc_signal_inout_if< sc_dt::sc_bit>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< sc_dt::sc_signed>  : public sc_core::sc_signal_in_if< sc_dt::sc_signed> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< sc_dt::sc_signed>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_signed & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_signed & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const sc_dt::sc_signed & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_signed & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< sc_dt::sc_signed>  (dynamic_cast<sc_core::sc_signal_in_if< sc_dt::sc_signed>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< sc_dt::sc_signed>  : public sc_core::sc_signal_write_if< sc_dt::sc_signed> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< sc_dt::sc_signed> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< sc_dt::sc_signed>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const sc_dt::sc_signed & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< sc_dt::sc_signed>  (dynamic_cast<sc_core::sc_signal_write_if< sc_dt::sc_signed>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_signed>  : public sc_core::sc_signal_inout_if< sc_dt::sc_signed> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< sc_dt::sc_signed>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_signed * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_signed * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_dt::sc_signed & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_signed & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const sc_dt::sc_signed & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_signed & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const sc_dt::sc_signed & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const sc_dt::sc_signed & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_signed>  (dynamic_cast<sc_core::sc_signal_inout_if< sc_dt::sc_signed>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_in_if_wrapper< sc_dt::sc_unsigned>  : public sc_core::sc_signal_in_if< sc_dt::sc_unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // event
  int cwr_trace_id3; // getCosimEvent
  int cwr_trace_id4; // getDataLength
  int cwr_trace_id5; // getDataType
  int cwr_trace_id6; // getDataTypeAndSize
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_interface_as_sc_object
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // register_port
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // writeCosim
  int cwr_trace_id16; // writeRaw

 public:
  sc_core_sc_signal_in_if_wrapper(sc_core::sc_signal_in_if< sc_dt::sc_unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeRaw");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_unsigned & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_unsigned & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  const sc_dt::sc_unsigned & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_unsigned & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_in_if_wrapper< sc_dt::sc_unsigned>  (dynamic_cast<sc_core::sc_signal_in_if< sc_dt::sc_unsigned>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_write_if_wrapper< sc_dt::sc_unsigned>  : public sc_core::sc_signal_write_if< sc_dt::sc_unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_write_if< sc_dt::sc_unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // get_writer_policy
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // write

 public:
  sc_core_sc_signal_write_if_wrapper(sc_core::sc_signal_write_if< sc_dt::sc_unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"write");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_signal_write_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void write(const sc_dt::sc_unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_write_if_wrapper< sc_dt::sc_unsigned>  (dynamic_cast<sc_core::sc_signal_write_if< sc_dt::sc_unsigned>  * >(intf));
  }
};

template<>
class sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_unsigned>  : public sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate_;
  int cwr_trace_id0; // allocateDataType
  int cwr_trace_id1; // event
  int cwr_trace_id2; // getCosimEvent
  int cwr_trace_id3; // getDataLength
  int cwr_trace_id4; // getDataType
  int cwr_trace_id5; // getDataTypeAndSize
  int cwr_trace_id6; // get_clamp_value_ptr
  int cwr_trace_id7; // get_data_ref
  int cwr_trace_id8; // get_writer_policy
  int cwr_trace_id9; // read
  int cwr_trace_id10; // readCosim
  int cwr_trace_id11; // readDebugNewValue
  int cwr_trace_id12; // readRaw
  int cwr_trace_id13; // release_clamp
  int cwr_trace_id14; // value_changed_event
  int cwr_trace_id15; // write
  int cwr_trace_id16; // writeCosim
  int cwr_trace_id17; // writeRaw
  int cwr_trace_id18; // write_clamp

 public:
  sc_core_sc_signal_inout_if_wrapper(sc_core::sc_signal_inout_if< sc_dt::sc_unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"allocateDataType");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getCosimEvent");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getDataLength");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"getDataType");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"getDataTypeAndSize");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_data_ref");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_writer_policy");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"read");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"readCosim");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"readDebugNewValue");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"readRaw");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"value_changed_event");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"write");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"writeCosim");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"writeRaw");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  void * allocateDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->allocateDataType();
  }
  bool event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->event();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & getCosimEvent() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getCosimEvent();
  }
  int getDataLength()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    int cwr_tmp = cwr_delegate->getDataLength();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  coware::cwrDataTypeT getDataType()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataType();
  }
  coware::cwrDataTypeT getDataTypeAndSize(int & size_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("size_", size_);
    }
    sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->getDataTypeAndSize(size_);
  }
  const sc_dt::sc_unsigned * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_unsigned * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_dt::sc_unsigned & get_data_ref() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_unsigned & cwr_tmp = cwr_delegate->get_data_ref();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_writer_policy get_writer_policy() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    sc_core::sc_signal_write_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_writer_policy();
  }
  const sc_dt::sc_unsigned & read() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,false);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_unsigned & cwr_tmp = cwr_delegate->read();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readCosim(void * value)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->readCosim(value);
  }
  bool readDebugNewValue(void * cwr_p0) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,false);
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->readDebugNewValue(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void readRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->readRaw(data_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  const sc_core::sc_event & value_changed_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    sc_core::sc_signal_in_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->value_changed_event();
  }
  void write(const sc_dt::sc_unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    sc_core::sc_signal_write_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write(cwr_p0);
  }
  void writeCosim(void * value, void * writer_handle, bool inout)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("inout", inout);
    }
    sc_core::cwr_sc_signal_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->writeCosim(value,writer_handle,inout);
  }
  void writeRaw(void * data_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->writeRaw(data_);
  }
  void write_clamp(const sc_dt::sc_unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_unsigned>  (dynamic_cast<sc_core::sc_signal_inout_if< sc_dt::sc_unsigned>  * >(intf));
  }
};

template <class T >
class snps_sc_signal_clamp_if_wrapper;
template<>
class snps_sc_signal_clamp_if_wrapper< bool>  : public snps::sc::signal_clamp_if< bool> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< bool> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< bool>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const bool * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< bool> * cwr_delegate = cwr_delegate_;
    const bool * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const bool & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< bool> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< bool>  (dynamic_cast<snps::sc::signal_clamp_if< bool>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< sc_dt::sc_logic>  : public snps::sc::signal_clamp_if< sc_dt::sc_logic> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< sc_dt::sc_logic>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const sc_dt::sc_logic * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_logic * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const sc_dt::sc_logic & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_logic> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< sc_dt::sc_logic>  (dynamic_cast<snps::sc::signal_clamp_if< sc_dt::sc_logic>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< char>  : public snps::sc::signal_clamp_if< char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< char> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const char * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< char> * cwr_delegate = cwr_delegate_;
    const char * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< char>  (dynamic_cast<snps::sc::signal_clamp_if< char>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< unsigned char>  : public snps::sc::signal_clamp_if< unsigned char> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< unsigned char> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< unsigned char>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const unsigned char * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< unsigned char> * cwr_delegate = cwr_delegate_;
    const unsigned char * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const unsigned char & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned char> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< unsigned char>  (dynamic_cast<snps::sc::signal_clamp_if< unsigned char>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< short>  : public snps::sc::signal_clamp_if< short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< short> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const short * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< short> * cwr_delegate = cwr_delegate_;
    const short * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< short>  (dynamic_cast<snps::sc::signal_clamp_if< short>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< unsigned short>  : public snps::sc::signal_clamp_if< unsigned short> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< unsigned short> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< unsigned short>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const unsigned short * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< unsigned short> * cwr_delegate = cwr_delegate_;
    const unsigned short * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const unsigned short & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned short> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< unsigned short>  (dynamic_cast<snps::sc::signal_clamp_if< unsigned short>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< int>  : public snps::sc::signal_clamp_if< int> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< int> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< int>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const int * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< int> * cwr_delegate = cwr_delegate_;
    const int * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const int & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< int> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< int>  (dynamic_cast<snps::sc::signal_clamp_if< int>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< unsigned>  : public snps::sc::signal_clamp_if< unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const unsigned * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< unsigned> * cwr_delegate = cwr_delegate_;
    const unsigned * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< unsigned>  (dynamic_cast<snps::sc::signal_clamp_if< unsigned>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< long>  : public snps::sc::signal_clamp_if< long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< long> * cwr_delegate = cwr_delegate_;
    const long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< long>  (dynamic_cast<snps::sc::signal_clamp_if< long>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< unsigned long>  : public snps::sc::signal_clamp_if< unsigned long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< unsigned long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< unsigned long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const unsigned long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< unsigned long> * cwr_delegate = cwr_delegate_;
    const unsigned long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const unsigned long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< unsigned long>  (dynamic_cast<snps::sc::signal_clamp_if< unsigned long>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< long long>  : public snps::sc::signal_clamp_if< long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const long long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< long long> * cwr_delegate = cwr_delegate_;
    const long long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< long long>  (dynamic_cast<snps::sc::signal_clamp_if< long long>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< unsigned long long>  : public snps::sc::signal_clamp_if< unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const unsigned long long * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    const unsigned long long * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const unsigned long long & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< unsigned long long> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< unsigned long long>  (dynamic_cast<snps::sc::signal_clamp_if< unsigned long long>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< float>  : public snps::sc::signal_clamp_if< float> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< float> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< float>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const float * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< float> * cwr_delegate = cwr_delegate_;
    const float * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const float & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< float> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< float>  (dynamic_cast<snps::sc::signal_clamp_if< float>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< double>  : public snps::sc::signal_clamp_if< double> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< double> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< double>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const double * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< double> * cwr_delegate = cwr_delegate_;
    const double * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const double & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< double> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< double>  (dynamic_cast<snps::sc::signal_clamp_if< double>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< sc_core::sc_time>  : public snps::sc::signal_clamp_if< sc_core::sc_time> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< sc_core::sc_time>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const sc_core::sc_time * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_clamp_value_ptr();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const sc_core::sc_time & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    snps::sc::signal_clamp_if< sc_core::sc_time> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< sc_core::sc_time>  (dynamic_cast<snps::sc::signal_clamp_if< sc_core::sc_time>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< sc_dt::sc_bit>  : public snps::sc::signal_clamp_if< sc_dt::sc_bit> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< sc_dt::sc_bit>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const sc_dt::sc_bit * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_bit * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const sc_dt::sc_bit & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_bit> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< sc_dt::sc_bit>  (dynamic_cast<snps::sc::signal_clamp_if< sc_dt::sc_bit>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< sc_dt::sc_signed>  : public snps::sc::signal_clamp_if< sc_dt::sc_signed> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< sc_dt::sc_signed>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const sc_dt::sc_signed * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_signed * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const sc_dt::sc_signed & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_signed> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< sc_dt::sc_signed>  (dynamic_cast<snps::sc::signal_clamp_if< sc_dt::sc_signed>  * >(intf));
  }
};

template<>
class snps_sc_signal_clamp_if_wrapper< sc_dt::sc_unsigned>  : public snps::sc::signal_clamp_if< sc_dt::sc_unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_clamp_value_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port
  int cwr_trace_id4; // release_clamp
  int cwr_trace_id5; // write_clamp

 public:
  snps_sc_signal_clamp_if_wrapper(snps::sc::signal_clamp_if< sc_dt::sc_unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_clamp_value_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"write_clamp");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  const sc_dt::sc_unsigned * get_clamp_value_ptr() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    const sc_dt::sc_unsigned * cwr_tmp = cwr_delegate->get_clamp_value_ptr();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp();
  }
  void write_clamp(const sc_dt::sc_unsigned & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    snps::sc::signal_clamp_if< sc_dt::sc_unsigned> * cwr_delegate = cwr_delegate_;
    cwr_delegate->write_clamp(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new snps_sc_signal_clamp_if_wrapper< sc_dt::sc_unsigned>  (dynamic_cast<snps::sc::signal_clamp_if< sc_dt::sc_unsigned>  * >(intf));
  }
};

template <class T >
class tlm_tlm_write_if_wrapper;
template <class T >
class tlm_tlm_delayed_write_if_wrapper;
template <class T >
class tlm_tlm_analysis_if_wrapper;
template <class T >
class tlm_tlm_delayed_analysis_if_wrapper;
template <class REQ,class RSP >
class tlm_tlm_transport_if_wrapper;
template <class T >
class tlm_tlm_blocking_get_if_wrapper;
template <class T >
class tlm_tlm_blocking_put_if_wrapper;
template <class T >
class tlm_tlm_nonblocking_get_if_wrapper;
template <class T >
class tlm_tlm_nonblocking_put_if_wrapper;
template <class T >
class tlm_tlm_get_if_wrapper;
template <class T >
class tlm_tlm_put_if_wrapper;
template <class T >
class tlm_tlm_blocking_peek_if_wrapper;
template <class T >
class tlm_tlm_nonblocking_peek_if_wrapper;
template <class T >
class tlm_tlm_peek_if_wrapper;
template <class T >
class tlm_tlm_blocking_get_peek_if_wrapper;
template <class T >
class tlm_tlm_nonblocking_get_peek_if_wrapper;
template <class T >
class tlm_tlm_get_peek_if_wrapper;
template <class T >
class tlm_tlm_fifo_debug_if_wrapper;
template <class T >
class tlm_tlm_fifo_put_if_wrapper;
template <class T >
class tlm_tlm_fifo_get_if_wrapper;
class tlm_tlm_fifo_config_size_if_wrapper : public tlm::tlm_fifo_config_size_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_fifo_config_size_if* cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // nb_bound
  int cwr_trace_id3; // nb_expand
  int cwr_trace_id4; // nb_reduce
  int cwr_trace_id5; // nb_unbound
  int cwr_trace_id6; // register_port

 public:
  tlm_tlm_fifo_config_size_if_wrapper(tlm::tlm_fifo_config_size_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"nb_bound");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"nb_expand");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"nb_reduce");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"nb_unbound");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  bool nb_bound(unsigned n)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,false);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("n", n);
    }
    tlm::tlm_fifo_config_size_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->nb_bound(n);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void nb_expand(unsigned n)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("n", n);
    }
    tlm::tlm_fifo_config_size_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->nb_expand(n);
  }
  bool nb_reduce(unsigned n)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,false);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("n", n);
    }
    tlm::tlm_fifo_config_size_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->nb_reduce(n);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void nb_unbound(unsigned n)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("n", n);
    }
    tlm::tlm_fifo_config_size_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->nb_unbound(n);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_fifo_config_size_if_wrapper (dynamic_cast<tlm::tlm_fifo_config_size_if * >(intf));
  }
};

template <class REQ,class RSP >
class tlm_tlm_blocking_master_if_wrapper;
template <class REQ,class RSP >
class tlm_tlm_blocking_slave_if_wrapper;
template <class REQ,class RSP >
class tlm_tlm_nonblocking_master_if_wrapper;
template <class REQ,class RSP >
class tlm_tlm_nonblocking_slave_if_wrapper;
template <class REQ,class RSP >
class tlm_tlm_master_if_wrapper;
template <class REQ,class RSP >
class tlm_tlm_slave_if_wrapper;
template <class TYPES >
class tlm_tlm_bw_transport_if_wrapper;
template <class TYPES >
class tlm_tlm_fw_transport_if_wrapper;
template <class TRANS,class PHASE >
class tlm_tlm_fw_nonblocking_transport_if_wrapper;
template <class TRANS,class PHASE >
class tlm_tlm_bw_nonblocking_transport_if_wrapper;
template <class TRANS >
class tlm_tlm_blocking_transport_if_wrapper;
template <class TRANS >
class tlm_tlm_fw_direct_mem_if_wrapper;
class tlm_tlm_bw_direct_mem_if_wrapper : public tlm::tlm_bw_direct_mem_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_bw_direct_mem_if* cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // invalidate_direct_mem_ptr
  int cwr_trace_id3; // register_port

 public:
  tlm_tlm_bw_direct_mem_if_wrapper(tlm::tlm_bw_direct_mem_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"invalidate_direct_mem_ptr");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("start_range", start_range);
      cwr_dummy->record_attribute("end_range", end_range);
    }
    tlm::tlm_bw_direct_mem_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->invalidate_direct_mem_ptr(start_range,end_range);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_bw_direct_mem_if_wrapper (dynamic_cast<tlm::tlm_bw_direct_mem_if * >(intf));
  }
};

template <class TRANS >
class tlm_tlm_transport_dbg_if_wrapper;
template<>
class tlm_tlm_fw_nonblocking_transport_if_wrapper< tlm::tlm_generic_payload, tlm::tlm_phase>  : public tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // nb_transport_fw
  int cwr_trace_id3; // register_port

 public:
  tlm_tlm_fw_nonblocking_transport_if_wrapper(tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"nb_transport_fw");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_base_protocol_types::tlm_phase_type & phase, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->nb_transport_fw(trans,phase,t);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_fw_nonblocking_transport_if_wrapper< tlm::tlm_generic_payload, tlm::tlm_phase>  (dynamic_cast<tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase>  * >(intf));
  }
};

template<>
class tlm_tlm_blocking_transport_if_wrapper< tlm::tlm_generic_payload>  : public tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload> * cwr_delegate_;
  int cwr_trace_id0; // b_transport
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port

 public:
  tlm_tlm_blocking_transport_if_wrapper(tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"b_transport");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  void b_transport(tlm::tlm_base_protocol_types::tlm_payload_type & trans, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    cwr_delegate->b_transport(trans,t);
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_blocking_transport_if_wrapper< tlm::tlm_generic_payload>  (dynamic_cast<tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload>  * >(intf));
  }
};

template<>
class tlm_tlm_fw_direct_mem_if_wrapper< tlm::tlm_generic_payload>  : public tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_direct_mem_ptr
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // register_port

 public:
  tlm_tlm_fw_direct_mem_if_wrapper(tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_direct_mem_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  bool get_direct_mem_ptr(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_dmi & dmi_data)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->get_direct_mem_ptr(trans,dmi_data);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_fw_direct_mem_if_wrapper< tlm::tlm_generic_payload>  (dynamic_cast<tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload>  * >(intf));
  }
};

template<>
class tlm_tlm_transport_dbg_if_wrapper< tlm::tlm_generic_payload>  : public tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport_dbg

 public:
  tlm_tlm_transport_dbg_if_wrapper(tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport_dbg");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  unsigned transport_dbg(tlm::tlm_base_protocol_types::tlm_payload_type & trans)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    unsigned cwr_tmp = cwr_delegate->transport_dbg(trans);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_dbg_if_wrapper< tlm::tlm_generic_payload>  (dynamic_cast<tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload>  * >(intf));
  }
};

template<>
class tlm_tlm_fw_transport_if_wrapper< tlm::tlm_base_protocol_types>  : public tlm::tlm_fw_transport_if< tlm::tlm_base_protocol_types> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_fw_transport_if< tlm::tlm_base_protocol_types> * cwr_delegate_;
  int cwr_trace_id0; // b_transport
  int cwr_trace_id1; // get_direct_mem_ptr
  int cwr_trace_id2; // nb_transport_fw
  int cwr_trace_id3; // transport_dbg

 public:
  tlm_tlm_fw_transport_if_wrapper(tlm::tlm_fw_transport_if< tlm::tlm_base_protocol_types>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"b_transport");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_direct_mem_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"nb_transport_fw");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport_dbg");
    }
  }

  void b_transport(tlm::tlm_base_protocol_types::tlm_payload_type & trans, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    cwr_delegate->b_transport(trans,t);
  }
  bool get_direct_mem_ptr(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_dmi & dmi_data)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->get_direct_mem_ptr(trans,dmi_data);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_base_protocol_types::tlm_phase_type & phase, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->nb_transport_fw(trans,phase,t);
  }
  unsigned transport_dbg(tlm::tlm_base_protocol_types::tlm_payload_type & trans)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    unsigned cwr_tmp = cwr_delegate->transport_dbg(trans);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_fw_transport_if_wrapper< tlm::tlm_base_protocol_types>  (dynamic_cast<tlm::tlm_fw_transport_if< tlm::tlm_base_protocol_types>  * >(intf));
  }
};

class tlm_tlm_fw_transport_if_export_dummy_wrapper : public tlm::tlm_fw_transport_if_export_dummy, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_fw_transport_if_export_dummy* cwr_delegate_;
  int cwr_trace_id0; // b_transport
  int cwr_trace_id1; // get_direct_mem_ptr
  int cwr_trace_id2; // nb_transport_fw
  int cwr_trace_id3; // transport_dbg

 public:
  tlm_tlm_fw_transport_if_export_dummy_wrapper(tlm::tlm_fw_transport_if_export_dummy *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"b_transport");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_direct_mem_ptr");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"nb_transport_fw");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport_dbg");
    }
  }

  void b_transport(tlm::tlm_base_protocol_types::tlm_payload_type & trans, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    cwr_delegate->b_transport(trans,t);
  }
  bool get_direct_mem_ptr(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_dmi & dmi_data)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,false);
    tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->get_direct_mem_ptr(trans,dmi_data);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_base_protocol_types::tlm_phase_type & phase, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->nb_transport_fw(trans,phase,t);
  }
  unsigned transport_dbg(tlm::tlm_base_protocol_types::tlm_payload_type & trans)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload> * cwr_delegate = cwr_delegate_;
    unsigned cwr_tmp = cwr_delegate->transport_dbg(trans);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_fw_transport_if_export_dummy_wrapper (dynamic_cast<tlm::tlm_fw_transport_if_export_dummy * >(intf));
  }
};

template<>
class tlm_tlm_bw_nonblocking_transport_if_wrapper< tlm::tlm_generic_payload, tlm::tlm_phase>  : public tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // nb_transport_bw
  int cwr_trace_id3; // register_port

 public:
  tlm_tlm_bw_nonblocking_transport_if_wrapper(tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"nb_transport_bw");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_base_protocol_types::tlm_phase_type & phase, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->nb_transport_bw(trans,phase,t);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_bw_nonblocking_transport_if_wrapper< tlm::tlm_generic_payload, tlm::tlm_phase>  (dynamic_cast<tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase>  * >(intf));
  }
};

template<>
class tlm_tlm_bw_transport_if_wrapper< tlm::tlm_base_protocol_types>  : public tlm::tlm_bw_transport_if< tlm::tlm_base_protocol_types> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_bw_transport_if< tlm::tlm_base_protocol_types> * cwr_delegate_;
  int cwr_trace_id0; // invalidate_direct_mem_ptr
  int cwr_trace_id1; // nb_transport_bw

 public:
  tlm_tlm_bw_transport_if_wrapper(tlm::tlm_bw_transport_if< tlm::tlm_base_protocol_types>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"invalidate_direct_mem_ptr");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"nb_transport_bw");
    }
  }

  void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("start_range", start_range);
      cwr_dummy->record_attribute("end_range", end_range);
    }
    tlm::tlm_bw_direct_mem_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->invalidate_direct_mem_ptr(start_range,end_range);
  }
  tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_base_protocol_types::tlm_phase_type & phase, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->nb_transport_bw(trans,phase,t);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_bw_transport_if_wrapper< tlm::tlm_base_protocol_types>  (dynamic_cast<tlm::tlm_bw_transport_if< tlm::tlm_base_protocol_types>  * >(intf));
  }
};

class tlm_tlm_bw_transport_if_export_dummy_wrapper : public tlm::tlm_bw_transport_if_export_dummy, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_bw_transport_if_export_dummy* cwr_delegate_;
  int cwr_trace_id0; // invalidate_direct_mem_ptr
  int cwr_trace_id1; // nb_transport_bw

 public:
  tlm_tlm_bw_transport_if_export_dummy_wrapper(tlm::tlm_bw_transport_if_export_dummy *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"invalidate_direct_mem_ptr");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"nb_transport_bw");
    }
  }

  void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("start_range", start_range);
      cwr_dummy->record_attribute("end_range", end_range);
    }
    tlm::tlm_bw_direct_mem_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->invalidate_direct_mem_ptr(start_range,end_range);
  }
  tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_base_protocol_types::tlm_payload_type & trans, tlm::tlm_base_protocol_types::tlm_phase_type & phase, sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->nb_transport_bw(trans,phase,t);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_bw_transport_if_export_dummy_wrapper (dynamic_cast<tlm::tlm_bw_transport_if_export_dummy * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< unsigned, unsigned> , PVResp< unsigned> >  : public tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned, unsigned>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned>  transport(const PVReq< unsigned, unsigned>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< unsigned, unsigned> , PVResp< unsigned> >  (dynamic_cast<tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> >  : public tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned long long, unsigned>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned long long>  transport(const PVReq< unsigned long long, unsigned>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> >  (dynamic_cast<tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > >  : public tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 128> >  transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > >  (dynamic_cast<tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > >  : public tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 256> >  transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > >  (dynamic_cast<tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > >  : public tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 512> >  transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > >  (dynamic_cast<tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< unsigned, unsigned long long> , PVResp< unsigned> >  : public tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned, unsigned long long>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned>  transport(const PVReq< unsigned, unsigned long long>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< unsigned, unsigned long long> , PVResp< unsigned> >  (dynamic_cast<tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> >  : public tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned long long, unsigned long long>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned long long>  transport(const PVReq< unsigned long long, unsigned long long>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> >  (dynamic_cast<tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > >  : public tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 128> >  transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > >  (dynamic_cast<tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > >  : public tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 256> >  transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > >  (dynamic_cast<tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > >  * >(intf));
  }
};

template<>
class tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > >  : public tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  tlm_tlm_transport_if_wrapper(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > >  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 512> >  transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(cwr_p0);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > >  (dynamic_cast<tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > >  * >(intf));
  }
};

template <class DT,class AT >
class PVTarget_process_wrapper;
template <class DT,class AT >
class PV_if_wrapper;
class PVDecoder_if_base_wrapper : public PVDecoder_if_base, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PVDecoder_if_base* cwr_delegate_;
  int cwr_trace_id0; // decode
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // get_interface_as_sc_object
  int cwr_trace_id3; // init
  int cwr_trace_id4; // register_port

 public:
  PVDecoder_if_base_wrapper(PVDecoder_if_base *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"decode");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"init");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"register_port");
    }
  }

  PVDecoderResult * decode(unsigned long long & addr)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("addr", addr);
    }
    PVDecoder_if_base* cwr_delegate = cwr_delegate_;
    return cwr_delegate->decode(addr);
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void init(PVNode_base * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    PVDecoder_if_base* cwr_delegate = cwr_delegate_;
    cwr_delegate->init(cwr_p0);
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PVDecoder_if_base_wrapper (dynamic_cast<PVDecoder_if_base * >(intf));
  }
};

template <unsigned address_width,unsigned data_width >
class scml_memory_pv_if_wrapper;
template<>
class PV_if_wrapper< unsigned, unsigned>  : public PV_if< unsigned, unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< unsigned, unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< unsigned, unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned, unsigned>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned>  transport(const PVReq< unsigned, unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned, unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< unsigned, unsigned>  (dynamic_cast<PV_if< unsigned, unsigned>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 32U, 32U>  : public scml_memory_pv_if< 32U, 32U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 32U, 32U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 32U, 32U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned, unsigned>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned>  transport(const PVReq< unsigned, unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned, unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 32U, 32U>  (dynamic_cast<scml_memory_pv_if< 32U, 32U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< unsigned long long, unsigned>  : public PV_if< unsigned long long, unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< unsigned long long, unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< unsigned long long, unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned long long, unsigned>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned long long>  transport(const PVReq< unsigned long long, unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned long long, unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< unsigned long long, unsigned>  (dynamic_cast<PV_if< unsigned long long, unsigned>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 32U, 64U>  : public scml_memory_pv_if< 32U, 64U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 32U, 64U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 32U, 64U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned long long, unsigned>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned long long>  transport(const PVReq< unsigned long long, unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned long long, unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 32U, 64U>  (dynamic_cast<scml_memory_pv_if< 32U, 64U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< sc_dt::sc_biguint< 128> , unsigned>  : public PV_if< sc_dt::sc_biguint< 128> , unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< sc_dt::sc_biguint< 128> , unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< sc_dt::sc_biguint< 128> , unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 128> >  transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 128> , unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< sc_dt::sc_biguint< 128> , unsigned>  (dynamic_cast<PV_if< sc_dt::sc_biguint< 128> , unsigned>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 32U, 128U>  : public scml_memory_pv_if< 32U, 128U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 32U, 128U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 32U, 128U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 128> >  transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 128> , unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 32U, 128U>  (dynamic_cast<scml_memory_pv_if< 32U, 128U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< sc_dt::sc_biguint< 256> , unsigned>  : public PV_if< sc_dt::sc_biguint< 256> , unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< sc_dt::sc_biguint< 256> , unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< sc_dt::sc_biguint< 256> , unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 256> >  transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 256> , unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< sc_dt::sc_biguint< 256> , unsigned>  (dynamic_cast<PV_if< sc_dt::sc_biguint< 256> , unsigned>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 32U, 256U>  : public scml_memory_pv_if< 32U, 256U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 32U, 256U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 32U, 256U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 256> >  transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 256> , unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 32U, 256U>  (dynamic_cast<scml_memory_pv_if< 32U, 256U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< sc_dt::sc_biguint< 512> , unsigned>  : public PV_if< sc_dt::sc_biguint< 512> , unsigned> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< sc_dt::sc_biguint< 512> , unsigned> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< sc_dt::sc_biguint< 512> , unsigned>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 512> >  transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 512> , unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< sc_dt::sc_biguint< 512> , unsigned>  (dynamic_cast<PV_if< sc_dt::sc_biguint< 512> , unsigned>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 32U, 512U>  : public scml_memory_pv_if< 32U, 512U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 32U, 512U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 32U, 512U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 512> >  transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 512> , unsigned> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 32U, 512U>  (dynamic_cast<scml_memory_pv_if< 32U, 512U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< unsigned, unsigned long long>  : public PV_if< unsigned, unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< unsigned, unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< unsigned, unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned, unsigned long long>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned>  transport(const PVReq< unsigned, unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned, unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< unsigned, unsigned long long>  (dynamic_cast<PV_if< unsigned, unsigned long long>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 64U, 32U>  : public scml_memory_pv_if< 64U, 32U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 64U, 32U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 64U, 32U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned, unsigned long long>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned>  transport(const PVReq< unsigned, unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned, unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 64U, 32U>  (dynamic_cast<scml_memory_pv_if< 64U, 32U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< unsigned long long, unsigned long long>  : public PV_if< unsigned long long, unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< unsigned long long, unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< unsigned long long, unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned long long, unsigned long long>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned long long>  transport(const PVReq< unsigned long long, unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned long long, unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< unsigned long long, unsigned long long>  (dynamic_cast<PV_if< unsigned long long, unsigned long long>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 64U, 64U>  : public scml_memory_pv_if< 64U, 64U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 64U, 64U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 64U, 64U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< unsigned long long, unsigned long long>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< unsigned long long>  transport(const PVReq< unsigned long long, unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< unsigned long long, unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 64U, 64U>  (dynamic_cast<scml_memory_pv_if< 64U, 64U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< sc_dt::sc_biguint< 128> , unsigned long long>  : public PV_if< sc_dt::sc_biguint< 128> , unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< sc_dt::sc_biguint< 128> , unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< sc_dt::sc_biguint< 128> , unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 128> >  transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 128> , unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< sc_dt::sc_biguint< 128> , unsigned long long>  (dynamic_cast<PV_if< sc_dt::sc_biguint< 128> , unsigned long long>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 64U, 128U>  : public scml_memory_pv_if< 64U, 128U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 64U, 128U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 64U, 128U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 128> >  transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 128> , unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 64U, 128U>  (dynamic_cast<scml_memory_pv_if< 64U, 128U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< sc_dt::sc_biguint< 256> , unsigned long long>  : public PV_if< sc_dt::sc_biguint< 256> , unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< sc_dt::sc_biguint< 256> , unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< sc_dt::sc_biguint< 256> , unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 256> >  transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 256> , unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< sc_dt::sc_biguint< 256> , unsigned long long>  (dynamic_cast<PV_if< sc_dt::sc_biguint< 256> , unsigned long long>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 64U, 256U>  : public scml_memory_pv_if< 64U, 256U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 64U, 256U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 64U, 256U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 256> >  transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 256> , unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 64U, 256U>  (dynamic_cast<scml_memory_pv_if< 64U, 256U>  * >(intf));
  }
};

template<>
class PV_if_wrapper< sc_dt::sc_biguint< 512> , unsigned long long>  : public PV_if< sc_dt::sc_biguint< 512> , unsigned long long> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  PV_if< sc_dt::sc_biguint< 512> , unsigned long long> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  PV_if_wrapper(PV_if< sc_dt::sc_biguint< 512> , unsigned long long>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 512> >  transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 512> , unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new PV_if_wrapper< sc_dt::sc_biguint< 512> , unsigned long long>  (dynamic_cast<PV_if< sc_dt::sc_biguint< 512> , unsigned long long>  * >(intf));
  }
};

template<>
class scml_memory_pv_if_wrapper< 64U, 512U>  : public scml_memory_pv_if< 64U, 512U> , public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_memory_pv_if< 64U, 512U> * cwr_delegate_;
  int cwr_trace_id0; // default_event
  int cwr_trace_id1; // get_interface_as_sc_object
  int cwr_trace_id2; // register_port
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport

 public:
  scml_memory_pv_if_wrapper(scml_memory_pv_if< 64U, 512U>  *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  PVResp< sc_dt::sc_biguint< 512> >  transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & arg_Req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    PV_if< sc_dt::sc_biguint< 512> , unsigned long long> * cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(arg_Req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_memory_pv_if_wrapper< 64U, 512U>  (dynamic_cast<scml_memory_pv_if< 64U, 512U>  * >(intf));
  }
};

class scml_clock_if_wrapper : public scml_clock_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_clock_if* cwr_delegate_;
  int cwr_trace_id0; // check_at_tick
  int cwr_trace_id1; // default_event
  int cwr_trace_id2; // disable
  int cwr_trace_id3; // disabled
  int cwr_trace_id4; // enable
  int cwr_trace_id5; // get_clamp
  int cwr_trace_id6; // get_clock_count
  int cwr_trace_id7; // get_configurator
  int cwr_trace_id8; // get_duty_cycle
  int cwr_trace_id9; // get_interface_as_sc_object
  int cwr_trace_id10; // get_next_edge_offset
  int cwr_trace_id11; // get_next_tick_data
  int cwr_trace_id12; // get_period
  int cwr_trace_id13; // get_period_multiplier
  int cwr_trace_id14; // get_posedge_first
  int cwr_trace_id15; // get_start_time
  int cwr_trace_id16; // get_tick_callback_engine
  int cwr_trace_id17; // get_tick_count
  int cwr_trace_id18; // get_tick_count
  int cwr_trace_id19; // get_tick_time
  int cwr_trace_id20; // is_master
  int cwr_trace_id21; // name
  int cwr_trace_id22; // register_observer
  int cwr_trace_id23; // register_port
  int cwr_trace_id24; // release_clamp
  int cwr_trace_id25; // running
  int cwr_trace_id26; // set_duty_cycle
  int cwr_trace_id27; // set_period
  int cwr_trace_id28; // set_period_multiplier
  int cwr_trace_id29; // set_posedge_first
  int cwr_trace_id30; // set_start_time
  int cwr_trace_id31; // unregister_observer

 public:
  scml_clock_if_wrapper(scml_clock_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"check_at_tick");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"default_event");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"disable");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"disabled");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"enable");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"get_clamp");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"get_clock_count");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"get_configurator");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"get_duty_cycle");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"get_next_edge_offset");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"get_next_tick_data");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"get_period");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"get_period_multiplier");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"get_posedge_first");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"get_start_time");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"get_tick_callback_engine");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"get_tick_count");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"get_tick_count");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"get_tick_time");
      cwr_trace_id20 = cwr_trace_->add_trace(this,"is_master");
      cwr_trace_id21 = cwr_trace_->add_trace(this,"name");
      cwr_trace_id22 = cwr_trace_->add_trace(this,"register_observer");
      cwr_trace_id23 = cwr_trace_->add_trace(this,"register_port");
      cwr_trace_id24 = cwr_trace_->add_trace(this,"release_clamp");
      cwr_trace_id25 = cwr_trace_->add_trace(this,"running");
      cwr_trace_id26 = cwr_trace_->add_trace(this,"set_duty_cycle");
      cwr_trace_id27 = cwr_trace_->add_trace(this,"set_period");
      cwr_trace_id28 = cwr_trace_->add_trace(this,"set_period_multiplier");
      cwr_trace_id29 = cwr_trace_->add_trace(this,"set_posedge_first");
      cwr_trace_id30 = cwr_trace_->add_trace(this,"set_start_time");
      cwr_trace_id31 = cwr_trace_->add_trace(this,"unregister_observer");
    }
  }

  bool check_at_tick() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->check_at_tick();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const sc_core::sc_event & default_event() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->default_event();
  }
  void disable()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->disable();
  }
  bool disabled() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->disabled();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void enable()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->enable();
  }
  n_scml_clock::clamp_if * get_clamp()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_clamp();
  }
  sc_dt::uint64 get_clock_count() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    sc_dt::uint64 cwr_tmp = cwr_delegate->get_clock_count();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  n_scml_clock::configurator * get_configurator() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_configurator();
  }
  double get_duty_cycle() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,false);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    double cwr_tmp = cwr_delegate->get_duty_cycle();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,true);
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  sc_core::sc_time get_next_edge_offset(bool pos_edge) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("pos_edge", pos_edge);
    }
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_next_edge_offset(pos_edge);
  }
  void get_next_tick_data(const sc_core::sc_time & delay, unsigned long long & count, sc_core::sc_time & time) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("count", count);
    }
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->get_next_tick_data(delay,count,time);
  }
  sc_core::sc_time get_period() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_period();
  }
  double get_period_multiplier() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    double cwr_tmp = cwr_delegate->get_period_multiplier();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  bool get_posedge_first() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,false);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->get_posedge_first();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_time get_start_time() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    sc_core::sc_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_start_time();
  }
  n_scml_clock::tick_callback_engine * get_tick_callback_engine() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_tick_callback_engine();
  }
  unsigned long long get_tick_count(const sc_core::sc_time & delay) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    unsigned long long cwr_tmp = cwr_delegate->get_tick_count(delay);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  unsigned long long get_tick_count() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    unsigned long long cwr_tmp = cwr_delegate->get_tick_count();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  sc_core::sc_time get_tick_time(long long clock_ticks_to_skip) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("clock_ticks_to_skip", clock_ticks_to_skip);
    }
    scml_clock_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_tick_time(clock_ticks_to_skip);
  }
  bool is_master() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id20,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->is_master();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  const char * name() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id21,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    const char * cwr_tmp = cwr_delegate->name();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  bool register_observer(scml_clock_observer * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id22,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->register_observer(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void register_port(sc_core::sc_port_base & port_, const char * if_typename_)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id23,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("if_typename_", *if_typename_);
    }
    sc_core::sc_interface* cwr_delegate = cwr_delegate_;
    cwr_delegate->register_port(port_,if_typename_);
  }
  void release_clamp(n_scml_clock::clamp_if * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id24,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->release_clamp(cwr_p0);
  }
  bool running() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id25,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->running();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  void set_duty_cycle(double d)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id26,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("d", d);
    }
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->set_duty_cycle(d);
  }
  void set_period(const sc_core::sc_time & t)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id27,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->set_period(t);
  }
  void set_period_multiplier(double cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id28,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("cwr_p0", cwr_p0);
    }
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->set_period_multiplier(cwr_p0);
  }
  void set_posedge_first(bool posedge_first)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id29,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("posedge_first", posedge_first);
    }
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->set_posedge_first(posedge_first);
  }
  void set_start_time(const sc_core::sc_time & cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id30,true);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->set_start_time(cwr_p0);
  }
  bool unregister_observer(scml_clock_observer * cwr_p0)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id31,false);
    scml_clock_if* cwr_delegate = cwr_delegate_;
    bool cwr_tmp = cwr_delegate->unregister_observer(cwr_p0);
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", cwr_tmp);
    }
    return cwr_tmp;
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_clock_if_wrapper (dynamic_cast<scml_clock_if * >(intf));
  }
};

class scml_transport_if_wrapper : public scml_transport_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_transport_if* cwr_delegate_;
  int cwr_trace_id0; // transport
  int cwr_trace_id1; // transport
  int cwr_trace_id2; // transport
  int cwr_trace_id3; // transport
  int cwr_trace_id4; // transport
  int cwr_trace_id5; // transport
  int cwr_trace_id6; // transport
  int cwr_trace_id7; // transport
  int cwr_trace_id8; // transport
  int cwr_trace_id9; // transport
  int cwr_trace_id10; // transport
  int cwr_trace_id11; // transport
  int cwr_trace_id12; // transport
  int cwr_trace_id13; // transport
  int cwr_trace_id14; // transport
  int cwr_trace_id15; // transport
  int cwr_trace_id16; // transport
  int cwr_trace_id17; // transport
  int cwr_trace_id18; // transport
  int cwr_trace_id19; // transport

 public:
  scml_transport_if_wrapper(scml_transport_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"transport");
    }
  }

  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned long long, unsigned long long>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned, unsigned long long>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned long long, unsigned>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned, unsigned>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  scml_memory_pv_if< 64U, 512U> ::response_type transport(const scml_memory_pv_if< 64U, 512U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 256U> ::response_type transport(const scml_memory_pv_if< 64U, 256U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 128U> ::response_type transport(const scml_memory_pv_if< 64U, 128U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 64U> ::response_type transport(const scml_memory_pv_if< 64U, 64U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 32U> ::response_type transport(const scml_memory_pv_if< 64U, 32U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 512U> ::response_type transport(const scml_memory_pv_if< 32U, 512U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 256U> ::response_type transport(const scml_memory_pv_if< 32U, 256U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 128U> ::response_type transport(const scml_memory_pv_if< 32U, 128U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 64U> ::response_type transport(const scml_memory_pv_if< 32U, 64U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 32U> ::response_type transport(const scml_memory_pv_if< 32U, 32U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_transport_if_wrapper (dynamic_cast<scml_transport_if * >(intf));
  }
};

class scml_mapable_if_wrapper : public scml_mapable_if, public trace_interface_settings  {
  mutable cwr_thread_trace *cwr_trace_;
  scml_mapable_if* cwr_delegate_;
  int cwr_trace_id0; // getName
  int cwr_trace_id1; // getPVInterfaceType
  int cwr_trace_id2; // getReadAccessDescriptor
  int cwr_trace_id3; // getWriteAccessDescriptor
  int cwr_trace_id4; // get_interface_as_sc_object
  int cwr_trace_id5; // setPVInterfaceType
  int cwr_trace_id6; // transport
  int cwr_trace_id7; // transport
  int cwr_trace_id8; // transport
  int cwr_trace_id9; // transport
  int cwr_trace_id10; // transport
  int cwr_trace_id11; // transport
  int cwr_trace_id12; // transport
  int cwr_trace_id13; // transport
  int cwr_trace_id14; // transport
  int cwr_trace_id15; // transport
  int cwr_trace_id16; // transport
  int cwr_trace_id17; // transport
  int cwr_trace_id18; // transport
  int cwr_trace_id19; // transport
  int cwr_trace_id20; // transport
  int cwr_trace_id21; // transport
  int cwr_trace_id22; // transport
  int cwr_trace_id23; // transport
  int cwr_trace_id24; // transport
  int cwr_trace_id25; // transport

 public:
  scml_mapable_if_wrapper(scml_mapable_if *delegate) : trace_interface_settings(delegate), cwr_delegate_(delegate) {
    cwr_trace_ =  cwr_thread_trace::instance();
    if (cwr_trace_) {
      cwr_trace_id0 = cwr_trace_->add_trace(this,"getName");
      cwr_trace_id1 = cwr_trace_->add_trace(this,"getPVInterfaceType");
      cwr_trace_id2 = cwr_trace_->add_trace(this,"getReadAccessDescriptor");
      cwr_trace_id3 = cwr_trace_->add_trace(this,"getWriteAccessDescriptor");
      cwr_trace_id4 = cwr_trace_->add_trace(this,"get_interface_as_sc_object");
      cwr_trace_id5 = cwr_trace_->add_trace(this,"setPVInterfaceType");
      cwr_trace_id6 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id7 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id8 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id9 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id10 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id11 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id12 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id13 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id14 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id15 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id16 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id17 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id18 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id19 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id20 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id21 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id22 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id23 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id24 = cwr_trace_->add_trace(this,"transport");
      cwr_trace_id25 = cwr_trace_->add_trace(this,"transport");
    }
  }

  const char * getName() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id0,false);
    scml_mapable_if* cwr_delegate = cwr_delegate_;
    const char * cwr_tmp = cwr_delegate->getName();
    cwr_dummy.end_entry();
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("return_val", *cwr_tmp);
    }
    return cwr_tmp;
  }
  scml::PVInterfaceType getPVInterfaceType() const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id1,true);
    scml_mapable_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getPVInterfaceType();
  }
  scml_memory_access_descriptor getReadAccessDescriptor(sc_dt::uint64 address) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id2,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("address", address);
    }
    scml_mapable_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getReadAccessDescriptor(address);
  }
  scml_memory_access_descriptor getWriteAccessDescriptor(sc_dt::uint64 address) const  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id3,true);
    if (trace_args() && cwr_dummy.isValid()) {
      cwr_dummy->record_attribute("address", address);
    }
    scml_mapable_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->getWriteAccessDescriptor(address);
  }
  sc_core::sc_object * get_interface_as_sc_object()  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id4,true);
    scml_mapable_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->get_interface_as_sc_object();
  }
  void setPVInterfaceType(scml::PVInterfaceType pvInterfaceType)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id5,true);
    scml_mapable_if* cwr_delegate = cwr_delegate_;
    cwr_delegate->setPVInterfaceType(pvInterfaceType);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id6,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id7,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned long long>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id8,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned long long, unsigned long long>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id9,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned, unsigned long long>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id10,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 512> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 512> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id11,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 256> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 256> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id12,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< sc_dt::sc_biguint< 128> , unsigned>  & req, PVResp< sc_dt::sc_biguint< 128> >  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id13,true);
    tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned long long, unsigned>  & req, PVResp< unsigned long long>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id14,true);
    tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  void transport(const PVReq< unsigned, unsigned>  & req, PVResp< unsigned>  & rsp)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id15,true);
    tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > * cwr_delegate = cwr_delegate_;
    cwr_delegate->transport(req,rsp);
  }
  scml_memory_pv_if< 64U, 512U> ::response_type transport(const scml_memory_pv_if< 64U, 512U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id16,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 256U> ::response_type transport(const scml_memory_pv_if< 64U, 256U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id17,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 128U> ::response_type transport(const scml_memory_pv_if< 64U, 128U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id18,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 64U> ::response_type transport(const scml_memory_pv_if< 64U, 64U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id19,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 64U, 32U> ::response_type transport(const scml_memory_pv_if< 64U, 32U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id20,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 512U> ::response_type transport(const scml_memory_pv_if< 32U, 512U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id21,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 256U> ::response_type transport(const scml_memory_pv_if< 32U, 256U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id22,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 128U> ::response_type transport(const scml_memory_pv_if< 32U, 128U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id23,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 64U> ::response_type transport(const scml_memory_pv_if< 32U, 64U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id24,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  scml_memory_pv_if< 32U, 32U> ::response_type transport(const scml_memory_pv_if< 32U, 32U> ::request_type & req)  {
    active_processes_++;
    Cwr_Trace_Entry_Exit cwr_dummy(cwr_trace_,cwr_trace_id25,true);
    scml_transport_if* cwr_delegate = cwr_delegate_;
    return cwr_delegate->transport(req);
  }
  static sc_core::sc_interface *cwr_factory(sc_core::sc_interface *intf) {
    return new scml_mapable_if_wrapper (dynamic_cast<scml_mapable_if * >(intf));
  }
};

template <class DT,class AT >
class scml_post_if_wrapper;
  class cwr_anonymous_register_imc {
   public:
    cwr_anonymous_register_imc() {
      register_imc_wrapper(typeid(sc_core::cwr_sc_signal_base).name(), sc_core_cwr_sc_signal_base_wrapper::cwr_factory, 6);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< bool> ).name(), sc_core_sc_signal_in_if_wrapper< bool> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< sc_dt::sc_logic> ).name(), sc_core_sc_signal_in_if_wrapper< sc_dt::sc_logic> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< bool> ).name(), sc_core_sc_signal_write_if_wrapper< bool> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< bool> ).name(), sc_core_sc_signal_inout_if_wrapper< bool> ::cwr_factory, 12);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< sc_dt::sc_logic> ).name(), sc_core_sc_signal_write_if_wrapper< sc_dt::sc_logic> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< sc_dt::sc_logic> ).name(), sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_logic> ::cwr_factory, 12);
      register_imc_wrapper(typeid(sc_core::sc_clock_if).name(), sc_core_sc_clock_if_wrapper::cwr_factory, 4);
      register_imc_wrapper(typeid(sc_core::sc_event_queue_if).name(), sc_core_sc_event_queue_if_wrapper::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_mutex_if).name(), sc_core_sc_mutex_if_wrapper::cwr_factory, 4);
      register_imc_wrapper(typeid(sc_core::sc_semaphore_if).name(), sc_core_sc_semaphore_if_wrapper::cwr_factory, 5);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< char> ).name(), sc_core_sc_signal_in_if_wrapper< char> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< char> ).name(), sc_core_sc_signal_write_if_wrapper< char> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< char> ).name(), sc_core_sc_signal_inout_if_wrapper< char> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< unsigned char> ).name(), sc_core_sc_signal_in_if_wrapper< unsigned char> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< unsigned char> ).name(), sc_core_sc_signal_write_if_wrapper< unsigned char> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< unsigned char> ).name(), sc_core_sc_signal_inout_if_wrapper< unsigned char> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< short> ).name(), sc_core_sc_signal_in_if_wrapper< short> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< short> ).name(), sc_core_sc_signal_write_if_wrapper< short> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< short> ).name(), sc_core_sc_signal_inout_if_wrapper< short> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< unsigned short> ).name(), sc_core_sc_signal_in_if_wrapper< unsigned short> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< unsigned short> ).name(), sc_core_sc_signal_write_if_wrapper< unsigned short> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< unsigned short> ).name(), sc_core_sc_signal_inout_if_wrapper< unsigned short> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< int> ).name(), sc_core_sc_signal_in_if_wrapper< int> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< int> ).name(), sc_core_sc_signal_write_if_wrapper< int> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< int> ).name(), sc_core_sc_signal_inout_if_wrapper< int> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< unsigned> ).name(), sc_core_sc_signal_in_if_wrapper< unsigned> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< unsigned> ).name(), sc_core_sc_signal_write_if_wrapper< unsigned> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< unsigned> ).name(), sc_core_sc_signal_inout_if_wrapper< unsigned> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< long> ).name(), sc_core_sc_signal_in_if_wrapper< long> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< long> ).name(), sc_core_sc_signal_write_if_wrapper< long> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< long> ).name(), sc_core_sc_signal_inout_if_wrapper< long> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< unsigned long> ).name(), sc_core_sc_signal_in_if_wrapper< unsigned long> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< unsigned long> ).name(), sc_core_sc_signal_write_if_wrapper< unsigned long> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< unsigned long> ).name(), sc_core_sc_signal_inout_if_wrapper< unsigned long> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< long long> ).name(), sc_core_sc_signal_in_if_wrapper< long long> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< long long> ).name(), sc_core_sc_signal_write_if_wrapper< long long> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< long long> ).name(), sc_core_sc_signal_inout_if_wrapper< long long> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< unsigned long long> ).name(), sc_core_sc_signal_in_if_wrapper< unsigned long long> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< unsigned long long> ).name(), sc_core_sc_signal_write_if_wrapper< unsigned long long> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< unsigned long long> ).name(), sc_core_sc_signal_inout_if_wrapper< unsigned long long> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< float> ).name(), sc_core_sc_signal_in_if_wrapper< float> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< float> ).name(), sc_core_sc_signal_write_if_wrapper< float> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< float> ).name(), sc_core_sc_signal_inout_if_wrapper< float> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< double> ).name(), sc_core_sc_signal_in_if_wrapper< double> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< double> ).name(), sc_core_sc_signal_write_if_wrapper< double> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< double> ).name(), sc_core_sc_signal_inout_if_wrapper< double> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< sc_core::sc_time> ).name(), sc_core_sc_signal_in_if_wrapper< sc_core::sc_time> ::cwr_factory, 6);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< sc_core::sc_time> ).name(), sc_core_sc_signal_write_if_wrapper< sc_core::sc_time> ::cwr_factory, 1);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< sc_core::sc_time> ).name(), sc_core_sc_signal_inout_if_wrapper< sc_core::sc_time> ::cwr_factory, 5);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< sc_dt::sc_bit> ).name(), sc_core_sc_signal_in_if_wrapper< sc_dt::sc_bit> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< sc_dt::sc_bit> ).name(), sc_core_sc_signal_write_if_wrapper< sc_dt::sc_bit> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< sc_dt::sc_bit> ).name(), sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_bit> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< sc_dt::sc_signed> ).name(), sc_core_sc_signal_in_if_wrapper< sc_dt::sc_signed> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< sc_dt::sc_signed> ).name(), sc_core_sc_signal_write_if_wrapper< sc_dt::sc_signed> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< sc_dt::sc_signed> ).name(), sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_signed> ::cwr_factory, 10);
      register_imc_wrapper(typeid(sc_core::sc_signal_in_if< sc_dt::sc_unsigned> ).name(), sc_core_sc_signal_in_if_wrapper< sc_dt::sc_unsigned> ::cwr_factory, 8);
      register_imc_wrapper(typeid(sc_core::sc_signal_write_if< sc_dt::sc_unsigned> ).name(), sc_core_sc_signal_write_if_wrapper< sc_dt::sc_unsigned> ::cwr_factory, 2);
      register_imc_wrapper(typeid(sc_core::sc_signal_inout_if< sc_dt::sc_unsigned> ).name(), sc_core_sc_signal_inout_if_wrapper< sc_dt::sc_unsigned> ::cwr_factory, 10);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< bool> ).name(), snps_sc_signal_clamp_if_wrapper< bool> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< sc_dt::sc_logic> ).name(), snps_sc_signal_clamp_if_wrapper< sc_dt::sc_logic> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< char> ).name(), snps_sc_signal_clamp_if_wrapper< char> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< unsigned char> ).name(), snps_sc_signal_clamp_if_wrapper< unsigned char> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< short> ).name(), snps_sc_signal_clamp_if_wrapper< short> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< unsigned short> ).name(), snps_sc_signal_clamp_if_wrapper< unsigned short> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< int> ).name(), snps_sc_signal_clamp_if_wrapper< int> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< unsigned> ).name(), snps_sc_signal_clamp_if_wrapper< unsigned> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< long> ).name(), snps_sc_signal_clamp_if_wrapper< long> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< unsigned long> ).name(), snps_sc_signal_clamp_if_wrapper< unsigned long> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< long long> ).name(), snps_sc_signal_clamp_if_wrapper< long long> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< unsigned long long> ).name(), snps_sc_signal_clamp_if_wrapper< unsigned long long> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< float> ).name(), snps_sc_signal_clamp_if_wrapper< float> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< double> ).name(), snps_sc_signal_clamp_if_wrapper< double> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< sc_core::sc_time> ).name(), snps_sc_signal_clamp_if_wrapper< sc_core::sc_time> ::cwr_factory, 1);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< sc_dt::sc_bit> ).name(), snps_sc_signal_clamp_if_wrapper< sc_dt::sc_bit> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< sc_dt::sc_signed> ).name(), snps_sc_signal_clamp_if_wrapper< sc_dt::sc_signed> ::cwr_factory, 3);
      register_imc_wrapper(typeid(snps::sc::signal_clamp_if< sc_dt::sc_unsigned> ).name(), snps_sc_signal_clamp_if_wrapper< sc_dt::sc_unsigned> ::cwr_factory, 3);
      register_imc_wrapper(typeid(tlm::tlm_fifo_config_size_if).name(), tlm_tlm_fifo_config_size_if_wrapper::cwr_factory, 7);
      register_imc_wrapper(typeid(tlm::tlm_bw_direct_mem_if).name(), tlm_tlm_bw_direct_mem_if_wrapper::cwr_factory, 3);
      register_imc_wrapper(typeid(tlm::tlm_fw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> ).name(), tlm_tlm_fw_nonblocking_transport_if_wrapper< tlm::tlm_generic_payload, tlm::tlm_phase> ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_blocking_transport_if< tlm::tlm_generic_payload> ).name(), tlm_tlm_blocking_transport_if_wrapper< tlm::tlm_generic_payload> ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_fw_direct_mem_if< tlm::tlm_generic_payload> ).name(), tlm_tlm_fw_direct_mem_if_wrapper< tlm::tlm_generic_payload> ::cwr_factory, 2);
      register_imc_wrapper(typeid(tlm::tlm_transport_dbg_if< tlm::tlm_generic_payload> ).name(), tlm_tlm_transport_dbg_if_wrapper< tlm::tlm_generic_payload> ::cwr_factory, 2);
      register_imc_wrapper(typeid(tlm::tlm_fw_transport_if< tlm::tlm_base_protocol_types> ).name(), tlm_tlm_fw_transport_if_wrapper< tlm::tlm_base_protocol_types> ::cwr_factory, 2);
      register_imc_wrapper(typeid(tlm::tlm_fw_transport_if_export_dummy).name(), tlm_tlm_fw_transport_if_export_dummy_wrapper::cwr_factory, 2);
      register_imc_wrapper(typeid(tlm::tlm_bw_nonblocking_transport_if< tlm::tlm_generic_payload, tlm::tlm_phase> ).name(), tlm_tlm_bw_nonblocking_transport_if_wrapper< tlm::tlm_generic_payload, tlm::tlm_phase> ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_bw_transport_if< tlm::tlm_base_protocol_types> ).name(), tlm_tlm_bw_transport_if_wrapper< tlm::tlm_base_protocol_types> ::cwr_factory, 2);
      register_imc_wrapper(typeid(tlm::tlm_bw_transport_if_export_dummy).name(), tlm_tlm_bw_transport_if_export_dummy_wrapper::cwr_factory, 2);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< unsigned, unsigned> , PVResp< unsigned> > ).name(), tlm_tlm_transport_if_wrapper< PVReq< unsigned, unsigned> , PVResp< unsigned> > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > ).name(), tlm_tlm_transport_if_wrapper< PVReq< unsigned long long, unsigned> , PVResp< unsigned long long> > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > ).name(), tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 128> , unsigned> , PVResp< sc_dt::sc_biguint< 128> > > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > ).name(), tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 256> , unsigned> , PVResp< sc_dt::sc_biguint< 256> > > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > ).name(), tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 512> , unsigned> , PVResp< sc_dt::sc_biguint< 512> > > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > ).name(), tlm_tlm_transport_if_wrapper< PVReq< unsigned, unsigned long long> , PVResp< unsigned> > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > ).name(), tlm_tlm_transport_if_wrapper< PVReq< unsigned long long, unsigned long long> , PVResp< unsigned long long> > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > ).name(), tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 128> , unsigned long long> , PVResp< sc_dt::sc_biguint< 128> > > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > ).name(), tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 256> , unsigned long long> , PVResp< sc_dt::sc_biguint< 256> > > ::cwr_factory, 1);
      register_imc_wrapper(typeid(tlm::tlm_transport_if< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > ).name(), tlm_tlm_transport_if_wrapper< PVReq< sc_dt::sc_biguint< 512> , unsigned long long> , PVResp< sc_dt::sc_biguint< 512> > > ::cwr_factory, 1);
      register_imc_wrapper(typeid(PVDecoder_if_base).name(), PVDecoder_if_base_wrapper::cwr_factory, 2);
      register_imc_wrapper(typeid(PV_if< unsigned, unsigned> ).name(), PV_if_wrapper< unsigned, unsigned> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 32U, 32U> ).name(), scml_memory_pv_if_wrapper< 32U, 32U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< unsigned long long, unsigned> ).name(), PV_if_wrapper< unsigned long long, unsigned> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 32U, 64U> ).name(), scml_memory_pv_if_wrapper< 32U, 64U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< sc_dt::sc_biguint< 128> , unsigned> ).name(), PV_if_wrapper< sc_dt::sc_biguint< 128> , unsigned> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 32U, 128U> ).name(), scml_memory_pv_if_wrapper< 32U, 128U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< sc_dt::sc_biguint< 256> , unsigned> ).name(), PV_if_wrapper< sc_dt::sc_biguint< 256> , unsigned> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 32U, 256U> ).name(), scml_memory_pv_if_wrapper< 32U, 256U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< sc_dt::sc_biguint< 512> , unsigned> ).name(), PV_if_wrapper< sc_dt::sc_biguint< 512> , unsigned> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 32U, 512U> ).name(), scml_memory_pv_if_wrapper< 32U, 512U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< unsigned, unsigned long long> ).name(), PV_if_wrapper< unsigned, unsigned long long> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 64U, 32U> ).name(), scml_memory_pv_if_wrapper< 64U, 32U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< unsigned long long, unsigned long long> ).name(), PV_if_wrapper< unsigned long long, unsigned long long> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 64U, 64U> ).name(), scml_memory_pv_if_wrapper< 64U, 64U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< sc_dt::sc_biguint< 128> , unsigned long long> ).name(), PV_if_wrapper< sc_dt::sc_biguint< 128> , unsigned long long> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 64U, 128U> ).name(), scml_memory_pv_if_wrapper< 64U, 128U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< sc_dt::sc_biguint< 256> , unsigned long long> ).name(), PV_if_wrapper< sc_dt::sc_biguint< 256> , unsigned long long> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 64U, 256U> ).name(), scml_memory_pv_if_wrapper< 64U, 256U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(PV_if< sc_dt::sc_biguint< 512> , unsigned long long> ).name(), PV_if_wrapper< sc_dt::sc_biguint< 512> , unsigned long long> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_memory_pv_if< 64U, 512U> ).name(), scml_memory_pv_if_wrapper< 64U, 512U> ::cwr_factory, 1);
      register_imc_wrapper(typeid(scml_clock_if).name(), scml_clock_if_wrapper::cwr_factory, 20);
      register_imc_wrapper(typeid(scml_transport_if).name(), scml_transport_if_wrapper::cwr_factory, 0);
      register_imc_wrapper(typeid(scml_mapable_if).name(), scml_mapable_if_wrapper::cwr_factory, 3);
    }
  };
  // The following will ensure the register functions get called
  cwr_anonymous_register_imc cwr_anonymous_register_imc_obj;
}
