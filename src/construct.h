#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <string>
#include "Storing/store.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// Stores number of	conditional appearences of sequence (of length [order]) of words in [txt] into [s]

void assimilate_text(string txt, Store &s, int order);

// Stores number of	conditional appearences of sequence (of length [order]) of words in [txt] into [s]

void assimilate_text_chars(string txt, Store &s, int order);

// Returns array of simplified strings from text file

string read_text(char* filename);

#endif
