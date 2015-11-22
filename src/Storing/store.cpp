#include "store.h"

Store::Store(){}
Store::~Store(){}

void Store::open(char* filename){}
void Store::close(char* filename){}

bool Store::is_init(){ return false; }
void Store::init(){}

bool Store::exists(queue<char> seq){ return false; }
void Store::create(queue<char> seq, llu nb){}

llu Store::get_hits(queue<char> seq){ return 0; }
void Store::add_hits(queue<char> seq, llu nb){}

double Store::get_proba(queue<char> seq){ return 0.0; }
char Store::next(queue<char> seq){ return 0; }

double Store::entropy(int order){ return 0; }
