#ifndef GEN_H
#define GEN_H

#include "Storing/store.h"
#include <iostream>

void add_next_char(wstring& text, Store& s, int order);

wstring generate_text(Store& s, int size, int order);

#endif