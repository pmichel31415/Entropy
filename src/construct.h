#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <string>
#include "Storing/store.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

queue<string> get_char_seq(string txt, int index, int length);

void assimilate_text(string txt, Store &s, int order);

vector<string> read_text(string filename);

#endif