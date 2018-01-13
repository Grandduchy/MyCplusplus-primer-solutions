//-------------------------------------------------------------EXERCISE 10.1
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> numbers;
	int number;
	while (cin >> number) {
		numbers.push_back(number);
	}
	int num = count(numbers.begin(), numbers.end(), 5);
	cout << num << endl;
	system("pause");
	return 0;
}*/
//-------------------------------------------------------------EXERCISE 10.2
/*
//CHANGE LINE 10 'vector' TO 'list' AND INCLUDE <list>.
*/
//-------------------------------------------------------------EXERCISE 10.3
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
using namespace std;

int main() {
	vector<int> myints = { 12,31,24,345,53,46,5,64,56,4,587,45,8,55,67,3453,45345 };
	cout << accumulate(myints.cbegin(), myints.cend(), 0) << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.6
/*
vector<int> mynum = { 31,23,1,24,234,423,5,34,6,45,758,56,54,23,3,2,234,1,34,234,5,65,7,6,5,4322,1,234,435 };
fill_n(mynum.begin(), mynum.size(),0);
*/
//-------------------------------------------------------------EXERCISE 10.9
/*
void elimDups(vector<string>& container) {
	vector<string> unique;
	vector<string>::iterator begin = container.begin();
	while (begin != container.end()) {
		if (find(unique.begin(), unique.end(), *begin) == unique.end()) {
			unique.push_back(*begin);
		}
		begin++;
	}
	container = unique;
}
*/
//-------------------------------------------------------------EXERCISE 10.11
//WE USED EXERCISE 10.9 FUNCTION TOO.
/*
bool isShorter(const string& a, const string& b) {
	return a.size() < b.size();
}
stable_sort(sentence.begin(), sentence.end(), isShorter);
*/
//-------------------------------------------------------------EXERCISE 10.12
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Sales_Data.h"
using namespace std;

bool compareIsb(Sales_data s1, Sales_data s2) {
	return s1.isbn() > s2.isbn();
}

int main() {
	vector<Sales_data> data;
	data.emplace_back("hello");
	data.emplace_back("haoskpow");
	data.emplace_back("hello");
	data.emplace_back("asokdoasd");
	data.emplace_back("hello");
	stable_sort(data.begin(), data.end(), compareIsb);
	for (auto& m : data) {
		cout << m.isbn() << endl;
	}
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.13
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool gtr5(const string& a) {
	return a.size() >= 5;
}

int main() {
	vector<string> sentence = { "the","quick","red","fox,","jumps","over","the","slow","red","turtle" };
	vector<string>::iterator second = partition(sentence.begin(), sentence.end(), gtr5);
	for (vector<string>::iterator begin = sentence.begin(); begin != second; begin++) {
		cout << *begin << " ";
	}
	cout << endl;
	while (second != sentence.end()) {
		cout << *second << " ";
		second++;
	}
	cout << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.14
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m = 5, n = 20;
	auto sum = [m, n] {return m + n; };
	cout << sum() << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.15
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m = 5, n = 20;
	auto sum = [m](const int& x) {return m + x; };
	cout << sum(20) << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.16
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void elimDups(vector<string>& container) {
	vector<string> unique;
	vector<string>::iterator begin = container.begin();
	while (begin != container.end()) {
		if (find(unique.begin(), unique.end(), *begin) == unique.end()) {
			unique.push_back(*begin);
		}
		begin++;
	}
	container = unique;
}

bool sort1(const string& s1, const string& s2) {
	return s1 < s2;
}

void biggies(vector<string>& s, vector<string>::size_type n ) {
	elimDups(s);
	auto sort = [](const string& s1, const string& s2) -> bool {return s1.size() < s2.size(); };
	stable_sort(s.begin(), s.end(), sort);
	auto gtr = [n](const string& s1) { return n < s1.size();  };
	vector<string>::iterator begin = find_if(s.begin(), s.end(), gtr);
	while (begin != s.end()) {
		cout << *begin << endl;
		begin++;
	}
}

int main() {
	vector<string> sentence = { "the","quick","red","fox,","jumps","over","the","slow","red","turtle" };
	biggies(sentence, 4);
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.17
/*
auto compareIsb = [](Sales_data s1, Sales_data s2) {return s1.isbn() > s2.isbn();} 
*/
//-------------------------------------------------------------EXERCISE 10.18
/*
void biggies(vector<string>& s, vector<string>::size_type n ) {
	elimDups(s);
	auto sort = [](const string& s1, const string& s2) -> bool {return s1.size() < s2.size(); };
	stable_sort(s.begin(), s.end(), sort);
	auto gtr = [n](const string& s1) { return n < s1.size();  };
	vector<string>::iterator begin = partition(s.begin(), s.end(), gtr);
	vector<string>::iterator sBegin = s.begin();
	while (sBegin != begin) {
		cout << *sBegin << endl;
		sBegin++;
	}
}
*/
//-------------------------------------------------------------EXERCISE 10.19
//SAME FUNCTION AS ABOCE, BUT LINE 212 REPLACE WITH
/*
vector<string>::iterator begin = stable_partition(s.begin(), s.end(), gtr);
*/
//-------------------------------------------------------------EXERCISE 10.20
/*
void biggies(vector<string>& s, vector<string>::size_type n ) {
	elimDups(s);
	auto sort = [](const string& s1, const string& s2) -> bool {return s1.size() < s2.size(); };
	stable_sort(s.begin(), s.end(), sort);
	auto gtr = [n](const string& s1) { return n < s1.size();  };
	int sum = count_if(s.begin(), s.end(),
		[n](string m) -> bool {return n < m.size(); });
	cout << sum << endl;
}
*/
//-------------------------------------------------------------EXERCISE 10.21
/*
int m = 20;
	while (m != 0) {
		if ( ([m]{return m > 0; })() ) {
			m--;
		}
		else {
			break;
		}
	}
*/
//-------------------------------------------------------------EXERCISE 10.22
/*
bool sort(const string& s1, const string &s2) {
	return s1.size() < s2.size();
}

bool gtr(const string& m, int n) {
	return n < m.size();
}

void biggies(vector<string>& s, vector<string>::size_type n ) {
	elimDups(s);
	stable_sort(s.begin(), s.end(), sort);
	auto gtrX = bind(gtr, placeholders::_1, n);
	int sum = count_if(s.begin(), s.end(), gtrX);
	cout << sum << endl;
}
*/
//-------------------------------------------------------------EXERCISE 10.24
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool check_size(const string &s1, const int& n) {
	return s1.size() > n;
}

vector<string>::const_iterator gtrLen(const vector<string>& s, int m) {
	auto gtr = bind(check_size, placeholders::_1, m);
	return find_if(s.begin(), s.end(), gtr);
}

int main() {
	vector<string> sentence = { "the","quick","red","fox,","jumps","over","the","slow","red","turtle" };
	auto m = gtrLen(sentence, 4);
	while (m != sentence.end()) {
		cout << *m << " ";
		m++;
	}
	cout << endl;
	system("pause");
	return 0;
}
*/

//-------------------------------------------------------------EXERCISE 10.25
/*
bool check_size(const string &s1, const int& n) {
	return s1.size() < n;
}

void biggies(vector<string>& s, vector<string>::size_type n) {
	elimDups(s);
	auto sort = [](const string& s1, const string& s2) -> bool {return s1.size() < s2.size(); };
	stable_sort(s.begin(), s.end(), sort);

	auto gtr = bind(check_size, placeholders::_1, n);
	vector<string>::iterator begin = partition(s.begin(), s.end(), gtr);
	vector<string>::iterator sBegin = s.begin();
	while (sBegin != begin) {
		cout << *sBegin << endl;
		sBegin++;
	}
}
*/
//-------------------------------------------------------------EXERCISE 10.27
/*
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;
int main() {
	vector<string> sentence = { "the","quick","red","fox,","jumps","over","the","slow","red","turtle" };
	list<string> unique_sentence;
	stable_sort(sentence.begin(), sentence.end());
	unique_copy(sentence.begin(), sentence.end(), inserter(unique_sentence, unique_sentence.begin()));
	for_each(unique_sentence.begin(), unique_sentence.end(), [](const string& s) {cout << s << endl; });
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.28
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <list>
using namespace std;
int main() {
	list<int> main = { 0,1,2,3,4,5,6,7,8,9 }, front, back, inst;
	copy(main.begin(), main.end(), front_inserter(front));
	copy(main.begin(), main.end(), back_inserter(back));
	copy(main.begin(), main.end(), inserter(inst, inst.begin()));
	cout << "Front inserter :" << endl;
	for_each(front.begin(), front.end(), [](const int& i) {cout << i <<" "<< flush; });
	cout << "Back inserter :" << endl;
	for_each(back.begin(), back.end(), [](const int& i) {cout << i << " "<< flush; });
	cout << "Inster inserter : " << endl;
	for_each(inst.begin(), inst.end(), [](const int& i) {cout << i << " " << flush; });
	cout << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.29
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <list>
using namespace std;
int main() {
	
	vector<string> words;
	fstream a("data.txt");
	ostream_iterator<string> os(cout, " ");
	istream_iterator<string> file(a), eod;
	while (file != eod) {
		words.push_back(*file++);
	}
	copy(words.begin(), words.end(), os);
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.30
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <list>
using namespace std;
int main() {
	vector<int> numbers;
	istream_iterator<int> is(cin), eod;
	ostream_iterator<int> os(cout, " ");
	while (is != eod) {
		numbers.push_back(*is++);
	}
	sort(numbers.begin(), numbers.end(), [](const int&n1, const int &n2) {return n1 < n2; });
	copy(numbers.begin(), numbers.end(), os);
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.31
//SAME AS ABOVE BUT
/*
unique_copy(numbers.begin(), numbers.end(), os);
*/
//-------------------------------------------------------------EXERCISE 10.33
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
using std::vector;using std::string;
int main() {
	std::ifstream input("data.txt");
	std::ofstream outputEvens("Evens.txt");
	std::ofstream outputOdds("Odds.txt");
	std::ostream_iterator<int> Evens(outputEvens, "\n");
	std::ostream_iterator<int> Odds(outputOdds, "\n");
	std::istream_iterator<int> Input(input), eod;
	while (Input != eod) {
		if (*Input % 2 == 0) {
			Evens = *Input;
		}
		else {
			Odds = *Input;
		}
		Input++;
	}
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.34
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	vector<int> m = { 12,31,2,12,23,235,345,345 };
	vector<int>::const_reverse_iterator x = m.crbegin();
	while (x != m.crend()) {
		cout << *x << "\n";
		x++;
	}
	cout << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.35
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl;
int main() {
	vector<int> m = { 12,31,2,12,23,235,345,345 };
	vector<int>::const_iterator x = m.cend() -1;
	while (x != m.begin()) {
		cout << *x << "\n";
		x--;
	}
	cout << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.36
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::list;
int main() {
	list<int> x= { 124,23,0,325,34,534,6,98,990,345,0,345,3453123,0,123,123 };
	auto m = std::find(x.crbegin(), x.crend(), 0);
	cout << *m << endl;
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.37
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::list;
int main() {
	std::ostream_iterator<int> m(cout, " ");
	vector<int> z = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> x(z.rbegin()+3,z.rend() -3);
	std::copy(x.begin(), x.end(), m);
	system("pause");
	return 0;
}
*/
//-------------------------------------------------------------EXERCISE 10.42
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::list;
int main() {
	std::ostream_iterator<int>x(cout, " ");
	list<int> numbers = { 12,43,24,645,1231,78,5,76,54,3212,4,3,43,76,788,80,9,876,543,32,21,23,49868,765,432,3,4,5879,8,765,645,34,23,42,465,43,6365,457,458756,87,56,876,8,456,35,2,4,2143,123,1,32123,1,32,2,22,2,2,2,22,2,1,42,46,45,7,658,576,6,435,23,4,1234,2,34,23,4,22,2,2, };
	numbers.sort();
	numbers.unique();
	std::copy(numbers.begin(), numbers.end(), x);
	system("pause");
	return 0;
}
*/