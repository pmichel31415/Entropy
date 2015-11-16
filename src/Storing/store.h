#ifndef STORE_H
#define STORE_H

#include <string>
#include <queue>
#pragma once
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
	virtual bool exists(queue<string> seq);
	virtual void create(queue<string> seq, long long int nb);

	// Access or modify hits
	virtual long long int get_hits(queue<string> seq);
	virtual void add_hits(queue<string> seq, long long int nb);

	// Access proba
	virtual double get_proba(queue<string> seq);

	// Generate next word/char in a serie randomly
	virtual string next(queue<string> seq);

	// Calculate entropy
	virtual double entropy(int order);


private:

};
#endif
