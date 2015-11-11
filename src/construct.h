#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <string>
#include "Storing/store.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// Get [length] chars up to [index] in [txt] and return a string queue

queue<wstring> get_char_seq(wstring txt, int index, int length);

// Stores number of	conditional appearences of sequence (of length [order]) of chars in [txt] into [s]

void assimilate_text(wstring txt, Store &s, int order);

// Returns array of simplified strings from text file

wstring read_text(char* filename);

#endif
