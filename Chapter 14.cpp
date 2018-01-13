//EXERCISE 14.6
/*
std::ostream& operator<<(std::ostream& os, const Sales_data& rhs) {
	os << rhs.bookNo << " " << rhs.units_sold << " " << rhs.revenue << std::flush;
	return os;
}
*/
//EXERCISE 14.7
/*
std::ostream& operator<<(std::ostream& os, const String& s) {
	if (s.begin) {
		for (char* iterator = s.begin; s.begin != s.end; iterator++) {
			os << *iterator << std::flush;
		}
	}
	return os;
}
*/
//ALL OF EMPLOYEE CLASS EXERCISES
/*
class Employee {
	friend std::ostream& operator<<(std::ostream& os, const Employee& emp);
	friend std::istream& operator >> (std::istream& is, Employee& emp);
	friend bool operator==(const Employee& rhs, const Employee& lhs);
	friend bool operator<(const Employee& rhs, const Employee& lhs);
	friend bool operator>(const Employee& rhs, const Employee& lhs);
public:
	Employee(unsigned a = 0, string n = "", string o = "", string t = "") :name(n), occupation(o), tele(t), age(a) {};
	Employee(unsigned a, string n, string o) : Employee(a, n, o, " ") {};
	Employee(const Employee& emp) :age(emp.age),name(emp.name),occupation(emp.occupation),tele(emp.tele) {};
	Employee& operator=(Employee);
	explicit operator int() const { return age; };
	explicit operator bool() const { return age && name; };
private:
	unsigned age;
	string name;
	string occupation;
	string tele;
};

Employee& Employee::operator=(Employee emp) {
	using std::swap;
	swap(age, emp.age);
	swap(name, emp.name);
	swap(occupation, emp.occupation);
	swap(tele, emp.tele);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
	os << emp.name << " " << emp.occupation << " " << emp.age << " " <<  emp.tele << std::flush;
	return os;
}


std::istream& operator >> (std::istream& is, Employee& emp) {
	is >> emp.age >> emp.name >> emp.occupation >> emp.tele;
	if (!is) {
		emp = Employee();
	}
	return is;
}

bool operator==(const Employee& rhs, const Employee& lhs) {
	return rhs.age == lhs.age && rhs.name == rhs.name &&
		rhs.occupation == lhs.occupation && rhs.tele == rhs.tele;
}

bool operator!=(const Employee& rhs, const Employee& lhs) {
	return !(rhs == lhs);
}

bool operator<(const Employee& rhs, const Employee& lhs) {
	return rhs.age < lhs.age;
}

bool operator >(const Employee& rhs, const Employee& lhs) {
	return rhs.age > lhs.age;
}
*/
//EXERCISE 14.9
/*
std::istream& operator >> (std::istream& is, Sales_data& rhs) {
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if (!is) {
		rhs = Sales_data();
	}
	else {
		rhs.revenue = rhs.units_sold * price;
	}
	return is;
}
*/
//EXERCISE 14.16
//SEE 'StrBlob.h', 'StrVec.h',  Sales_Data.h
//EXERCISE 14.18
//SEE 'StrBlob.h', 'StrVec.h'
//EXERCISE 14.30
/*
#ifndef CONST STRBLOB
#define CONST STRBLOB

class ConstStrBlobPtr {
	friend class StrBlob;
public:
	ConstStrBlobPtr(const StrBlob& sb) : index(0), wkptr(sb.strData) {};
	const string& operator*() const;
	const string* operator->() const;
	const string& operator[](const int&) const;
private:
	unsigned int index;
	weak_ptr<vector<string>> wkptr;
	shared_ptr<vector<string>> check(const int& integer, const string& message) const;
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(const int& integer, const string& message) const {
	auto check = wkptr.lock();
	if (!check) {
		throw std::runtime_error::runtime_error("StrBlobPtr does not point to a StrBlob");
	}
	else if (integer >= check->size()) {
		throw std::out_of_range::out_of_range(message);
	}
	else if (integer < 0) {
		throw std::out_of_range(message);
	}
	else {
		return check;
	}
}

const string& ConstStrBlobPtr::operator[](const int& n) const {
	check(index, "Subscript operator past off range of ConstStrBlobPtr.");
	return this->wkptr.lock()->operator[](n);
}

const string& ConstStrBlobPtr::operator*() const {
	check(index, "StrBlobPtr dereference past range.");
	return (*this)[index];
}

const string* ConstStrBlobPtr::operator->() const {
	return &this->operator*();
}
/*How this works:
* In the operator*, we get the string that is whole(not the memory) to be returned when we dereference it. 
* In the end we get the string, similar to how a pointer works.
* But in the operator->, we first make the operator* do the checking work. Then with the string we've recieved we direct the string to its mememory
* through the adress of operator, which is then followed through copy initilization to create a pointer.
* Now when we use it ///
*	const StrBlob x({ "Hello","World!" });
*	ConstStrBlobPtr constStr(x);
*	cout << constStr->at(0) << endl;
*The constStr returns a pointer which we just explained why.
** Then we use the built in arrow operator in the standard library defined by string to do the rest of the work of
* allowing various string memeber functions.
*/
#endif // !CONST STRBLOB

//EXERCISE 14.3
/*
class PtrStrBlobPtr {
public:
	PtrStrBlobPtr(StrBlobPtr& sbp) : data(sbp.strData) {};
	vector<string>& operator*() {
		return *data;
	}
	vector<string>* operator->() {
		return &(*data);
	}
private:
	shared_ptr<vector<string>> data;
};
*/
//EXERCISE 14.34
/*
class FucObj {
public:
	FucObj(int& n) : equalizer(n) {};
	const int& operator()(const int& a, const int& b, const int & c) const {
		if (a > equalizer) {
			return a;
		}
		else if (b > equalizer) {
			return b;
		}
		else if (c > equalizer) {
			return c;
		}
		else {
			return equalizer;
		}
	}
private:
	int equalizer;
};
*/
//EXERCISE 14.35
/*
class ReadString {
public:
	ReadString(std::istream& i = std::cin) : is(i) {};
	void operator()(string& s) {
		is >> s;
		if (!is.good()) {
			s = string();
		}
	}
private:
	std::istream& is;
};
*/
//EXERCISE 14.36
/*
class ReadString {
public:
	ReadString(std::istream& i = std::cin) : is(i) {};
	vector<string> operator()(string& s) {
		vector<string> data;
		while (is.good()) {
			is >> s;
			data.push_back(s);
		}
		return data;
	}
private:
	std::istream& is;
};
*/
//EXERCISE 14.37
/*
class Equal {
public:
	bool operator()(const int& a, const int & b) {
		return a > b;
	}
};

int main() {
	Equal myEqual;
	vector<int>ints({ 12,3,45,34,55,6,568,67,9708,234,0,8,7,65,4,3,2,3,1,31,23,2,543,234,456,45,7,65,867,9,879,0,345,546,53,24,1,23,1,23,23,53,57,65,8,680,68456,123,45645,34 });
	std::stable_sort(ints.begin(), ints.end(), myEqual);
	std::for_each(ints.begin(), ints.end(), [](const int& n) {
		cout << n << " " << flush;
	});
	cout << endl;
	system("pause");
	return 0;
}

*/
//EXERCISE 14.38 && 14.39
/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

class Size {
	friend std::ostream& operator<<(std::ostream&,const Size&);
public:
	explicit Size(const string& x) : occurance(0) { size = x.size(); };
	explicit Size(const int& x) : size(x), occurance(0) {}
	bool operator()(const string& x) {
		x.size() <= size ? occurance++ : occurance;
		return x.size() <= size;
	}
private:
	unsigned int size;
	unsigned int occurance;
};

std::ostream& operator<<(std::ostream& os,const Size& a) {
	os << a.occurance << flush;
	return os;
}

int main() {
	std::ifstream ifs ("data.txt");
	string line;
	Size sz(10);
	while (std::getline(ifs, line)) {
		std::stringstream sst(line);
		string word;
		while (sst >> word) {
			sz(word);
		}
	}
	cout << sz << endl;
	system("pause");
	return 0;
}
*/
//EXERCISE 14.40 
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

void elimDups(vector<string>& vec) {
	std::sort(vec.begin(), vec.end());
}

struct SizeSort {
	bool operator()(const string& a, const string& b) {
		return a.size() < b.size();
	}
};

class FindSize {
public:
	FindSize(size_t& a) : sz(a) {};
	bool operator()(const string& a) {
		return a.size() >= sz;
	}
private:
	size_t sz;
};

struct Print {
	void operator()(const string& s) {
		cout << s << " ";
	}
};

void biggies(vector<string> &words,vector<string>::size_type sz) {
	elimDups(words); // put words in alphabetical order and remove
	stable_sort(words.begin(), words.end(), SizeSort());// sort words by size, but maintain alphabetical order for words of the same size
	auto wc = find_if(words.begin(), words.end(), FindSize(sz) ); // get an iterator to the first element whose size() is >= sz
	// compute the number of elements with size >= sz
	auto count = words.end() - wc;
	cout << count << " " << "words" << " of length " << sz << " or longer" << endl;
	// print words of the given size or longer, each one followed by a space
	for_each(wc, words.end(),Print());
	cout << endl;
}

int main() {
	vector<string> myVec= { "Proin", "sed", "diam", "odio.", "Quisque", "gravida", "cursus", "neque.", "Maecenas", "hendrerit", "viverra","lectus", "quis", "venenatis." };
	biggies(myVec, 4);

	system("pause");
	return 0;
}
*/
//EXERCISE 14.42 a)
/*
#include <functional>
int main() {
	int occurances = 0;
	std::greater<int> gtr1024;
	vector<int> ints = { 12,31,23,3,5,34,54,56,65,776,708,89798,78,65,46,3,432,4,23,53,46,56,765,8,65,6,432,45645879,123,12,31,2,321,543,65,45,7645,6,54,645,645,6,45,76,8,768,76,856,65,34,5,324,21,421,3,123,21,312,31231231,23,12,3,12,4343,5,435345,35 };
	for (int& i : ints) {
		if (gtr1024(i,1024)) {
			occurances++;
		}
	}
	cout << occurances << endl;
	system("pause");
	return 0;
}
*/
//EXERCISE 14.42 b)
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

int main() {
	int occurances = 0;
	std::not_equal_to<string> neqtPOOH;
	vector<string> words = {"pooh","pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "pooh", "Hello World","pooh", "pooh", "pooh", "pooh", };
	std::pair<int,vector<string>::iterator> def;
	for (vector<string>::iterator begin = words.begin(); begin != words.end(); begin++) {
		if (neqtPOOH(*begin, "pooh")) {
			def.second = begin;
			def.first = begin - words.begin();
			break;
		}
	}
	cout << "At word " << def.first << ", " << *def.second << " is not equal to pooh." << endl;
	system("pause");
	return 0;
}
*/
//EXERCISE 14.43 c)
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

int main() {
	std::multiplies<int> x;
	auto multyBy2 = std::bind(x, 2, std::placeholders::_1);
	vector<int> ints = { 12,31,23,3,5,34,54,56,65,776,708,89798,78,65,46,3,432,4,23,53,46,56,765,8,65,6,432,45645879,123,12,31,2,321,543,65,45,7645,6,54,645,645,6,45,76,8,768,76,856,65,34,5,324,21,421,3,123,21,312,31231231,23,12,3,12,4343,5,435345,35 };
	
	for (auto begin = ints.begin(); begin != ints.end(); begin++) {
		*begin = multyBy2(*begin);
	}
	std::for_each(ints.begin(), ints.end(), [](const int& a) {
		cout << a << endl;
	});
	system("pause");
	return 0;
}
*/
//EXERCISE 14.44
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

struct Add {
	int operator()(const int& a, const int& b) {
		return a + b;
	}
};

auto minus = [](const int& a, const int& b) { return a - b; };

int mutiply(const int&a, const int &b) {
	return a*b;
}

int divide(const int& a, const int &b) {
	return a / b;
}

int(*dptr)(const int&a , const int& b) = &divide;



int main() {

	std::map<string, std::function<int(int,int)>> calculator;
	calculator.insert({"+",Add()});
	calculator.insert({"-",minus});
	calculator.insert({ "*",mutiply });
	calculator.insert({ "/",dptr });

	system("pause");
	return 0;
}
*/
