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
		double buff_p;
		ifs.open(filename);

		if (!ifs.is_open() || !ifs.good()){
			cerr << "ERROR : couldn't load file " << filename << endl;
		}
		else{
			while (cin >> buff_word){
				cin >> buff_p;
				proba.insert(pair<string, double>(buff_word, buff_p));
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
			for (pair<string, double> p : proba){
				cout << p.first << " " << p.second << endl;
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

	virtual void create(string word, double p){
		proba.insert(pair<string, double>(word, p));
	}

	// Access or modify proba
	virtual double get_proba(string word){
		return proba[word];
	}
	void set_proba(string word, double p){
		proba[word] = p;
	}

private:
	map<string, double> proba;
};
