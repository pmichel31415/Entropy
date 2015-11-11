#ifndef ENTROPY_H
#define ENTROPY_H

#include "Storing/store.h"
#include "construct.h"
#include "gen.h"
#include <algorithm>

void assim(Store& s, char* store_fname, char* text_fname, int order);

void gen(Store& s, char* store_fname, char* output_fname, int length, int order);

void calc(Store& s, char* store_fname, int order);


#endif // !ENTROPY_H

