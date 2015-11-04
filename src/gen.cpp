#include "gen.h"

void add_next_char(wstring& text, Store& s, int order){
	queue<wstring> seq;
	wstring next;
	int i0 = order <= text.size() ? text.size() - order : 0;

	for (int i = i0; i < text.size(); i++){
		seq.push((wstring)text.substr(i, 1));
	}

	next = s.next(seq);
	text.append(next);
}

wstring generate_text(Store& s, int size, int order){
	wstring txt = L"";
	int length = 0;
	while (length < size){
		add_next_char(txt, s, order);
		length++;
	}
	replace(txt.begin(), txt.end(), '_', ' ');
	return txt;
}