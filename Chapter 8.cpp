//------------------------------------------------------------------------------EXERCISE 8.1-8.2
/*
#include <iostream>
#include <string>
#include <vector>
#include "Sales_Data.h"
using namespace std;
istream& read(istream& i,vector<int>& container) {
	int x;
	while (i >> x) {
		container.push_back(x);
	}
	return i;
}

int main() {
	istream& stream = cin;
	vector<int> numbers;
	do {
		stream.clear();
		stream.ignore();
		stream.setstate(0);
		read(stream,numbers);
		
	} while (!stream.eof());
	for (auto &m : numbers) {
		cout << m << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}*/
//------------------------------------------------------------------------------EXERCISE 8.4
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ifstream i("data.txt");
	if (i) {
		string input;
		vector<string> inputs;
		while (getline(i, input)) {
			inputs.push_back(input);
		}
		for (auto m : inputs) {
			cout << m << " " << endl;
		}
	}
	system("pause");
	return 0;
}*/
//------------------------------------------------------------------------------EXERCISE 8.5
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ifstream i("data.txt");
	if (i) {
		string input;
		vector<string> inputs;
		while (i >> input) {
			inputs.push_back(input);
		}
		for (auto m : inputs) {
			cout << m << " " << endl;
		}
	}
	system("pause");
	return 0;
}*/
//------------------------------------------------------------------------------EXERCISE 8.6
/*
int main(int argc, char* argv[]) {....
ifstream input (argv[2]);
Sales_data total = { input };
*/
//------------------------------------------------------------------------------EXERCISE 8.7-8.8
//-----------------WE USED SALES_DATA.H FROM CHAPTER 7, NEAR IMPLENTATION MODEL.
/*#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Sales_Data.h"
using namespace std;
int main(int argc, char* argv[]) {
	ifstream input (argv[1]);
	ofstream output(argv[2],ostream::app);
	Sales_data total = { input };
	Sales_data transaction;
	while (read(input, transaction)) {//read other inputs.
		if (total.isbn() == transaction.isbn()) {
			total.combine(transaction);
		}
		else {
			print(output, total) << endl;
			total = transaction;
		}
	}
	print(output, total) << endl;

	system("pause");
	return 0;
}*/
//------------------------------------------------------------------------------EXERCISE 8.9
/*#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
istream& read(istream& i, vector<string>& container) {
	string x;
	
	while (getline(i,x)) {
		container.push_back(x);
		istringstream stuff(x);
		string m;
			while (stuff >> m) {
				cout << m << endl;
			}
	}
	return i;
}

int main() {
	istream& stream = cin;
	vector<string> numbers;
	do {
		stream.clear();
		stream.ignore();
		stream.setstate(0);
		read(stream, numbers);

	} while (!stream.eof());
	for (auto &m : numbers) {
		cout << m << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}*/
//------------------------------------------------------------------------------EXERCISE 8.10
/*
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream input("data.txt");
	vector<string> words;
	string word;
	if (input) {
		while (getline(input, word)) {
			words.push_back(word);
			istringstream data(word);
			string a;
			while (data >> a) {
				cout << a << endl;
			}
		}
	}
	else {
		cerr << "Couldn't find file" << endl;
	}
	system("pause");
	return 0;
}*/
//------------------------------------------------------------------------------EXERCISE 8.13
/*
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string line, word; 
		vector<PersonInfo> people; 
		ifstream input("data.txt");
		istringstream record;
	while (getline(input, line)) {
		PersonInfo info; 
		record = istringstream(line);
		record >> info.name; 
		while (record >> word) 
			info.phones.push_back(word); 
		people.push_back(info); 
	}
	for (auto m : people) {
		cout << m.name << endl;
	}
	system("pause");
	return 0;
}*/
