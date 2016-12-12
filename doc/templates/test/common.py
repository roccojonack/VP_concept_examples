# This Software is part of Wind River Simics. The rights to copy, distribute,
# modify, or otherwise make use of this Software may be licensed only
# pursuant to the terms of an applicable Wind River license agreement.
#
# Copyright 2015 Intel Corporation

from simics import *
from cli import run_command
import stest
import re

def create_configuration(classname, log_file):
    run_command('log-setup -overwrite logfile = %s' % log_file)
    clock = SIM_create_object('clock', 'clk', [['freq_mhz', 1000]])
    return SIM_create_object(classname, 'dut', [['queue', clock],
                                                ['log_level', 2]])

def remove_trailing_file_info(string):
    return re.sub(r' in \S+:\d+$', '', string)

def compare_logs(expected, actual):
    stest.expect_equal(len(actual), len(expected))  # zip will truncate
    for (lineno, (exp_line, act_line)) in enumerate(zip(expected, actual)):
        stest.expect_equal(remove_trailing_file_info(act_line),
                           remove_trailing_file_info(exp_line),
                           'Logs did not match on line %d' % (lineno + 1))

def run_test(classname):
    log_file = stest.log_file(classname + '.log')
    dut = create_configuration(classname, log_file)

    SIM_continue(1000000)  # Arbitrary large number
#    compare_logs(file('master.log').readlines(),
#                 file(log_file).readlines())
