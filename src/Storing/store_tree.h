#ifndef STORE_TREE_H
#define STORE_TREE_H

#include "store.h"
#include "simple_tree.h"

class Store_tree : public Store
{
public:
	Store_tree();

	~Store_tree();

	// Open and close store
	virtual void open(char* filename);
	virtual void close(char* filename);

	// Check if store is initialized (e.g. table was created, etc.) and initializes it
	virtual bool is_init();
	virtual void init();

	// Check if word exists and insert it
	virtual bool exists(queue<string> seq);
	virtual void create(queue<string> seq, llu nb);

	// Access or modify hits
	virtual llu  get_hits(queue<string> seq);
	virtual void add_hits(queue<string> seq, llu nb);

	// Access proba
	virtual double get_proba(queue<string> seq);

	// Generate next word/char in a serie randomly
	virtual string next(queue<string> seq);

	// Calculate entropy
	virtual double entropy(int order);

	// For debug
	void print_tree();

private:
	Simple_tree* hits;
};
#endif // !STORE_TREE_H
