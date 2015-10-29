class Store
{
public:
	Store();
	~Store();

	// Open and close store
	virtual void open() = 0;
	virtual void close() = 0;

	// Check if store is initialized (e.g. table was created, etc.) and initializes it
	virtual bool is_init() = 0;
	virtual bool init() = 0;

	// Check if word exists and insert it
	virtual bool exists() = 0;
	virtual bool create() = 0;

	// Access or modify proba
	virtual double get_proba() = 0;
	virtual void set_proba() = 0;

private:

};
