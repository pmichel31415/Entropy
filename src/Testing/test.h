#ifndef TEST_H
#define TEST_H

#include "../Storing/store.h"
#include "../Storing/store_tree.h"
#include "../construct.h"
#include <sstream>

void print(queue<string> q);

queue<string> split(string str, char delimiter);

void incr(queue<string> test_q, Store& s);

void test_tree();
void test_construct();

#endif
