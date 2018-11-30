#
# Copyright (c) 2013 Qualcomm Technologies, Inc. All rights reserved.
#
namespace eval Specification {
#    variable installDir   [file normalize [file dirname [info script]]]
	
    proc buildproc { args } {
        global env
        variable installDir
        variable compiler

        variable compiler [::scsh::get_backend_compiler]

        #  set target $machine
        set target [::scsh::machine]
        set linkerOptions ""
        set preprocessorOptions ""

        set libversion $compiler

        switch -exact -- $target {

            "linux" {
                # Set the preprocessor paths.
                set preprocessorOptions [concat $preprocessorOptions "-Iinclude"]

                # Set the Linker paths.
                set linkerOptions [concat $linkerOptions "-Wl,-E,-rpath,$env(FLEXNOC_PA_LIBPATH) -L$env(FLEXNOC_PA_LIBPATH) -lnttpTLM -L$env(FLEXNOC_PA_LIBPATH)/../../../lib -L../Specification_Architecture_Structure -lSpecification_Architecture_Structure_WrappedVV -lgmpxx -lgmp"]
            }

            "windows" {
                # Set the preprocessor paths.
                set preprocessorOptions [concat $preprocessorOptions "-I\"include\""]

                # Set the Linker paths.
                set linkerOptions [concat $linkerOptions "-LIBPATH:\"\$(FLEXNOC_PA_LIBPATH)\" libnttpTLM.lib"]
            }

            default {
               # target platform is not supported.
               puts stderr "ERROR: \"$target\" is not supported, [::scsh::version]"
               return
            }
        }

        puts "PREPROCESSOR=$preprocessorOptions"
        puts "LINKER=$linkerOptions"

        puts "Adding IP build options: Arteris NOC, version [::scsh::version]."
        ::scsh::cwr_append_ipsimbld_opts preprocessor "$preprocessorOptions"
        ::scsh::cwr_append_ipsimbld_opts linker       "$linkerOptions"

    }

    puts "Enabling IP: Arteris NOC, version [::scsh::version]."
    ::scsh::add_build_callback [namespace current]::buildproc
}
