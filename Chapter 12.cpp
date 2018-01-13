//------------------------------------------------------------------EXERCISE 12.2-12.3
/*
class StrBlob {
public:
	StrBlob() = default;
	StrBlob(std::initializer_list<string> i) {}

	int size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& s) { data->push_back(s); }
	void pop_back();
	void pop_back() const;
	string& front();
	string& back();
	string& front() const;
	string& back() const;
private:
	std::shared_ptr<vector<string>> data;
	void check(const int& i, const string& s) {
		if (i >= data->size())
			throw std::out_of_range(s);
	}
	void check(const int& i, const string& s) const {
		if (i >= data->size())
			throw std::out_of_range(s);
	}
};
string& StrBlob::front() {
	this->check(0, "Front on empty StrBlob");
	return data->front();
}
string & StrBlob::back() {
	this->check(0, "Back on empty StrBlob");
	return data->back();
}
string& StrBlob::front() const{
	this->check(0, "Front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() const {
	this->check(0, "Back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back() {
	this->check(0, "Pop_back on empty StrBlob");
	this->data->pop_back();
}
void StrBlob::pop_back() const {
	this->check(0, "Pop_back on empty const StrBlob");
	this->data->pop_back();
}
*/
//------------------------------------------------------------------EXERCISE 12.6
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <new>
#include <vector>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

vector<int>* dac() {
	vector<int>* pV = new vector<int>;
	return pV;
}

void read(vector<int>* pV) {
	int m(0);
	while (cin >> m) {
		pV->push_back(m);
	}
}

void print(vector<int>* pV) {
	for (vector<int>::const_iterator begin = pV->cbegin(); begin != pV->cend(); begin++) {
		cout << *begin << endl;
	}
}

int main() {
	vector<int>* ptr = dac();
	read(ptr);
	print(ptr);
	delete ptr;
	ptr = nullptr;
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------EXERCISE 12.7
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <new>
#include <memory>
#include <vector>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

std::shared_ptr<vector<int>> dac() {
	vector<int> pV;
	return std::make_shared<vector<int>>(pV);
}

void read(vector<int>& pV) {
	int m(0);
	while (cin >> m) {
		pV.push_back(m);
	}
}

void print(vector<int> pV) {
	for (vector<int>::const_iterator begin = pV.cbegin(); begin != pV.cend(); begin++) {
		cout << *begin << endl;
	}
}

int main() {
	std::shared_ptr<vector<int>> ptr = dac();
	read(*ptr);
	print(*ptr);
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------EXERCISE 12.20
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <new>
#include <fstream>
#include <memory>
#include <vector>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;
//////

//StrBlob//
class StrBlob {
	friend class StrBlobPtr;
public:
	StrBlob() = default;
	StrBlob(std::initializer_list<string> i) {}

	int size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& s) { data->push_back(s); }
	void pop_back();
	void pop_back() const;
	string& front();
	string& back();
	string& front() const;
	string& back() const;
private:
	std::shared_ptr<vector<string>> data;
	void check(const int& i, const string& s) {
		if (i >= data->size())
			throw std::out_of_range(s);
	}
	void check(const int& i, const string& s) const {
		if (i >= data->size())
			throw std::out_of_range(s);
	}
};
string& StrBlob::front() {
	this->check(0, "Front on empty StrBlob");
	return data->front();
}
string & StrBlob::back() {
	this->check(0, "Back on empty StrBlob");
	return data->back();
}
string& StrBlob::front() const {
	this->check(0, "Front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() const {
	this->check(0, "Back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back() {
	this->check(0, "Pop_back on empty StrBlob");
	this->data->pop_back();
}
void StrBlob::pop_back() const {
	this->check(0, "Pop_back on empty const StrBlob");
	this->data->pop_back();
}


class StrBlobPtr {
public:
	StrBlobPtr() = default;
	StrBlobPtr(int i, std::shared_ptr<vector<string>> sptr) : index(i), wkptr(sptr) {};
	StrBlobPtr(int i, StrBlob a) : index(0), wkptr(a.data) {};
	string& deref() const;
	StrBlobPtr& incr();
private:
	std::weak_ptr<vector<string>> wkptr;
	int index;
	std::shared_ptr<vector<string>> check(const int& i, const string message) const;

};
std::shared_ptr<vector<string>> StrBlobPtr::check(const int& i, const string message) const {
	std::shared_ptr<vector<string>> sp = wkptr.lock();
	if (!sp) {
		throw std::runtime_error(message);
	}
	else if (i >= sp->size()) {
		throw std::out_of_range(message);
	}
	return sp;
}
string& StrBlobPtr::deref() const {
	//std::shared_ptr<vector<string>> sp = check("Cannot dereference StrBlobPtr.");
	std::shared_ptr<vector<string>> sp = check(index, "StrBlobPtr is out of range");
	return (*sp)[index];
}

StrBlobPtr& StrBlobPtr::incr() {
	std::shared_ptr<vector<string>> sp = check(index, "StrBlobPtr is out of range");
	index++;
	return *this;
}


//////

int main() {
	StrBlob blob;
	std::ifstream ifs("data.txt");
	while (ifs) {
		string x;
		getline(ifs,x);
		blob.push_back(x);
	}
	
	StrBlobPtr bPtr (0, blob);
	while (true) {
		cout << bPtr.deref() << endl;  
		bPtr.incr();
	}
	system("pause");
	return 0;
}

*/
//------------------------------------------------------------------EXERCISE 12.23
/*
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;


void main() {
	string a = "Hello world!", b = "Whats your name?";
	int m = a.size() + b.size();
	char *c = new char[m];
	a += b;
	for (int n = 0; n <= m -1; n++) {
		*(c +n) = a[n];
	}
	for (int n = 0; n <= m -1; n++) {
		cout << *( c+n) << flush;
	}
	delete[] c;
	system("pause");
}
*/
//------------------------------------------------------------------EXERCISE 12.24
/*
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;


void main() {
	string m;
	vector<string> s;
	int i = 0;
	while (cin >> m) {
		i += m.size();
		s.push_back(m);
	}
	char* arr = new char[i];
	for (int n = 0;;) {
		for (string a : s) {
			for (char c : a) {
				*(arr + n) = c;
				n++;
			}
		}
		break;
	}

	for (int z = 0; z <= i - 1; z++) {
		cout << *(arr + z) << flush;
	}

	system("pause");
}
*/
//------------------------------------------------------------------EXERCISE 12.26
/*
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;


void main() {
	std::allocator<string> allocate;
	const int n = 20;
	auto const aPtr = allocate.allocate(n);
	string s;
	auto sPtr = aPtr;
	while (cin >> s && aPtr != (aPtr+n) ) {
		allocate.construct(sPtr,s);
		sPtr++;
	}
	int z = sPtr - aPtr;
	cout << z << endl;
	while (aPtr != sPtr) {
		sPtr--;
		cout << *(sPtr) << endl;
		allocate.destroy(sPtr);
	}
	allocate.deallocate(aPtr,z);
	
	cout << z << " elements in total were read." << endl;
	system("pause");
}

*/
//------------------------------------------------------------------EXERCISE 12.27
/*
class TextQuery {
public:
	TextQuery(std::ifstream& ifs) { read(ifs); };

private:
	map<string, set<vector<int>>> textMap;
	vector<string> lines;
	void read(std::ifstream& ifs);
	void createMap();
};
void TextQuery::read(std::ifstream& ifs) {
	string line;
	vector<string> m;
	while (getline(ifs, line)) {
		this->lines.push_back(line);
	}
}

void TextQuery::createMap() {
	string word;
	int lineNum = 1;
	for (auto& line : this->lines) {
		std::stringstream sst;
		while (sst >> word) {
			if (this->textMap.find(word) != this->textMap.end()) {//if its in the set already
				auto p = this->textMap.find(word);
			}
			else {//otherwise make a new one.

			}
		}
		lineNum++;
	}
	
}


class QueryResult {
public:
private:
};
*/
//------------------------------------------------------------------EXERCISE 12.30-12.33
//----------------------IN TEXTQUERY.H
/*
#ifndef QUERY
#define QUERY
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <memory>

using std::vector; using std::string; using std::endl; using std::map; using std::set;
class QueryResult;
class TextQuery {
	friend QueryResult;
public:
	TextQuery(std::ifstream& ifs);
	QueryResult query(const string& s);
private:
	map<string, std::shared_ptr<set<int>>> textMap;
	std::shared_ptr<vector<string>> file;
};
TextQuery::TextQuery(std::ifstream& ifs) :file(new vector<string>) {
	string line;
	while (getline(ifs, line)) {
		int number = file->size() ;
		file->push_back(line);
		std::stringstream sst(line);
		string word;
		while (sst >> word) {
			std::shared_ptr<set<int>>& ptr = textMap[word];
			if (!ptr) {
				ptr.reset(new set<int>());
			}
			ptr->insert(number);
		}

	}
}

class QueryResult {
	friend std::ostream& print(std::ostream& os, const QueryResult& qr);
public:
	QueryResult(string s, std::shared_ptr<set<int>> p, std::shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {};
	set<int>::iterator begin() { return lines->begin(); };
	set<int>::iterator end() { return lines->end(); };
	std::shared_ptr<std::vector<string>> get_file() { return file; };
private:
	string sought;
	std::shared_ptr<set<int>> lines;
	std::shared_ptr<std::vector<string>> file;
};

QueryResult TextQuery::query(const string&s) {
	auto itr1 = textMap.find(s);
	static std::shared_ptr<set<int>> noresult(new set<int>());
	if (itr1 != textMap.end()) {
		return QueryResult(s, itr1->second, file);
	}
	else {
		return QueryResult(s, noresult, file);
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " times. " << endl;
	for (auto &m : *(qr.lines)) {
		os << "\t(line " << m + 1 << ") " << *(qr.file->begin() + m) << endl;
	}
	return os;
}

#endif // !QUERY
*/
//-----------------------IN MAIN.CPP
/*
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include "TextQuery.h"
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

void runQueries(std::ifstream &infile)
{
	// infile is an ifstream that is the file we want to query
	TextQuery tq(infile); // store the file and build the query map
						  // iterate with the user: prompt for a word to find and print results
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		// stop if we hit end-of-file on the input or if a 'q' is entered
		if (!(cin >> s) || s == "q") break;
		// run the query and print the results
		print(cout, tq.query(s)) << endl;
	}
}

int main() {
	std::ifstream d("data.txt");
	runQueries(d);
	system("pause");
	return 0;
}

*/
//-------------------------------------------FINAL IMPLENTATION OF STRBLOB.H, IGNORED A FEW EXERCISES INCLUDING STRBLOB AND CONSTSTRBLOB.
/*
#pragma once
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <initializer_list>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector; using std::shared_ptr; using std::weak_ptr;

class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	StrBlob() : strData(new vector<string>) {};
	StrBlob(std::initializer_list<string> b) : strData(new vector<string>(b)) {};
	string popBack();
	void pushBack(const string& t);
	string front();
	string back();
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> strData;
	void check(const int& integer, const string& message);
};

void StrBlob::check(const int& integer, const string& message) {
	if (integer <= 0) {
		std::runtime_error::runtime_error(message);
	}
}

void StrBlob::pushBack(const string& t) {
	this->strData->push_back(t);
}

string StrBlob::popBack() {
	check(this->strData->size(), "popBack member function was called on an empty StrBlob");
	string temp = this->back();
	this->strData->pop_back();
	return temp;
}

string StrBlob::front() {
	check(this->strData->size(), "front member function was called on an empty StrBlob.");
	return this->strData->front();
}

string StrBlob::back() {
	check(this->strData->size(), "back memeber function was called on an empty StrBlob.");
	return this->strData->back();
}


class StrBlobPtr {
public:
	StrBlobPtr(StrBlob& blob) : wkptr(blob.strData),index(0) {};
	StrBlobPtr(StrBlob& blob, const int& m) : wkptr(blob.strData), index(m) {};
	string deref() const;
	StrBlobPtr& incr();
private:
	int index;
	weak_ptr<vector<string>> wkptr;
	shared_ptr<vector<string>> check(const int& integer, const string& message, const string& message2) const;
};
shared_ptr<vector<string>> StrBlobPtr::check(const int& integer,const string& message, const string& message2) const {
	auto check = wkptr.lock();
	if (!check) {
		std::runtime_error::runtime_error(message);
	}
	else if (integer >= check->size()) {
		std::out_of_range::out_of_range(message2);
	}
	else {
		return check;
	}
}

string StrBlobPtr::deref() const {
	auto ptr = check(index,"StrBlobPtr does not point to an object.","Deref member function called on StrBlobPtr that points to an empty StrBlob.");
	return ptr->at(index);
}

StrBlobPtr& StrBlobPtr::incr() {
	index++;
	return *this;
}


//ON STRBLOB

StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, this->strData->size() - 1);
}
*/