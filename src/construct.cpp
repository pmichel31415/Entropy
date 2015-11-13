#include "construct.h"

// Split string in array with delimiter

vector<string> split(string str) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, '_')) {
		tok.push_back('_');
		internal.push_back(tok);
	}

	return internal;
}

// Split string in queue of chars (strings)

vector<string> split_chars(string str) {
	vector<string> internal(str.length());
	for (int i = 0; i < str.size(); i++){
		internal[i] = str.substr(i, 1);
	}

	return internal;
}

// Get [length] words/chars up to [index] in [txt] and return a string queue

queue<string> get_seq(vector<string> tab, int index, int length){
	queue<string> seq;
	int beg, end = index;
	if (index < length){
		beg = 0;
	}
	else{
		beg = index - length;
	}

	for (int i = beg; i <= end; i++){
		seq.push(tab[i]);
	}

	return seq;
}


// Stores number of	conditional appearences of sequence (of length [order]) of chars in [txt] into [s]

void assimilate_text(string txt, Store &s, int order, vector<string>(*text_splitter)(string)){
	string chars;
	queue<string> seq;
	vector<string> tab = text_splitter(txt);
	for (int i = 0; i < tab.size(); i++){
		seq = get_seq(tab, i, order);
		s.add_hits(seq, 1);
	}
	cerr << "ok" << endl;
}

// Checks if char is either blank (tab/space/rc/eol), a point, an apostrophy or a lower/upper case letter

bool is_acceptable(char c){
	bool is_blank = (c == 32) || (c == 9) || (c == 10) || (c == 13);
	bool is_point = c == 46;
	bool is_apos = c == 39;
	bool is_upper_c = (c > 64) && (c < 91);
	bool is_lower_c = (c > 96) && (c < 123);

	return is_blank || is_point || is_upper_c || is_lower_c;
}

// Checks if character denotes the end of a sentence

bool is_point(char c){
	return c == 46;
}

// Normalizes letter to upper case

void to_upper_c(char& c){
	if ((c > 96) && (c < 123)){
		c -= 32;
	}
}

// Normalizes blanks to space

void blank_to_space(char& c){
	if ((c == 9) || (c == 10) || (c == 13) || (c == 32)){
		c = 95;
	}
}

bool check_blank(string str, char c){
	return str.size() == 0 || str[str.size() - 1] != 95 || c != 95;
}

// Returns array of simplified strings from text file

string read_text(char* filename){
	string buff_s = "";
	char buff;
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open() || !ifs.good()){
		cerr << "ERROR : couldn't load file " << filename << endl;
	}
	else{
		while (ifs >> noskipws >> buff){
			blank_to_space(buff);
			if (check_blank(buff_s, buff))
				buff_s.push_back(buff);
		}
	}

	ifs.close();
	return buff_s;
}
