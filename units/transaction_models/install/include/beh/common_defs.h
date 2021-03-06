/*****************************************************************************
 *
 *   The following code is derived, directly or indirectly, from the SystemC
 *   source code Copyright (c) 1996-2014 by all Contributors.
 *   All Rights reserved.
 *
 *   The contents of this file are subject to the restrictions and limitations
 *   set forth in the SystemC Open Source License (the "License");
 *   You may not use this file except in compliance with such restrictions and
 *   limitations. You may obtain instructions on how to receive a copy of the
 *   License at http://www.accellera.org/. Software distributed by Contributors
 *   under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 *   ANY KIND, either express or implied. See the License for the specific
 *   language governing rights and limitations under the License.
 *
 *   *****************************************************************************/
/*
 * @file
 *  reporting.h
 *  
 * @brief
 * Convenience macros to simplify reporting.
 */
#pragma once
#include "tlm.h"                                        ///< TLM headers
#include <sstream>                                      ///< string streams
#include <iomanip>                                      ///< I/O manipulation
#include <stdio.h>                                      ///< standard I/O

using std::setfill;
using std::setw;
using namespace std;


#define SC_TRACE_SIG(x) sc_trace(tf, x,       std::string(sc_module::name()) + "." + #x)
#define SC_TRACE_VAR(x) sc_trace(tf, x,       std::string(sc_module::name()) + "." + #x)
#define SC_TRACE_ATT(x) sc_trace(tf, x.value, std::string(sc_module::name()) + "." + #x)

#if ( defined ( REPORT_DEFINE_GLOBALS ) )
#   define RDG_EXTERN
#else /* REPORT_DEFINE_GLOBALS */
#   define RDG_EXTERN   extern
#endif /* REPORT_DEFINE_GLOBALS */

RDG_EXTERN bool          tlm_enable_info_reporting;     ///< info level reporting enable
RDG_EXTERN bool          tlm_enable_warning_reporting;  ///< warning level reporting enable
RDG_EXTERN bool          tlm_enable_error_reporting;    ///< error level reporting enable
RDG_EXTERN bool          tlm_enable_fatal_reporting;    ///< fatal level reporting enable

RDG_EXTERN ostringstream reporting_os;                  ///< reporting output string

#define REPORT_ENABLE_INFO_REPORTING()     (tlm_enable_info_reporting    = true)
#define REPORT_ENABLE_WARNING_REPORTING()  (tlm_enable_warning_reporting = true)
#define REPORT_ENABLE_ERROR_REPORTING()    (tlm_enable_error_reporting   = true)
#define REPORT_ENABLE_FATAL_REPORTING()    (tlm_enable_fatal_reporting   = true)

#define REPORT_DISABLE_INFO_REPORTING()    (tlm_enable_info_reporting    = false)
#define REPORT_DISABLE_WARNING_REPORTING() (tlm_enable_warning_reporting = false)
#define REPORT_DISABLE_ERROR_REPORTING()   (tlm_enable_error_reporting   = false)
#define REPORT_DISABLE_FATAL_REPORTING()   (tlm_enable_fatal_reporting   = false)

#define REPORT_SET_ENABLES(ri,rw,re,rf) \
{ \
  if (ri) {REPORT_ENABLE_INFO_REPORTING    ();} else {REPORT_DISABLE_INFO_REPORTING    ();} \
  if (rw) {REPORT_ENABLE_WARNING_REPORTING ();} else {REPORT_DISABLE_WARNING_REPORTING ();} \
  if (re) {REPORT_ENABLE_ERROR_REPORTING   ();} else {REPORT_DISABLE_ERROR_REPORTING   ();} \
  if (rf) {REPORT_ENABLE_FATAL_REPORTING   ();} else {REPORT_DISABLE_FATAL_REPORTING   ();} \
}

#define REPORT_ENABLE_ALL_REPORTING() \
{ \
  REPORT_SET_ENABLES(true,true,true,true); \
}

#define REPORT_DISABLE_ALL_REPORTING() \
{ \
  REPORT_SET_ENABLES(false,false,false,false); \
}

#if ( defined ( REPORTING_OFF ) )

#define REPORT_NEW(text) {}
#define REPORT_APPEND(text) {}
#define REPORT_OUTPUT(severity, source) {}

#else /* REPORTING_OFF */

#define REPORT_NEW(text) \
{ \
  reporting_os.str (""); \
  reporting_os << text; \
}

#define REPORT_APPEND(text) \
{ \
  reporting_os << text; \
}

#define REPORT_OUTPUT(severity, source, text) \
{ \
  ostringstream os; \
  os << sc_core::sc_time_stamp() << ": " <<  __FUNCTION__ << ": " << text; \
  SC_REPORT_##severity (source, os.str().c_str()); \
}
#endif /* REPORTING_OFF */

#define REPORT_INFO(source, routine, text) \
{ ostringstream os; \
  string routine_string (routine); \
  int colon_location; \
  if ((colon_location = routine_string.find("::")) != -1) \
  { \
    routine_string.erase(0, colon_location + 2); \
  } \
  os << sc_core::sc_time_stamp() << ": " << routine_string << ": " << text; \
  if (tlm_enable_info_reporting) \
  { \
    SC_REPORT_INFO(source, os.str().c_str()); \
  } \
}

#define REPORT_WARNING(source, routine, text) \
{ ostringstream os; \
  string routine_string (routine); \
  int colon_location; \
  if ((colon_location = routine_string.find("::")) != -1) \
  { \
    routine_string.erase(0, colon_location + 2); \
  } \
  os << sc_core::sc_time_stamp() << ": " << routine_string << ": " << text; \
  if (tlm_enable_warning_reporting) \
  { \
    SC_REPORT_WARNING(source, os.str().c_str()); \
  } \
}

#define REPORT_ERROR(source, routine, text) \
{ ostringstream os; \
  string routine_string (routine); \
  int colon_location; \
  if ((colon_location = routine_string.find("::")) != -1) \
  { \
    routine_string.erase(0, colon_location + 2); \
  } \
  os << sc_core::sc_time_stamp() << ": " << routine_string << ": " << text; \
  if (tlm_enable_error_reporting) \
  { \
    SC_REPORT_ERROR(source, os.str().c_str()); \
  } \
}

#define REPORT_FATAL(source, routine, text) \
{ ostringstream os; \
  string routine_string (routine); \
  int colon_location; \
  if ((colon_location = routine_string.find("::")) != -1) \
  { \
    routine_string.erase(0, colon_location + 2); \
  } \
  os << sc_core::sc_time_stamp() << ": " << routine_string << ": " << text; \
  if (tlm_enable_fatal_reporting) \
  { \
    SC_REPORT_FATAL(source, os.str().c_str()); \
  } \
}
