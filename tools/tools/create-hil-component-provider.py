#!/usr/bin/env python
import subprocess
import sys
import optparse

parser = optparse.OptionParser()
parser.add_option('-o', '--object-file', dest='objfile', help='The object file')
#parser.add_option('-a', '--age', dest='age', help='Your Age', type=int)

(options, args) = parser.parse_args()

if options.objfile is None:
    options.objfile = raw_input('Enter object file name:')

output_basename = subprocess.check_output(['basename',options.objfile,'.o'])
print output_basename

FUNCTIONS = subprocess.check_output("msp430-nm "+ options.objfile+" | grep T | cut -f3 -d "+'" "',shell=True).split("\n")
list.pop(FUNCTIONS)
print FUNCTIONS

name_lower = output_basename.rstrip()
name_upper = output_basename.rstrip().upper()

file  = open(""+name_lower+"-adapter.h",'w')

print >>file, '#ifndef __' + name_upper + '_PROVIDER_H__'
print >>file, '#define __' + name_upper + '_PROVIDER_H__'
print >>file, "\n"
print >>file, '#include "' + name_lower + '.h"'
print >>file, "\n"
print >>file, 'enum '+ name_upper + '_FUNCTION {'
for function in FUNCTIONS:
	print >>file, "\tFUNCTION_" + function.upper() + ','
print >>file,  "\tFUNCTION_" + name_upper + '_LAST,'
print >>file, '};'
print >>file, "\n"
print >>file, 'enum ' + name_upper + '_PROCESSES {'
print >>file, "\tPROCESS_" + name_upper + '_LAST,'
print >>file, '};'
print >>file, "\n"
print >>file, "const void* " + name_lower+ "_functions[FUNCTION_" + name_upper+ "_LAST]={"+ ",".join(FUNCTIONS) + "};"
print >>file, "const struct process* " + name_lower+ "_processes[PROCESS_" + name_upper + "_LAST] = NULL;"
print >>file, "\n"
print >>file, "hil_component_t " + name_lower + "= { { " + name_upper +", 2, 7, HIL_COMPONENT, " + str(len(name_lower)) + ", " + name_lower +"} , {" + name_lower + "_functions, " + name_lower +"_processes, FUNCTION_" + name_upper + "_LAST, PROCESS_" + name_upper + "_LAST} };"
print >>file, "\n"
print >>file, '#endif /*__' + name_upper + '_PROVIDER_H__*/'
