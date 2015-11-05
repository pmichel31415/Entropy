#ifndef ENTROPY_H
#define ENTROPY_H

#include "Storing/store.h"
#include "construct.h"
#include "gen.h"
#include <algorithm>

void assim(Store& s, wstring store_fname, wstring text_fname, int order);

void gen(Store& s, wstring store_fname, wstring output_fname, int length, int order);

void calc(Store& s, wstring store_fname, int order);


#endif // !ENTROPY_H

