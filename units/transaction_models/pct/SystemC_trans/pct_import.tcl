::pct::new_project
::pct::open_library TLM2_PL
#Import NoC
::pct::clear_systemc_defines
::pct::clear_systemc_include_path
::pct::add_to_systemc_include_path /workarea/GitRepo/VP_concept_examples/units/transaction_models/source/SystemC_trans
::pct::set_import_protocol_generation_flag false
::pct::set_update_existing_encaps_flag true
::pct::set_dynamic_port_arrays_flag true
::pct::set_import_scml_properties_flag true
::pct::load_modules --set-category modules pct_import.cc
#Set Port Protocols correctly

set block SYSTEM_LIBRARY:master
set preprocessorOptions "-I/workarea/GitRepo/VP_concept_examples/units/transaction_models/source/SystemC_trans"
# set linkerOptions [concat $linkerOptions "-Wl,-E,-rpath,$env(FLEXNOC_PA_LIBPATH) -L$env(FLEXNOC_PA_LIBPATH) -lnttpTLM -L$env(FLEXNOC_PA_LIBPATH)/../../../lib -L../Specification_Architecture_Structure -lSpecification_Architecture_Structure_WrappedVV -lgmpxx -lgmp"]
# ::pct::set_encap_build_script $block/master vp_build.tcl
::pct::set_background_color_rgb $block 255 255 255 255

::pct::export_system_library master master.xml
