////----------------------------------------------------------------------------------------------------------EXERCISE 11.3-11.4
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {std::map<string, int> words;
	string word;
	while (cin >> word) {
		for (char& x : word) {
			x = std::tolower(x);
		}
		auto remove = std::remove_if(word.begin(), word.end(), [](const char x) {return x == ',' || x == '.'; });
		string a(word.begin(), remove);
		words[a]++;
	}
	for (auto& m : words) {
		cout << m.first << " : "<<m.second << endl;
	}
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.8
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
#include <iterator>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	std::ostream_iterator<string> os(cout, " ");
	std::map<string, vector<string>> myMap;
	myMap["Lebarge"].push_back("Josh");
	myMap["Derome"].push_back("Jonnathan");
	myMap["Derome"].push_back("Alex");
	for (const auto& x : myMap) {
		cout << x.first << " family : ";
		std::copy(x.second.begin(), x.second.end(), os);
		cout << endl;
	}
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.11
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "Sales_Data.h"
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	set<Sales_data,decltype(compare)*> bookstore(compare);
	bookstore.emplace("Great");
	bookstore.emplace("Than");
	for (const auto m : bookstore) {
		cout << m.isbn() << endl;
	}
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.12
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	string s;
	int n;
	vector<std::pair<string, int>> collection;

	while (cin >> s >> n) {
		collection.push_back(std::pair<string,int>(s, n));
	}
	for (const auto&m : collection) {
		cout << m.first << " : " << m.second << endl;
	}
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.13
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	std::pair<int, int>n;
	auto m = std::make_pair<int,int >(5,5);
	std::pair<int, int> {5, 5};

	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.14
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	std::map<string, vector<std::pair<string,int>>> myMap;
	myMap["Lebarge"].push_back(std::make_pair<string,int>("Josh",5));
	myMap["Derome"].push_back(std::pair<string, int> {"Jonnathan",20});
	myMap["Derome"].push_back(std::pair<string,int>("Alex",10));

	for (const auto& x : myMap) {
		cout << x.first << " family : ";
		std::for_each(x.second.begin(), x.second.end(), [](const auto& a) {
			cout << a.first << " age: " << a.second << " "<< std::flush;
		});
		cout << endl;
	}
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.16
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::flush;
int main() {
	std::map<int, int>numbers = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4} };
	for (std::map<int, int>::const_iterator begin = numbers.begin(); begin != numbers.end(); begin++) {
		cout << begin->second << endl;
	}
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.20
/*
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <set>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::flush;
int main() {
	std::map<string, size_t> word_count; // empty map from string to size_t
	string word;
	while (cin >> word) {
		auto w = word_count.insert({ word,1 });
		if (w.second == false) {
			word_count[word]++;
		}
		for (const auto &w : word_count) {// for each element in the map
									 // print the results
			cout << w.first << " occurs " << w.second
				<< ((w.second > 1) ? " times" : " time") << endl;
		}
	}
		
	
	
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.22
/*
std::map<string,vector<int>> m;
m.insert({ "hi",vector<int>{5,3,1} });
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.28
/*
std::map<string, vector<int>>m;
std::map<string, vector<int>>::iterator f = m.find("hi");
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.31
//THOUGHT //----------------------------------------------------------------------------------------------------------EXERCISE SAID TO REMOVE ALL IN RANGE.
//NOT JUST ONE.
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::flush;
int main() {
	string searchAuthor = "John Doe";
	std::multimap<string, string> author;
	author.emplace("John Doe", "Manifactures of Me.");
	author.emplace("John Doe", "Death of Cannoblism");
	author.emplace("John Doe", "Why me hey?");
	author.emplace("John Doe", "The love of my life");
	author.emplace("Ricky the beast", "Tactical historic warfare");
	author.emplace("Unk", "Mysterious of lucid dreaming.");
	for (auto range = author.equal_range(searchAuthor);
		range.first != range.second; range.first++) {
		author.erase(range.first,range.second);
		break;
	}
	std::for_each(author.begin(), author.end(), [](const auto& a) {
		cout << a.first << " "<< a.second << endl;
	});
	system("pause");
	return 
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.32
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::flush;
int main() {
	string searchAuthor = "John Doe";
	std::multimap<string, string> author;
	author.emplace("John Doe", "Manifactures of Me.");
	author.emplace("John Doe", "Death of Cannoblism");
	author.emplace("John Doe", "Why me hey?");
	author.emplace("John Doe", "The love of my life");
	author.emplace("Ricky the beast", "Tactical historic warfare");
	author.emplace("Unk", "Mysterious of lucid dreaming.");
	std::pair<string,vector<string>> works;
	for (auto range = author.equal_range(searchAuthor);
		range.first != range.second; range.first++) {
		works.first = range.first->first;
		works.second.push_back(range.first->second);
	}
	std::stable_sort(works.second.begin(), works.second.end());
	cout << "Works of " <<works.first << " : "<< endl;
	for (vector<string>::const_iterator begin = works.second.cbegin(); begin != works.second.cend(); begin++) {
		cout << *begin << " ; ";
	}
	cout << endl;
	system("pause");
	return 0;
}
*/
////----------------------------------------------------------------------------------------------------------EXERCISE 11.33
/*
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush;

std::map<string, string> getMap(std::ifstream& ifs);
string transform(std::map<string, string>& myMap, const string& s);

void trans(std::ifstream& ifs, std::ofstream& ofs) {
	std::map<string, string>ourMap = getMap(ifs);
	string entireLine;
	ifs.clear();
	ifs.seekg(0);
	while (getline(ifs,entireLine)) {
		std::istringstream line (entireLine);
		string empty;
		string word;
		while (line >> empty >>word) {
			if (ourMap.find(word) != ourMap.end()) {
				ofs << transform(ourMap, ourMap.find(word)->second) << " " << flush;
			}
			else {
				ofs << word << " " << flush;
			}
		}
		ofs << endl;
	}
	cout << "Values changed successfully." << endl;
}

std::map<string, string> getMap(std::ifstream& ifs) {
	std::map<string, string> x;
	string rule;
	string replace;
	while (ifs >> rule && std::getline(ifs, replace)) {
		if (rule.size() >= 1) {
			x[rule] = replace.substr(1);//remove the space before it.
		}
		else {
			throw std::runtime_error("No rules");
		}
	}
	return x;
}

string transform(std::map<string,string>& myMap, const string& s) {
	if (myMap.find(s) != myMap.end()) {
		return myMap.find(s)->second;
	}
	else {
		return s;
	}
}

int main() {
	std::ifstream ifs("rules.txt");
	std::ofstream ofs("data.txt");
	trans(ifs, ofs);
	system("pause");
	return 0;
}
*/
