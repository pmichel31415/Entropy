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

	string hd;
	vector<Simple_tree*> sons;
	int freq;
	int sons_tot;

	Simple_tree();
	Simple_tree(string str, int f);

	~Simple_tree();

	void read_from_file(istream* ifs);

	void write_to_file(FILE* f);

	void print(ostream* ofs);

	void add(queue<string> seq, int f);

	bool is_in(queue<string> seq);

	int get(queue<string> seq);

	double get_p(queue<string> seq);

	string get_rand(queue<string> prev);

	double entropy(int order);


private:



};
#endif // !SIMPLE_TREE_H
