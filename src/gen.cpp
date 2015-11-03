#include "gen.h"

void add_next_char(string& text, Store& s, int order){
	queue<string> seq;
	string next;
	int i0 = order <= text.size() ? text.size() - order : 0;

	for (int i = i0; i < text.size(); i++){
		seq.push(text.substr(i, 1));
	}

	next = s.next(seq);
	text.append(next);
}

string generate_text(Store& s, int size, int order){
	string txt = "";
	int length = 0;
	while (length < size){
		add_next_char(txt, s, order);
		length++;
	}
	replace(txt.begin(), txt.end(), '_', ' ');
	return txt;
}