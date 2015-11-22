#ifndef SIMPLE_TREE_H
#define SIMPLE_TREE_H

#include <queue>
#include <iostream>
#include <string>
#include <random>
#include "../def.h"

using namespace std;

class Simple_tree
{
public:

	char hd;
	vector<Simple_tree*> sons;
	llu freq;
	llu  sons_tot;

	Simple_tree();
	Simple_tree(char str, llu  f);

	~Simple_tree();

	void read_from_file(FILE* f);

	void write_to_file(FILE* f);

	void print(ostream* ofs);

	void add(queue<char> seq, llu f);

	bool is_in(queue<char> seq);

	llu get(queue<char> seq);

	double get_p(queue<char> seq);

	char get_rand(queue<char> prev);

	double entropy(int order);


private:



};
#endif // !SIMPLE_TREE_H
