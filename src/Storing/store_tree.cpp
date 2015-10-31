#include "store_tree.h"
#include <fstream>

using namespace std;

Store_tree::Store_tree(){
	hits = 0;
}

Store_tree::~Store_tree(){
	delete hits;
}

// Open and close store
void Store_tree::open(string filename){
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open() || !ifs.good()){
		cerr << "ERROR : couldn't load file " << filename << endl;
	}
	else{
		hits = new Simple_tree("", 0);
		hits->read_from_file(&ifs);
	}
	ifs.close();
}

void Store_tree::close(string filename){
	ofstream ofs;
	ofs.open(filename);
	if (!ofs.is_open() || !ofs.good()){
		cerr << "ERROR : couldn't open file " << filename << endl;
	}
	else{
		hits->write_to_file(&ofs);
	}
	ofs.close();
}

// Check if store is initialized (e.g. table was created, etc.) and initializes it
bool Store_tree::is_init(){
	return !(hits == 0);
}

void Store_tree::init(){
	hits = new Simple_tree("", 0);
}

// Check if word exists and insert it
bool Store_tree::exists(queue<string> seq){
	return hits->is_in(seq);
}

void Store_tree::create(queue<string> seq, int nb){
	hits->add(seq, nb);
}

// Access or modify hits
int Store_tree::get_hits(queue<string> seq){
	return hits->get(seq);
}
void Store_tree::add_hits(queue<string> seq, int nb){
	hits->add(seq, nb);

}

// Access proba
double Store_tree::get_proba(queue<string> seq){
	return hits->get_p(seq);
}