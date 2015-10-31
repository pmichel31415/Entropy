#include "construct.h"

queue<string> split(string str, char delimiter) {
	queue<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push(tok);
	}

	return internal;
}

queue<string> split_chars(string str) {
	queue<string> internal;
	for (int i = 0; i < str.size(); i++){
		internal.push(str.substr(i,1));
	}

	return internal;
}


queue<string> get_char_seq(string txt, int index, int length){
	if (index < length){
		return split_chars(txt.substr(0, index));
	}
	else{
		return split_chars(txt.substr(index - length, length));
	}
}

void assimilate_text(string txt, Store &s, int order){
	string chars;
	queue<string> seq;
	for (int i = 1; i <= txt.length(); i++){
		seq = get_char_seq(txt, i, order);
		s.add_hits(seq, 1);
	}
}

bool is_acceptable(char c){
	bool is_blank = (c == 32) || (c == 9) || (c == 10) || (c == 13);
	bool is_point = c == 46;
	bool is_apos = c == 39;
	bool is_upper_c = (c > 64) && (c < 91);
	bool is_lower_c = (c > 96) && (c < 123);

	return is_blank || is_point || is_upper_c || is_lower_c;
}
bool is_point(char c){
	return c == 46;
}

void to_upper_c(char& c){
	if ((c > 96) && (c < 123)){
		c -= 32;
	}
}

void blank_to_space(char& c){
	if ((c == 9) || (c == 10) || (c == 13)){
		c = 32;
	}
}

vector<string> read_text(string filename){
	vector<string> ret;
	string buff_s = "";
	char buff;
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open() || !ifs.good()){
		cerr << "ERROR : couldn't load file " << filename << endl;
	}
	else{
		while (ifs.get(buff)){
			if (is_acceptable(buff)){
				to_upper_c(buff);
				blank_to_space(buff);
				buff_s.push_back(buff);
				if (is_point(buff)){
					ret.push_back(buff_s);
					buff_s = "";
				}
			}
		}
	}

	ifs.close();
	return ret;
}