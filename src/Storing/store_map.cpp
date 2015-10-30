#include "store.h"
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class Store_map : Store
{
public:
	Store_map();
	~Store_map();

	// Open and close store
	void open(string filename){
		ifstream ifs;
		string buff_word;
		int buff_n, buff_tot;
		double buff_p;
		ifs.open(filename);

		if (!ifs.is_open() || !ifs.good()){
			cerr << "ERROR : couldn't load file " << filename << endl;
		}
		else{
			while (cin >> buff_word){
				cin >> buff_n;
				cin >> buff_tot;
				cin >> buff_p;
				proba.insert(pair<string, hits>(buff_word, { buff_n, buff_tot, buff_p }));
			}

		}
		ifs.close();
	}

	void close(string filename){
		ofstream ofs;

		if (!ofs.is_open() || !ofs.good()){
			cerr << "ERROR : couldn't open file " << filename << endl;
		}
		else{
			for (pair<string, hits> p : proba){
				cout << p.first << " " << p.second.n << " " << p.second.tot << " " << p.second.proba << endl;
			}
		}
		ofs.close();
	}

	// Check if store is initialized (e.g. table was created, etc.) and initializes it
	bool is_init(){
		return true;
	}

	void init(){}

	// Check if word exists and insert it
	bool exists(string word){
		return proba.find(word) != proba.end();
	}

	virtual void create(string word, hits h){
		proba.insert(pair<string, hits>(word, h));
	}

	// Access or modify hits
	virtual hits get_hits(string word){
		return proba[word];
	}
	void set_hits(string word, hits h){
		proba[word] = h;
	}

	// Access proba
	double get_proba(string word){
		return proba[word].proba;
	}

	// calculate all proba
	void calculate_probas(){
		for (pair<string, hits> p : proba){
			p.second.proba = ((float)p.second.n) / ((float)p.second.tot);
		}
	}


private:
	map<string, hits> proba;
};
