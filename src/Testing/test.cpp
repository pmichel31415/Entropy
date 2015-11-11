#include "test.h"


// Split string in array with delimiter

queue<wstring> split(wstring str, wchar_t delimiter) {
	queue<wstring> internal;
	wstringstream ss(str); // Turn the string into a stream.
	wstring tok;
	int i0 = 0;
	for (int i = 0; i < str.size(); i++){
		if (str.at(i) == delimiter){
			tok = str.substr(i0, i - i0);
			internal.push(tok);
			i0 = i + 1;
		}
	}

	return internal;
}


void print(queue<wstring> q){
	while (!q.empty()){
		wcout << q.front() << " ";
		q.pop();
	}
}


void incr(queue<wstring> test_q, Store& s){
	if (!s.exists(test_q)){
		print(test_q); wcout << "is not in tree, adding..." << endl;
		s.create(test_q, 1);
		wcout << "Created" << endl;
	}
	else{
		int h = s.get_hits(test_q);
		print(test_q); wcout << "is already in tree with frequence " << h << endl;
		s.add_hits(test_q, 1);
		wcout << "Frequence incremented" << endl;
		h = s.get_hits(test_q);
		double p = s.get_proba(test_q);
		print(test_q); wcout << "has now been encountered " << h << " times. It's probability of appearence is " << p << endl;
	}
}

void test_tree(){
	Store_tree s;
	wcout << "Beginning test" << endl;
	wcout << "--------------" << endl;
	s.open("store_tree.txt");
	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	vector<wstring> test_queues_1 = {
		L"a:b:c",
		L"a:b:c",
		L"a:b:a",
		L"a:c:c",
		L"a:b:d"
	};
	vector<wstring> test_queues_2 = {
		L"a",
		L"a:b",
		L"a:b:c",
		L"b:c:c",
		L"b:b:d",
		L"b:b"
	};

	for (int i = 0; i < test_queues_2.size(); i++){
		incr(split(test_queues_2[i], L':'), s);
	}

	wcout << "Closing store" << endl;
	s.close("store_tree.txt");
}

void test_construct(){
	Store_tree s;
	wcout << "Beginning test" << endl;
	wcout << "--------------" << endl;
	wcout << "Opening store_tree.txt : " << endl;
	s.open("store_tree.txt");
	wcout << "Opened " << endl;
	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}

	wstring txt = read_text("trois_mousquetaires.txt");
	wcout << "Assimilating : " << endl;
	wcout << txt << endl << endl;
	assimilate_text(txt, s, 4);



	wcout << "Closing store" << endl;
	s.close("store_tree.txt");
}

void test_gen(){
	Store_tree s;

	srand(time(0));

	wcout << "Beginning test" << endl;
	wcout << "--------------" << endl;
	wcout << "Opening store_tree.txt : " << endl;
	s.open("store_tree.txt");
	wcout << "Opened " << endl;
	if (!s.is_init()){
		wcerr << "Store is not initialized, initializing..." << endl;
		s.init();
		wcerr << "Store initialized!" << endl;
	}
	wcout << "Generating first text : Markov model of order 0 : " << endl;
	wcout << "------------------------------------------------- " << endl;
	wcout << generate_text(s, 200, 0) << endl << endl;
	wcout << "Generating first text : Markov model of order 1 : " << endl;
	wcout << "------------------------------------------------- " << endl;
	wcout << generate_text(s, 200, 1) << endl << endl;
	wcout << "Generating first text : Markov model of order 2 : " << endl;
	wcout << "------------------------------------------------- " << endl;
	wcout << generate_text(s, 200, 2) << endl << endl;
	wcout << "Generating first text : Markov model of order 3 : " << endl;
	wcout << "------------------------------------------------- " << endl;
	wcout << generate_text(s, 200, 3) << endl << endl;

	wcout << "Closing store" << endl;
	s.close("store_tree.txt");
}
