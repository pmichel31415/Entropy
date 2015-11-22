#include <iostream>
#include <time.h>
#include "Storing/store_tree.h"
//#include "Testing/test.h"
#include "entropy.h"
#include "string.h"

using namespace std;

const string usage = "Usage:\n\n  - assimilate [store file name] [text file name] ([order])\n\n  - generate [store file name] [output file name] ([length] [order])\n\n  - calculate [store file name] ([order])\n";

wstring wstr_from_char_arr(const char* str){
	wstring wstr;
	string*  s = new string(str);
	wstr.assign(s->begin(), s->end());
	return wstr;
}

int main(int argc, const char* argv[]){

	srand(time(0));

	if (argc < 2){
		cerr << "No command given" << endl;
		cerr << usage << endl;
	}
	else{
		Store_tree s;
		if (strcmp(argv[1], "assimilate") == 0 && argc >= 4){
			if (argc >= 5){
				assim(s, (char*)argv[2], (char*)argv[3], atoi(argv[4]));
			}
			else{
				assim(s, (char*)argv[2], (char*)argv[3], 1);
			}
		}
		else if (strcmp(argv[1], "generate") == 0 && argc >= 4){
			if (argc >= 6){
				gen(s, (char*)argv[2], (char*)argv[3], atoi(argv[4]), atoi(argv[5]));
			}
			else if (argc == 5){
				gen(s, (char*)argv[2], (char*)argv[3], atoi(argv[4]), 1);
			}
			else{
				gen(s, (char*)argv[2], (char*)argv[3], 100, 1);
			}
		}
		else if (strcmp(argv[1], "calculate") == 0 && argc >= 3){
			if (argc >= 4){
				calc(s, (char*)argv[2], atoi(argv[3]));
			}
			else{
				calc(s, (char*)argv[2], 0);
			}
		}
		else{
			cerr << "Wrong command" << endl;
			cerr << usage << endl;
		}
	}

	return 0;
}
