#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <string>
#include "Storing/store.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// Splits text in array of words

vector<string> split(string txt);

// Splits text in vector of chars 

vector<string> split_chars(string txt);

// Stores number of	conditional appearences of sequence (of length [order]) of chars/words in [txt] into [s]

void assimilate_text(string txt, Store &s, int order, vector<string>(*text_splitter)(string));

// Returns array of simplified strings from text file

string read_text(char* filename);

#endif
