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
	cout << "Opening store_tree.txt : " << endl;
	s.open("store_tree.txt");
	cout << "Opened " << endl;
	if (!s.is_init()){
		cerr << "Store is not initialized, initializing..." << endl;
		s.init();
		cerr << "Store initialized!" << endl;
	}

	string txt = read_text("trois_mousquetaires.txt");
	cout << "Assimilating : " << endl;
	cout << txt << endl << endl;
	assimilate_text(txt, s, 4);



	cout << "Closing store" << endl;
	s.close("store_tree.txt");
}

void test_gen(){
	Store_tree s;

	srand(time(0));

	cout << "Beginning test" << endl;
	cout << "--------------" << endl;
	cout << "Opening store_tree.txt : " << endl;
	s.open("store_tree.txt");
	cout << "Opened " << endl;
	if (!s.is_init()){
		cerr << "Store is not initialized, initializing..." << endl;
		s.init();
		cerr << "Store initialized!" << endl;
	}
	cout << "Generating first text : Markov model of order 0 : " << endl;
	cout << "------------------------------------------------- " << endl;
	cout << generate_text(s, 200, 0) << endl << endl;
	cout << "Generating first text : Markov model of order 1 : " << endl;
	cout << "------------------------------------------------- " << endl;
	cout << generate_text(s, 200, 1) << endl << endl;
	cout << "Generating first text : Markov model of order 2 : " << endl;
	cout << "------------------------------------------------- " << endl;
	cout << generate_text(s, 200, 2) << endl << endl;
	cout << "Generating first text : Markov model of order 3 : " << endl;
	cout << "------------------------------------------------- " << endl;
	cout << generate_text(s, 200, 3) << endl << endl;

	cout << "Closing store" << endl;
	s.close("store_tree.txt");
}
