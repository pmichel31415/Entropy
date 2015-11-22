#ifndef STORE_H
#define STORE_H

#include <string>
#include <queue>
#include "../def.h"

using namespace std;


class Store
{
public:
	Store();
	~Store();

	// Open and close store
	virtual void open(char* filename);
	virtual void close(char* filename);

	// Check if store is initialized (e.g. table was created, etc.) and initializes it
	virtual bool is_init();
	virtual void init();

	// Check if word exists and insert it
	virtual bool exists(queue<char> seq);
	virtual void create(queue<char> seq, llu nb);

	// Access or modify hits
	virtual llu get_hits(queue<char> seq);
	virtual void add_hits(queue<char> seq, llu nb);

	// Access proba
	virtual double get_proba(queue<char> seq);

	// Generate next word/char in a serie randomly
	virtual char next(queue<char> seq);

	// Calculate entropy
	virtual double entropy(int order);


private:

};
#endif
