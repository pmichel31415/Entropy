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
	virtual void open(string filename);
	virtual void close(string filename);

	// Check if store is initialized (e.g. table was created, etc.) and initializes it
	virtual bool is_init();
	virtual void init();

	// Check if word exists and insert it
	virtual bool exists(queue<string> seq);
	virtual void create(queue<string> seq, int nb);

	// Access or modify hits
	virtual int get_hits(queue<string> seq);
	virtual void add_hits(queue<string> seq, int nb);

	// Access proba
	virtual double get_proba(queue<string> seq);

	// Generate next word/char in a serie randomly
	virtual string next(queue<string> seq);


private:
	Simple_tree* hits;
};
#endif // !STORE_TREE_H
