#include <string>
using namespace std;

struct hits{
	int n;
	int tot;
	double proba;
};

class Store
{
public:
	Store();
	~Store();

	// Open and close store
	virtual void open(string filename) = 0;
	virtual void close(string filename) = 0;

	// Check if store is initialized (e.g. table was created, etc.) and initializes it
	virtual bool is_init() = 0;
	virtual void init() = 0;

	// Check if word exists and insert it
	virtual bool exists(string word) = 0;
	virtual void create(string word, hits h) = 0;

	// Access or modify hits
	virtual hits get_hits(string word) = 0;
	virtual void set_hits(string word, hits h) = 0;

	// Access proba
	virtual double get_proba(string word) = 0;

	// calculate all proba
	virtual void calculate_probas() = 0;

private:

};
