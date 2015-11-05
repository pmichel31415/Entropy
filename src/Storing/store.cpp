#include "store.h"

Store::Store(){}
Store::~Store(){}

void Store::open(wstring filename){}
void Store::close(wstring filename){}

bool Store::is_init(){ return false; }
void Store::init(){}

bool Store::exists(queue<wstring> seq){ return false; }
void Store::create(queue<wstring> seq, int nb){}

int Store::get_hits(queue<wstring> seq){ return 0; }
void Store::add_hits(queue<wstring> seq, int nb){}

double Store::get_proba(queue<wstring> seq){ return 0.0; }
wstring Store::next(queue<wstring> seq){ return L""; }

double Store::entropy(int order){ return 0; }