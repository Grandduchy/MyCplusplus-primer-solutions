//EXERCISE 17.4
/*
bool compareISBN(const Sales_data& a, const Sales_data &b) {
	return a.isbn() == b.isbn();
}

typedef std::tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> match;
	for (auto begin = files.begin(); begin != files.end();begin++) {
		auto iters = std::equal_range(begin->begin(), begin->end(), Sales_data(book),compareISBN);
		if (iters.first != iters.second) {
			matches found = std::make_tuple(iters.first - begin->begin(), iters.first, iters.second);
			match.push_back( found );
		}

	}
	
	
	return match;
}
*/
//EXERCISE 17.5
/*
bool compareISBN(const Sales_data& a, const Sales_data &b) {
	return a.isbn() == b.isbn();
}

typedef std::pair<vector<Sales_data>::size_type, std::pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches;
vector<matches> findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<matches> match;
	for (auto begin = files.begin(); begin != files.end();begin++) {
		auto iters = std::equal_range(begin->begin(), begin->end(), Sales_data(book),compareISBN);
		if (iters.first != iters.second) {
			auto found_iters = std::make_pair(iters.first, iters.second);
			auto found = std::make_pair(iters.first - begin->begin(), found_iters);
			match.push_back( found );
		}

	}
	return match;
}
*/
//EXERCISE 17.10
/*
bitset<21>bits;
	int n = 0;
	while (cin >> n) {
		if (n <= 21) {
			bits[n-1].flip();
		}
		else {
			cout << n << " invalid." << endl;
		}
	}
	cout << "bits : " << bits << endl;
	cout << bits.to_ulong() << endl;
*/
//EXERCISE 17.11-17.13
/*
void update(bitset<10>& bits, const short& q_n, bool fot) {
	if (fot) {
		bits[q_n] = 1;
	}
	else {
		bits[q_n] = 0;
	}
}

bool checkanswer(bitset<10>& bits, const short& q_n, const char& c) {
	if (bits[q_n] == 1 && c == 't') {
		return true;
	}
	else if (bits[q_n] == 0 && c == 'f') {
		return false;
	}
}

int main() {
	bitset<10> quiz_results;
	bitset<10> answers("0111010101");
	cout << "t/f" << endl;
	char x;
	cin >> x;
	update(quiz_results, 0, checkanswer(answers, 0,x));
	cout << quiz_results.to_ulong() << endl;
	system("pause");
	return 0;
}
*/
//EXERCISE 17.15
/*
int main() {

	cout << "Enter a word, accepting : i before e except after c" << endl;
	string text;
	getline(cin, text);
	try {
		string patternString("[^c]ei");
		std::smatch s;
		std::regex pattern(patternString,std::regex_constants::icase);
		std::regex_search(text, s, pattern);
		if (s.empty()) {
			cout << "Text is not valid, rule was not followed. " << endl;
		}
		else {
			cout << "Rule followed, returned:\n" << s.str() << endl;
		}
	}
	catch (std::regex_error e) {
		cout << e.what() << "\n" << e.code() << endl;
	}

	system("pause");
	return 0;
}
*/
//EXERCISE 17.17
/*
int main() {
	cout << "Enter a word, accepting : i before e except after c" << endl;
	string text;
	string line;
	while (getline(cin, line)) {
		text.append(line);
	}
	try {
		string patternString("[^c]ei");
		std::smatch s;
		std::regex pattern(patternString, std::regex_constants::icase);
		std::regex_search(text, s, pattern);
		if (s.empty()) {
			cout << "Text is not valid, rule was not followed. " << endl;
		}
		else {

			for (std::sregex_iterator regBegin(text.begin(), text.end(), pattern), regEnd; regBegin != regEnd; regBegin++) {
				cout << regBegin->prefix().str().substr(regBegin->prefix().str().size()-10);
				cout << "   >>>> " << regBegin->str() << " <<<<   ";
				cout << regBegin->suffix().str().substr(0, 10) << endl;
			}

		}
	}
	catch (std::regex_error e) {
		cout << e.what() << "\n" << e.code() << endl;
	}

	system("pause");
	return 0;
}
*/
//EXERICSE 17.19 && 17.20 && 17.22
/*

bool validate(const std::smatch& sm) {
	if (sm[1].matched) {
		return sm[3].matched && (sm[4].matched == sm[6].matched);
	}
	else {
		return !sm[3].matched && (sm[4].matched == sm[6].matched);
	}
}

int main() {
	string phoneNumber("123 456 789");
	try {
		string pattern("(\\()?(\\d{3})(\\))?([.\\- ])*(\\d{3})([.\\- ])*(\\d{3})");
		std::regex patt(pattern);
		std::smatch num;
		std::regex_search(phoneNumber,num, patt);
		if (validate(num)) {
			cout << phoneNumber << " is a valid format" << endl;
		}
		else {
			cout << phoneNumber << " is not valid format" << endl;
		}
	}
	catch (std::regex_error e) {
		cout << e.what() << "\n code: " << e.code() << endl;
	}
	system("pause");
	return 0;
}

*/
//EXERCISE 17.21
/*
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;


bool validate(const std::smatch& sm) {
	if (sm[1].matched) {
		return sm[3].matched && (sm[4].matched == sm[6].matched);
	}
	else {
		return !sm[3].matched && (sm[4].matched == sm[6].matched);
	}
}

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string pattern("(\\()?(\\d{3})(\\))?([.\\- ])*(\\d{3})([.\\- ])*(\\d{3})");
	std::regex patt(pattern);
	string line, word; 
		vector<PersonInfo> people; 
		ifstream input("data.txt");
		istringstream record;
	while (getline(input, line)) {
		PersonInfo info; 
		record = istringstream(line);
		record >> info.name; 
		while (record >> word) {
			std::smatch num;
			std::regex_search(word, num, patt);
			if (validate(num))
				info.phones.push_back(word);
		}
			 
		people.push_back(info); 
	}
	for (auto m : people) {
		cout << m.name << endl;
	}
	system("pause");
	return 0;
}
*/
//EXERCISE 17.22
/*
bool validate(const std::smatch& sm) {
	if (sm[2].matched) {
		return sm[3].matched;
	}
	else {
		return true;
	}
}

int main() {
	string zip("12345-6789");
	try {
		string reg("(\\d{5})([-])?(\\d{4})?");
		std::regex pattern(reg);
		std::smatch sm;
		std::regex_search(zip, sm, pattern);
		if (validate(sm)) {
			cout << zip << " is a valid format" << endl;
		}
		else {
			cout << zip << " is not a valid format" << endl;
		}
	}
	catch (std::regex_error e) {
		cout << e.what() << "\n code: " << e.code() << endl;
	}
	system("pause");
	return 0;
}
*/
//EXERCISE 17.27
//ADD AND CHANGE LINE 258 TO:
/*
string format("$1.$3");
cout << std::regex_replace(zip,pattern,format) << " is a valid format" << endl;
*/
//EXERCISE 17.28 - 17.30
/*
unsigned int random(size_t min = 0,size_t max = 0x7fffffff, size_t eng = 0) {
	static std::default_random_engine engine(eng);
	static std::uniform_int_distribution<unsigned> range(min, max);
	return range(engine);
}

int main() {
	int min = 0, max = 0, engine = 0;
	cout << "Enter min number ";
	cin >> min;
	cout << "Enter max number ";
	cin >> max;
	cout << "Do you want a seed? y\n ";
	char x;
	cin >> x;
	if (x == 'y') {
		cout << "enter a seed ";
		cin >> engine;
	}
	cout << "Your random number is " << random(min, max, engine) << endl;
	system("pause");
	return 0;
}
*/
//EXERCISE 17.34
/*
//Table 17.17 IO Manipulators
	cout << "Bool alpha : " << true << "\n-> " << std::boolalpha << true << endl << std::noboolalpha;
	cout << "Show base : in hex: " << std::hex << 25 << "\n-> " << std::showbase << 25 << endl << std::noshowbase << std::dec;
	cout << "Show point : " << 10.0000 << "\n-> " << std::showpoint << 10.0000 << endl << std::noshowpoint;
	cout << "Show pos(positive) : " << 20 << "\n-> " << std::showpos << 20 << endl << std::noshowpos;
	cout << "uppercase : in hex " << std::showbase << std::hex << 50 << "\n-> " << std::uppercase << 50 << endl << std::dec << std::nouppercase << std::noshowbase;
	cout << "Dec Oct Hex : " << std::showbase << 75 << std::oct << "\t" << 75 << std::hex << "\t" <<75 << endl << std::noshowbase << std::dec;
	int i = -16;
	double d = 3.14159;
	cout << "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';
	// pad the first column and std::left-justify all columns
	cout << std::left
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n'
		<< std::right; // restore normal justification
				  // pad the first column and std::right-justify all columns
	cout << std::right
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';
	// pad the first column but put the padding internal to the field
	cout << std::internal
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';
	// pad the first column, using # as the pad character
	cout << std::setfill('#')
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n'
		<< std::setfill(' ');
*/
//EXERCISE 17.37 && 17.38
/*
int main() {
	std::ifstream ifs("Data.txt");
	char strings[100];
	while (ifs.peek() != EOF) {
		ifs.get(strings, 100,'\0');
		cout.write(strings, ifs.gcount());
	}
	system("pause");
	return 0;
}

*/
