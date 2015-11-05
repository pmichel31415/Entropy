#ifndef SIMPLE_TREE_H
#define SIMPLE_TREE_H

#include <queue>
#include <iostream>
#include <string>
#include <random>

using namespace std;

class Simple_tree
{
public:

	wstring hd;
	vector<Simple_tree*> sons;
	int freq;
	int sons_tot;

	Simple_tree();
	Simple_tree(wstring str, int f);

	~Simple_tree();

	void read_from_file(wistream* ifs);

	void write_to_file(wostream* ofs);

	void add(queue<wstring> seq, int f);

	bool is_in(queue<wstring> seq);

	int get(queue<wstring> seq);

	double get_p(queue<wstring> seq);

	wstring get_rand(queue<wstring> prev);

	double entropy(int order);


private:
	
	
	
};
#endif // !SIMPLE_TREE_H
