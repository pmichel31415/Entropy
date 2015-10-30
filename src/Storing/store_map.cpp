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
		int buff_n;
		ifs.open(filename);

		if (!ifs.is_open() || !ifs.good()){
			cerr << "ERROR : couldn't load file " << filename << endl;
		}
		else{
			cin >> tot;
			while (cin >> buff_word){
				cin >> buff_n;
				hits.insert(pair<string, int>(buff_word, buff_n));
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
			for (pair<string, int> p : hits){
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
		return hits.find(word) != hits.end();
	}

	void create(string word, int nb){
		hits.insert(pair<string, int>(word, nb));
		tot += nb;
	}

	// Access or modify hits
	int get_hits(string word){
		return hits[word];
	}
	void set_hits(string word, int nb){
		tot += nb - hits[word];
		hits[word] = nb;
		
	}

	// Access proba
	double get_proba(string word){
		return ((float)hits[word])/((double)tot);
	}



private:
	int tot;
	map<string, int> hits;
};
