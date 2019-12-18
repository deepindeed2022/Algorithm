#!/bin/python2

import sys
import os.path
import os

def exclude_suffix(f, suffix=[".c", ".cpp", ".md", ".py", ".h", ".hpp"]):
	for s in suffix:
		if f.endswith(s):
			return False
	return True

if __name__ == '__main__':
	files = os.listdir(".")
	for f in files:
		if os.access(f, os.X_OK) and exclude_suffix(f):
			os.remove(f)