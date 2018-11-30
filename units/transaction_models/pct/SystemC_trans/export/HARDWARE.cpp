#include "systemc.h"
#include "../../../source/SystemC_trans/master.h"
#include "../../../source/SystemC_trans/slave.h"
#include "tlm.h"
#include "cassert"
#include "cwr_dynamic_loader.h"
#include "cwr_sc_dynamic_stubs.h"
#include "cwr_sc_hierarch_module.h"
#include "cwr_sc_object_creator.h"
#include "scmlinc/scml_abstraction_level_switch.h"
#include "scmlinc/scml_property_registry.h"

// User code begin (using configuration "SCV")
#include <cwrScvInterface.h>
// User code end

using namespace conf;
using namespace std;

template <class BC>
class BusCreator : public ScObjectCreatorBase
{
  sc_object* create (const string& name) {
    ScGeneratedBaseBlockCreatorHelper helper(getHierarchicalName(name));
    if (helper.is_runtime_disabled()) {
      return new conf::StubBusCreator(name.c_str(), helper);
    } else {
      return new BC(name.c_str(), helper);
    }
  }
};

template <class GBC>
class GeneratedBlockCreator : public ScObjectCreatorBase
{
  sc_object* create (const string& name) {
    ScGeneratedBaseBlockCreatorHelper helper(getHierarchicalName(name));
    if (helper.is_runtime_disabled()) {
      return new conf::StubBusCreator(name.c_str(), helper);
    } else {
      return new GBC(name.c_str(), helper);
    }
  }
};



class master0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "master/master: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       cwr_sc_object_registry::inst().addInitiatorSocket(new conf::tlm_initiator_socket_stub<32, tlm::tlm_base_protocol_types, 1, sc_core::SC_ONE_OR_MORE_BOUND>(std::string("initiator_socket" ).c_str()), string(static_cast<sc_object*>(result)->name()) + ".initiator_socket" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "master/master: " << hierach_name << " created." << std::endl; }
      master* result = new master(name.c_str());
       cwr_sc_object_registry::inst().addInitiatorSocket(&result->initiator_socket, string(static_cast<sc_object*>(result)->name()) + ".initiator_socket" );
      return result;
    }
  }
};


class slave0Creator : public ScObjectCreatorBase
{
public:
  static unsigned int creationVerboseMode() {
    const char * const env_var_val = ::getenv("SNPS_SLS_DYNAMIC_CREATION_VERBOSE");
    return env_var_val ? (::atoi(env_var_val)) : 3;
  }
  sc_object* create ( const string& name ) {
    string hierach_name = getHierarchicalName(name);
    if (scml_property_registry::inst().hasProperty(scml_property_registry::MODULE, scml_property_registry::BOOL, hierach_name, "runtime_disabled") && 
        scml_property_registry::inst().getBoolProperty(scml_property_registry::MODULE, hierach_name, "runtime_disabled")) {
      sc_module_name n(name.c_str());
      if (creationVerboseMode() >= 6) { std::cout << "slave/slave: STUB for " << hierach_name << " created." << std::endl; }
      conf::stub *result = new conf::stub(n);
       cwr_sc_object_registry::inst().addTargetSocket(new conf::tlm_target_socket_stub<32, tlm::tlm_base_protocol_types, 1, sc_core::SC_ONE_OR_MORE_BOUND>(std::string("target_socket" ).c_str()), string(static_cast<sc_object*>(result)->name()) + ".target_socket" );
      return result;
    } else {
      if (creationVerboseMode() >= 6) { std::cout << "slave/slave: " << hierach_name << " created." << std::endl; }
      slave* result = new slave(name.c_str());
       cwr_sc_object_registry::inst().addTargetSocket(&result->target_socket, string(static_cast<sc_object*>(result)->name()) + ".target_socket" );
      return result;
    }
  }
};



extern void scv_tr_cwrdb_init();

int sc_main(int argc, char* argv[])
{
  scv_tr_cwrdb_init();
  // User code begin (using configuration "SCV")
scv_tr_cwrdb_init();
  // User code end

  ScInitiatorSocketFactory::inst().addCreator ("conf::tlm_initiator_socket_stub<32, tlm::tlm_base_protocol_types, 1, sc_core::SC_ONE_OR_MORE_BOUND>", new ScInitiatorSocketCreator<conf::tlm_initiator_socket_stub<32, tlm::tlm_base_protocol_types, 1, sc_core::SC_ONE_OR_MORE_BOUND> >());
  ScInitiatorSocketFactory::inst().addCreator ("tlm::tlm_base_initiator_socket<32, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND>", new ScInitiatorSocketCreator<tlm::tlm_base_initiator_socket<32, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> >());
  ScObjectFactory::inst().addCreator ("master0", new master0Creator());
  ScObjectFactory::inst().addCreator ("slave0", new slave0Creator());
  ScTargetSocketFactory::inst().addCreator ("conf::tlm_target_socket_stub<32, tlm::tlm_base_protocol_types, 1, sc_core::SC_ONE_OR_MORE_BOUND>", new ScTargetSocketCreator<conf::tlm_target_socket_stub<32, tlm::tlm_base_protocol_types, 1, sc_core::SC_ONE_OR_MORE_BOUND> >());
  ScTargetSocketFactory::inst().addCreator ("tlm::tlm_base_target_socket<32, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND>", new ScTargetSocketCreator<tlm::tlm_base_target_socket<32, tlm::tlm_fw_transport_if<tlm::tlm_base_protocol_types>, tlm::tlm_bw_transport_if<tlm::tlm_base_protocol_types>, 1, sc_core::SC_ONE_OR_MORE_BOUND> >());
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "master/master loaded." << std::endl; }
  if (::getenv("SNPS_SLS_DYNAMIC_LOADER_VERBOSE")) { std::cout << "slave/slave loaded." << std::endl; }

  scml_property_registry::inst().setXMLFile("Properties.xml");

  nSnps::nDynamicLoading::DynamicLoader dynamicLoader
    (scml_property_registry::inst().getStringProperty(scml_property_registry::GLOBAL, "", "/pct/runtime/dynamic_load_info"));

  string xml_file_path = scml_property_registry::inst().getPropertyXmlFilePath();
  string hierarchy_xml_file = xml_file_path + "/" + 
    scml_property_registry::inst().getStringProperty(
      scml_property_registry::GLOBAL, "", "system_hierarchy_xml_file");

  cwr_sc_hierarch_module* HARDWARE = new cwr_sc_hierarch_module("HARDWARE", hierarchy_xml_file);

  // Enable/disable backdoor accesses
  scml_abstraction_level_switch::instance().set_simulation_mode(scml_property_registry::inst().getStringProperty(scml_property_registry::GLOBAL, "", "/pct/runtime/simulation_mode")=="MODE_FULL_SIMULATION" ? scml_abstraction_level_switch::MODE_FULL_SIMULATION : scml_abstraction_level_switch::MODE_SPEED_OPTIMIZED);

  // User code begin (using configuration "SCV")

  // User code end

  try {
    sc_start();
  } catch (const sc_core::sc_report& sce) { 
    std::cout << "Exception raised by sc_start() : " << sce.what() << std::endl;  
    return 1;  
  } 

  if (sc_is_running()) {
    sc_stop();
  }
  delete HARDWARE;

  // User code begin (using configuration "SCV")

  // User code end

  return 0;
}
