#include "entropy.h"

void assim(Store& s, char* store_fname, char* text_fname, int order){
	s.open(store_fname);
	order++;
	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	string txt = read_text(text_fname);

	assimilate_text(txt, s, order, &split);

	s.close(store_fname);

}

void gen(Store& s, char* store_fname, char* output_fname, int length, int order){
	ofstream ofs;
	ofs.open(output_fname);
	s.open(store_fname);

	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	string txt = generate_text(s, length, order);
	replace(txt.begin(), txt.end(), '_', ' ');
	ofs << txt;
	ofs.close();
}

void calc(Store& s, char* store_fname, int order){
	s.open(store_fname);
	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	double H = s.entropy(order);

	wcout << H << endl;

}
