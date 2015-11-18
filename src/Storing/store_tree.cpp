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
void Store_tree::open(char* filename){
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

void Store_tree::close(char* filename){
	FILE* f = fopen(filename, "w");
	if (f == 0){
		cerr << "ERROR : couldn't open file " << filename << endl;
	}
	else{
		hits->write_to_file(f);
	}
	fclose(f);
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

void Store_tree::create(queue<string> seq, llu nb){
	hits->add(seq, nb);
}

// Access or modify hits
llu Store_tree::get_hits(queue<string> seq){
	return hits->get(seq);
}
void Store_tree::add_hits(queue<string> seq, llu nb){
	hits->add(seq, nb);

}

// Access proba
double Store_tree::get_proba(queue<string> seq){
	return hits->get_p(seq);
}

string Store_tree::next(queue<string> seq){
	return hits->get_rand(seq);
}

double Store_tree::entropy(int order){
	return hits->entropy(order);
}

void Store_tree::print_tree(){
	hits->print(&cout);
}
