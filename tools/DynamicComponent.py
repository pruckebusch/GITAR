#!/usr/bin/env python
import subprocess
import sys
import optparse
import string
from collections import namedtuple
#~ ComponentInfo = namedtuple("ComponentInfo", "Name nProvFnct nReqFnct nReqDynFnct nReqSysFnct nReqDynCmp nReqSysCmp lstProvFnct lstReqFnct lstReqSysFnct lstReqDynFnct")
FunctionInfo = namedtuple("FunctionInfo","Name strComp nParam nReturn strFnctDef strFnctReturn lstFnctParam")

class ComponentInfo:
	def __init__(self, strName, uid, num_prov_functions, version, subrelease):
		self.strName
		self.uid = uid
		self.num_prov_functions = num_prov_functions
		self.version = version
		self.subrelease = subrelease
	
