#include "gen.h"

string generate_text(Store& s, int target_length, int order){
	string txt = "";
	int length = 0;
	queue<string> seq;
	string next;
	while (length < target_length){
		next = s.next(seq);
		if (seq.size() >= order)
			seq.pop();

		seq.push(next);
		length++;

		txt.append(next);
	}

	replace(txt.begin(), txt.end(), '_', ' ');
	return txt;
}
