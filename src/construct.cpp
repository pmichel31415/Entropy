#include "construct.h"

// Split string in queue of chars (strings)

queue<wstring> split_chars(wstring str) {
	queue<wstring> internal;
	for (int i = 0; i < str.size(); i++){
		internal.push(str.substr(i, 1));
	}

	return internal;
}

// Get [length] chars up to [index] in [txt] and return a string queue

queue<wstring> get_char_seq(wstring txt, int index, int length){
	if (index < length){
		return split_chars(txt.substr(0, index));
	}
	else{
		return split_chars(txt.substr(index - length, length));
	}
}

// Stores number of	conditional appearences of sequence (of length [order]) of chars in [txt] into [s]

void assimilate_text(wstring txt, Store &s, int order){
	wstring chars;
	queue<wstring> seq;
	for (int i = 1; i <= txt.length(); i++){
		seq = get_char_seq(txt, i, order);
		s.add_hits(seq, 1);
	}
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

void blank_to_space(wchar_t& c){
	if ((c == 9) || (c == 10) || (c == 13) || (c == 32)){
		c = 95;
	}


}

bool check_blank(wstring str, wchar_t c){
	return str.size() == 0 || str[str.size() - 1] != 95 || c != 95;
}

// Returns array of simplified strings from text file

wstring read_text(wstring filename){
	wstring buff_s = L"";
	wchar_t buff;
	wifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open() || !ifs.good()){
		wcerr << "ERROR : couldn't load file " << filename << endl;
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