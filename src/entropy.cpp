#include "entropy.h"

void assim(Store& s, char* store_fname, char* text_fname, int order){
	s.open(store_fname);
	order++;
	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	wstring txt = read_text(text_fname);
	assimilate_text(txt, s, order);

	s.close(store_fname);

}

void gen(Store& s, char* store_fname, char* output_fname, int length, int order){
	wofstream wofs;
	wofs.open(output_fname);
	s.open(store_fname);

	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	wstring txt = generate_text(s, length, order);
	replace(txt.begin(), txt.end(), '_', ' ');
	wofs << txt;
	s.close(store_fname);
	wofs.close();
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

	s.close(store_fname);
}
