# Downloads french "Code Civil" from https://github.com/steeve/france.code-civil and remove article names from each file

import os

# Clone from github
os.system('git clone https://github.com/steeve/france.code-civil.git')

base = "france.code-civil"


# Search recursively through each sub-directory and remove two first lines from each md/txt file
def rec(dirname):
	for d in os.listdir(dirname):
		filename = dirname+"/"+d
		if os.path.isdir(filename):
			rec(filename)
		elif os.path.isfile(filename):
			if filename.endswith(".md") or filename.endswith(".txt"):
				with open(filename, "r") as txtfile:
					text=txtfile.readlines()
				with open(filename, "w") as txtfile:
					for k in range(2,len(text)):
						txtfile.write(text[k])

# Apply function to root directory
rec(base)





