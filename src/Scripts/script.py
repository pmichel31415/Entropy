# Launches entropy program on all txt/md files of a directory (including subdirectories)

import os

# markov order
o = 2

# base directory name
base = "texts"

# Search recursively through each sub-directory and launch "./entropy assimilate"
def rec(dirname):

	for d in os.listdir(dirname):
		filename = dirname+"/"+d
		if os.path.isdir(filename):
			rec(filename)
		elif os.path.isfile(filename):
			if filename.endswith(".txt") or filename.endswith(".md"):
				command = "entropy assimilate store_2.txt \"" + filename + "\" " + str(o)
				print(command)
				os.system(command)

# Apply function to root directory
rec(base)
