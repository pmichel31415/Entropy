#include "test.h"

void print(queue<string> q){
	while (!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
}


void incr(queue<string> test_q, Store& s){
	if (!s.exists(test_q)){
		print(test_q); cout << "is not in tree, adding..." << endl;
		s.create(test_q, 1);
		cout << "Created" << endl;
	}
	else{
		int h = s.get_hits(test_q);
		print(test_q); cout << "is already in tree with frequence " << h << endl;
		s.add_hits(test_q, 1);
		cout << "Frequence incremented" << endl;
		h = s.get_hits(test_q);
		double p = s.get_proba(test_q);
		print(test_q); cout << "has now been encountered " << h << " times. It's probability of appearence is " << p << endl;
	}
}

void test_tree(){
	Store_tree s;
	cout << "Beginning test" << endl;
	cout << "--------------" << endl;
	s.open("store_tree.txt");
	if (!s.is_init()){
		cerr << "Store is not initialized, initializing..." << endl;
		s.init();
		cerr << "Store initialized!" << endl;
	}

	vector<string> test_queues_1 = {
		"a:b:c",
		"a:b:c",
		"a:b:a",
		"a:c:c",
		"a:b:d"
	};
	vector<string> test_queues_2 = {
		"a",
		"a:b",
		"a:b:c",
		"b:c:c",
		"b:b:d",
		"b:b"
	};

	for (int i = 0; i < test_queues_2.size(); i++){
		incr(split(test_queues_2[i], ':'), s);
	}

	cout << "Closing store" << endl;
	s.close("store_tree.txt");
}

void test_construct(){
	Store_tree s;
	cout << "Beginning test" << endl;
	cout << "--------------" << endl;
	s.open("store_tree.txt");
	if (!s.is_init()){
		cerr << "Store is not initialized, initializing..." << endl;
		s.init();
		cerr << "Store initialized!" << endl;
	}

	vector<string> txt = read_text("poem.txt");
	for (int i = 0; i < txt.size(); i++){
		cout << "Assimilating : " << endl;
		cout << txt[i] << endl << endl;
		assimilate_text(txt[i], s, 3);
	}


	cout << "Closing store" << endl;
	s.close("store_tree.txt");
}
