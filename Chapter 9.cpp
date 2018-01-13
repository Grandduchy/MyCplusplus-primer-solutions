//EXERICSE 9.2
/*
#include <list>
#include <deque>
list<deque<int>>;
*/
//EXERCISE 9.4
/*
bool check(vector<int>::iterator begin, vector<int>::iterator end,int num) {
	while (begin != end) {
		if (*begin == num) {
			return true;
		}
		begin++;
	}
	return false;
}*/
//EXERCISE 9.5
/*
vector<int>::iterator check(vector<int> numbers, int num) {
	vector<int>::iterator begin = numbers.begin(), end = numbers.end();
	while (begin != end) {
		if (num == *begin) {
			return begin;
		}
		++begin;
	}
	return end;
}
*/
//EXERCISE 9.11
//SIX WAYS TO INTIALIZE A VECTOR
/*
vector<int> number;//default initalized, its empty with 0 size
vector<int> number(10); // we define a size, and it is default initalized.
vector<int> numbers(10, 20); //we define a size and their values.
vector<int> numbers{ 25,234,432 };  //we explicity say whats in the vector.
vector<int> numbers(random.begin(), random.end()); // they are pointers and will copy their contents up to the end of .end()
vector<int> numbers = random;// we set it equal to another.
*/
//EXERCISE 9.13
/*
list<int> numbers = {234,324,23,234,23,6,325,23,452,35,23,52,35,23,5};
	vector<double> doubles(numbers.begin(),numbers.end());
	for (auto m : doubles) {
		cout << m << endl;
	}
*/
//EXERCISE 9.18
/*
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main() {
	string line;
	deque<string> data;
	while (getline(cin,line)) {
		data.push_back(line);
	}
	for (string& n : data) {
		cout << n << endl;
	}
	system("pause");
	return 0;
}
*/
//EXERCISE 9.19
//CHANGE DEQUE TO LIST
//EXERCISE 9.20
/*
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main() {
	list<int> numbers;
	deque<int> evens;
	deque<int> odds;
	for (int m = 0; m <= 30; m++) {
		numbers.push_front(m*m);
	}
	for (list<int>::iterator begin = numbers.begin(); begin != numbers.end(); begin++) {
		if (*begin % 2) {
			evens.push_back(*begin);
		}
		else {
			odds.push_back(*begin);
		}
	}
}
*/
//EXERCISE 9.24
/*
vector<int> numbers = { 31,23,1,23,12,4,215,1,24,123,2 };
	if (!numbers.empty()) {
		cout << numbers.at(0) << endl;
		cout << numbers.front() << endl;
		cout << *(numbers.begin()) << endl;
		cout << numbers[0] << endl;
	}*/
//EXERCUSE 9.26
/*#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main() {
	int ia[] = { 4, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> numbers1(begin(ia), end(ia));
	list<int> numbers2 (begin(ia), end(ia));
	vector<int>::iterator it1 = numbers1.begin();
	list<int>::iterator it2 = numbers2.begin();
	while (it1 != numbers1.end()|| it2 != numbers2.end()) {
		if (*it1 % 2 == 0) {
			it1 = numbers1.erase(it1);
			it2++;
		}
		else {
			it1++;
			it2 = numbers2.erase(it2);
		}

	}
	for (const auto &m : numbers2) {
		cout << m << endl;
	}
	system("pause");
	return 0;
}*/
//EXERCISE 9.27
/*
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;

int main() {
	forward_list<int> numbers = { 1,2,51,25,23,4,123,1,23,12,5,363,7,56,45,54,3,234,32,1,23,123,12,321,543,534,5 };
	forward_list<int>::iterator previous = numbers.before_begin();
	forward_list<int>::iterator begin = numbers.begin();
	while (begin != numbers.end()) {
		if (*begin % 2 != 0) {//if odd
			begin = numbers.erase_after(previous);
		}
		else {//if even
			previous = begin++;
		}
	}
	for (auto m : numbers) {
		cout << m << endl;
	}
	system("pause");
	return 0;
}*/
//EXERCISE 9.28
/*
forward_list<string> input(forward_list<string> list, string str1, string str2) {
	forward_list<string>::iterator previous = list.before_begin();
	forward_list<string>::iterator begin = list.begin();
	while (begin != list.end()) {
		if (*begin == str1) {
			begin = list.insert_after(previous, str2);
			return list;
		}
		else {
			previous = begin++;
		}
	}
}*/

//EXERCISE 9.41
/*vector<char> word= { 'h','i',' ','m','e' };
	string m(word.begin(),word.end());
	cout << m << endl;
*/
//EXERCISE 9.43
/*
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;
string replace(string& s, const string& oldVal, const string& newVal) {
	string::iterator begin = s.begin();

	int Num = oldVal.size();
	while (begin != s.end()) {
		if (*begin == oldVal.at(0)) {//if the first character is the one from oldVal, we start to check
			string word;
			int oindex = begin - s.begin();//original index.
			for (int index = begin - s.begin(); index  <= (Num+oindex)-1 && index <= s.size(); index++) {
				word.push_back(s[index]);//we put the opporitie size into the string.
			}
			if (word == oldVal) {//now we check if its the same.
				s.erase(oindex, Num);
				s.insert(oindex, newVal);
			}
			begin++;//we increment the iterator to keep going.
		}

		else {
			begin++;
		}
	}
	return s;
}
int main() {
	string m = "The world is great tho. I know right! its amazing, but even tho its ugly.";
	replace(m, "tho", "though");
	system("pause");
	return 0;
}*/
//EXERCISE 9.44
//IN LINE 209-210 REPLACE WITH
/*
s.replace(oindex,Num,newVal);
*/
//EXERCISE 9.45
/*
string addfix(string& name, string prefix, string suffix) {
	name.insert(0, prefix + " ").append(" " + suffix);
	return name;
}
*/
//EXERCISE 9.46
/*
string addfix(string& name, string prefix, string suffix) {
	name.insert(0, prefix + " ").insert(name.size() + prefix.size()+1, " "+suffix );
	return name;
}
*/
//EXERCISE 9.47
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string random("ab2c3d7R4E6");
	string condition = ("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	string::size_type index = 0;
	while (index != random.size()) {
		index = random.find_first_not_of(condition,index);
		if (index == string::npos) {
			break;
		}
		cout << random.at(index) << endl;
		index++;
	}
	
	system("pause");
	return 0;
}
*/
//EXERCISE 9.49
/*
string lowestA_D(const string &s, const string& d) {
	string condition("tilkhfdqypjg");
	int sum_s = 0, sum_d = 0;
	string::size_type index = 0;
	while (index != s.size()) {
		index = s.find_first_not_of(condition, index);
		sum_s++;
		index++;
	}
	index = 0;
	while (index != d.size()) {
		index = d.find_first_not_of(condition, index);
		sum_d++;
		index++;
	}
	return (sum_s > sum_d) ? s : (sum_s < sum_d) ? d : "Neither";
}*/
//EXERCISE 9.50
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	vector<string> numbers = { "342342235","234234","234","123883","42.2" };
	unsigned sum = 0;
	for (auto m : numbers) {
		sum += stoi(m);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
*/
//EXERCISE 9.51
/*
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Date {
public:
	Date(string d);
	void get() {
		cout << "Year :" << year << " Month : " << month << " Day :" << day << endl;
	}
private:
	unsigned year;
	unsigned month;
	unsigned day;
};

Date::Date(string d) : year(0) {
	const vector<string> large = { "January","Febuary","March" };
	const vector<string> small = { "Jan","Feb","Mar" };
	string condition = "qwertyuiopasdfghjklzxcvbnm";
	if (isdigit(d.at(0))) {// 3/1/5 format.
		year = 2000+ stoi(string(1,d.at(0)));
		month = stoi(string(1,d.at(2)));
		if ( d.substr(4,2).size() > 1 ) {
			day = stoi(d.substr(4, 2));
		}
		else {
			day = stoi(string(1,d.at(4)));
		}
		
	}
	else if (d.find_last_of(condition) <= 2) {//Jan, 5, 2003 format
		auto x = find(small.begin(), small.end(), d.substr(0, 3));
		month = (x - small.begin())+1;

		if (d.substr(5, 2).size() > 1) {
			day = stoi(d.substr(5, 2));
		}
		else {
			day = stoi(d.substr(5, 1));
		}
		year = stoi( d.substr(d.size() - 4, 4) );
	}
	else {// January 5, 2003 format
		int lastIndex = d.find_last_of("qwertyuiopasdfghjklzxcvbnm");
		auto x = find(large.begin(), large.end(), d.substr(0, lastIndex+1));
		month = (x - large.begin());
		
		string condition("1234567890");
		int index = d.find_first_of(condition);
		if (index != d.find_last_of(condition) ) {
			day = stoi(d.substr(index, 2));
		}
		else {
			day = stoi(d.substr(index, 1));
		}
		year = stoi(d.substr(d.size() - 4, d.size()));
	}
};
int main() {
	Date x("January, 5, 2003");
	x.get();
	system("pause");
	return 0;
}
*/
