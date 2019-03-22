#!/usr/bin/env python
import subprocess
import sys
import optparse

parser = optparse.OptionParser()
parser.add_option('-c', '--source-file', dest='cfile', help='The .c file')
parser.add_option('-o', '--object-file', dest='ofile', help='The .o file')
parser.add_option('-q', '--cheader-file', dest='hfile', help='The .h file')
#parser.add_option('-a', '--age', dest='age', help='Your Age', type=int)

(options, args) = parser.parse_args()

if options.cfile is None:
    options.cfile = raw_input('Enter c file name:')

print options.cfile

cfile_basename = subprocess.check_output(['basename',options.cfile,'.h']).strip()
print cfile_basename
cfile_basename_upper = cfile_basename.upper()

functions = subprocess.check_output("ctags -R --c-kinds=p -f - " + options.cfile +" | grep -v static | awk -F'\t|\/\^|;|\$' '{{cmd = \"basename \"$2 \" .h\"};{cmd | getline line};{print line \" \"$4};{close(cmd)}}'",shell=True).split("\n")
list.pop(functions)

for line in functions:
	fdef = (line.partition(" ")[2]).rstrip()
	fname = ((fdef.partition("(")[0]).rpartition(" ")[2]).rstrip() 
	fret = ((fdef.partition("(")[0]).rpartition(" ")[0]).rstrip()
	fparams = ((fdef.partition("(")[2]).partition(")")[0]).split(",")
	fparams_name = []
	fparams_type = []
	for index in range(len(fparams)):
		fparams[index] = fparams[index].strip()
		ind_ptr = fparams[index].rfind("*")
		if ind_ptr > -1:
			fparams_type.append(fparams[index][0:ind_ptr+1])
			fparams_name.append(fparams[index].rpartition("*")[2])
		else:
			fparams_type.append(fparams[index].rpartition(" ")[0])
			fparams_name.append(fparams[index].rpartition(" ")[2])
	print "\n" + '/* Stub function declaration for ' + fname +' */'
	print "static " + fdef + "{"
	print "\t( (" + fret + " (*)(" + ",".join(fparams_type) + ")) " + cfile_basename + "_cmp_ref->interface.function_array[FUNCTION_" + fname.upper() + "])(" + ",".join(fparams_name)  + ");"
	print "}"

