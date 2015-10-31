#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <string>
#include "Storing/store.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// Get [length] chars up to [index] in [txt] and return a string queue

queue<string> get_char_seq(string txt, int index, int length);

// Stores number of	conditional appearences of sequence (of length [order]) of chars in [txt] into [s]

void assimilate_text(string txt, Store &s, int order);

// Returns array of simplified strings from text file

vector<string> read_text(string filename);

#endif