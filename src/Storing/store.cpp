#include "store.h"

Store::Store(){}
Store::~Store(){}

void Store::open(string filename){}
void Store::close(string filename){}

bool Store::is_init(){ return false; }
void Store::init(){}

bool Store::exists(queue<string> seq){ return false; }
void Store::create(queue<string> seq, int nb){}

int Store::get_hits(queue<string> seq){ return 0; }
void Store::add_hits(queue<string> seq, int nb){}

double Store::get_proba(queue<string> seq){ return 0.0; }