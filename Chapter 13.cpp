//------------------------------------------------------------------------------------EXERCISE 13.5
/*
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
	HasPtr(const HasPtr& temp) : ps(temp.ps), i(temp.i) {};
private:
	std::string *ps;
	int i;
};
HasPtr(const HasPtr& temp) : ps(temp.ps), i(temp.i) {};
//COPY OPERATOR
//USED WITH 
*  HasPtr m(x);
*/
//------------------------------------------------------------------------------------EXERCISE 13.8 
/*
HasPtr& operator=(const HasPtr& temp) { this->ps = temp.ps; this->i = temp.i; return *this; }
//COPY ASSIGNMENT OPERATOR
//USED WITH
HasPtr m();
HasPtr x;
*  x = m;
*/
//------------------------------------------------------------------------------------EXERCISE 13.11
//~HasPtr() {};
//------------------------------------------------------------------------------------EXERCISE -- HOW THESE OPERATORS WORK 
/*
struct numbered {
	numbered() : mysn("D") {}
	numbered(numbered& temp) { temp.mysn = "CA"; this->mysn = "CB"; }//functions use copy constructors for their objects if they are not references, if they are they use the object directly.
	numbered operator=(numbered& temp) { this->mysn = "BA"; temp.mysn = "BB"; cout << "CALLED" << endl; return *this; }//numbered is not a reference so it creates a new one via the a(b) copy constructor
	string mysn;
};

void f(const numbered& s) { cout << s.mysn << endl; }

int main() {
	numbered a, b = a, c = b;
	numbered d;
	d = a;
	cout << d.mysn << endl;
	cout << a.mysn << endl;
	//f(a); f(b); f(c);
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.18
/*
class Employee {
public:
	Employee() { unq++; };
	Employee(const string& s) : name(s) { unq++; };
	Employee operator=(const Employee& e) { name = e.name; unq++; };
	Employee(const Employee& e) { name = e.name; unq++; };
	int getNum() { return unq; };
private:
	static int unq;
	string name;
};
int Employee::unq = 0;
*/
//------------------------------------------------------------------------------------EXERCISE 13.22
/*
HasPtr& operator=(const HasPtr& temp) { this->i = temp.i; this->ps = new string(*(temp.ps)); return *this; };
HasPtr(const HasPtr& temp) :i(temp.i) { ps = new string(*(temp.ps)); };
~HasPtr() {delete ps;}
*/
//---------------------------------------------------------------------JUST TO KEEP INCASE
/*
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
	HasPtr(const HasPtr& temp) : ps(temp.ps), i(temp.i) {};
	HasPtr& operator=(const HasPtr& temp) { this->ps = temp.ps; this->i = temp.i; return *this; };
	~HasPtr() {};
private:
	std::string *ps;
	int i;
};

struct myClass {
	myClass() { std::cout << "myClass()" << std::endl; };
	myClass(const myClass&) { std::cout << "myClass(const myClass&)" << std::endl; };
	myClass operator=(const myClass& temp) { cout << "myClass(operator=)" << endl; return *this; };
	~myClass() { cout << "~myClass" << endl; };
	int m = 5;
};
*/
//------------------------------------------------------------------------------------EXERCISE 13.26
//SEE CHAPTER 12 FOR FULL STRBLOB.
/*
class StrBlob {
	friend class StrBlobPtr;
public:
	StrBlob() : strData(new vector<string>) {};
	StrBlob(std::initializer_list<string> b) : strData(new vector<string>(b)) {};
	StrBlob operator=(const StrBlob& temp) {
		this->strData = std::make_shared<vector<string>>(new vector<string>(*(temp.strData)));
	};
	StrBlob(const StrBlob& temp) {
		vector<string> x =*(temp.strData);
		this->strData = std::make_shared<vector<string>>(x);
	}
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
*/
//------------------------------------------------------------------------------------EXERCISE 13.27
/*
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new int(1))  {};
	HasPtr(const HasPtr& temp);
	HasPtr operator=(const HasPtr& temp);
	~HasPtr();
private:
	std::string *ps;
	int i;
	int* use;
};
HasPtr::HasPtr(const HasPtr& temp) : i(temp.i), use(temp.use), ps(temp.ps) {(*use)++; };

HasPtr HasPtr::operator=(const HasPtr& temp) {
	(*use)--;
	if (*use <= 0) {
		delete ps;
		delete use;
	}
	(*temp.use)++;
	use = temp.use;
	i = temp.i;
	ps = temp.ps;
}

HasPtr::~HasPtr() {
	--(*use);
	if (*use >= 0) {
		delete ps;
		delete use;
	}
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.28
/*
class TreeNode {
public:
	TreeNode() : value(""), count(0) { left = new TreeNode(); right = new TreeNode(); }
	TreeNode(const TreeNode& temp) :value(temp.value), count(temp.count) {
		left = temp.left;
		right = temp.right;
	}
	TreeNode operator= (const TreeNode& temp) {
		value = temp.value;
		count = temp.count;
		TreeNode* Templeft = temp.left;//we do this incase temp is equal to the left operand.
		TreeNode* Tempright = temp.right;
		delete left;
		delete right;
		left = Templeft;
		right = Tempright;
		return *this;
	}
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree() { root = new TreeNode(); };
	BinStrTree(const BinStrTree& temp) : root(temp.root) {};
	BinStrTree operator=(const BinStrTree& temp) {
		TreeNode* tempRoot = temp.root;
		delete root;
		root = tempRoot;
		return *this;
	}
private:
	TreeNode *root;
};
*/
//------------------------------------------------------------------------------------EXERCISE 13.30-13.31
//LAST IMPLENTATION(TO THIS CHAPTER) OF HASPTR
/*
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include <algorithm>
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector; 

class HasPtr {
	friend void swap(HasPtr& left, HasPtr& right);
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new int(1))  {};
	HasPtr(const HasPtr& temp);
	HasPtr& operator=(const HasPtr& temp);
	bool operator<(const HasPtr& temp) const;
	~HasPtr();

	string& getString() const {
		return *ps;
	}
private:
	std::string *ps;
	int i;
	int* use;
};
HasPtr::HasPtr(const HasPtr& temp) : i(temp.i), use(temp.use), ps(temp.ps) {(*use)++; };

HasPtr& HasPtr::operator=(const HasPtr& temp) {
	auto* tempLeftPs = temp.ps;
	int tempI = temp.i;
	auto* tempLeftUse = temp.use;
	(*use)--;
	if (*use <= 0) {
		delete ps;
		delete use;
	}
	(*temp.use)++;
	use = tempLeftUse;
	i = tempI;
	ps = tempLeftPs;
	return *this;
}

bool HasPtr::operator<(const HasPtr& temp) const{
	return ((this->ps->size()) < (temp.ps->size()) ? true : false);
}

HasPtr::~HasPtr() {
	--(*use);
	if (*use <= 0) {
		delete ps;
		delete use;
	}
}

void swap(HasPtr& left, HasPtr& right) {
	std::swap(left.i, right.i);
	std::swap(left.ps, right.ps);
	std::swap(left.use, right.use);
}

int main() {
	//------------------------------------------------------------------------------------EXERCISE 13.30
	//HasPtr HW("Hello World");
	//HasPtr ME("xrdftchu");
	//swap(HW, ME);
	//cout << "Hello World :" << HW.getString() << "\nrandom:" << ME.getString() << endl;

	//------------------------------------------------------------------------------------EXERCISE 13.31
	vector<HasPtr> myHas({ HasPtr("Hello"),HasPtr("World"),HasPtr("unduefineeeed"),HasPtr("joke"),HasPtr("me") });
	vector<HasPtr>::iterator begin = myHas.begin();
	vector<HasPtr>::iterator end = myHas.end();
	std::stable_sort(begin, end, [](const HasPtr& a, const HasPtr& b) { return a < b; });
	vector<HasPtr>::iterator begin1 = myHas.begin();
	vector<HasPtr>::iterator end1 = myHas.end();
	std::for_each(begin1, end1, [](const HasPtr temp) {cout << temp.getString() << endl; });
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.34 && 13.36 && 13.37
/*
#pragma once
#ifndef EMAIL
#define EMAIL
#include <iostream>
#include <vector>
#include <string>
#include <set>
using std::vector; using std::endl; using std::set; using std::string;

class Folder;

class Message {
	friend class Folder;
public:
	explicit Message(const string& s = "") : contents(s) {};
	Message(const Message& m);
	Message& operator=(const Message& m);
	~Message();
	/////
	void swap(Message& lhs, Message& rhs);
	std::ostream& printFolders(std::ostream& os);
	void save(Folder& fr);
	void remove(Folder& fr);
private:
	string contents;
	set<Folder*> folders;
	void addToFolders(const Message &m);
	void removeFromFolders();
};

class Folder {
	friend class Message;
public:
	Folder() = default;
	Folder(const string& a) : ID(a) {};
	~Folder();
	void addMsg(Message* ptr);
	void remMsg(Message* ptr);
	std::ostream& printMessages(std::ostream& os);
private:
	string ID;
	set<Message*> messages;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////



std::ostream& Folder::printMessages(std::ostream& os) {
	for (Message* m : messages) {
		os << m->contents << " ";
	}
	return os;
}

Folder::~Folder() {
	for (Message* mesg : messages) {
		delete mesg;
	}
}

void Folder::addMsg(Message* ptr) {
	ptr->save(*this);

}

void Folder::remMsg(Message* ptr) {
	decltype(messages.end()) findMSG = messages.end();
	for (auto begin = messages.begin(); begin != messages.end(); begin++) {
		if ((**begin).contents == ptr->contents) {
			findMSG = begin;
		}
	}
	if (findMSG != messages.end()) {
		messages.erase(findMSG);
		ptr->folders.erase(this);
	}
	else {
		throw std::runtime_error::runtime_error("There is no message to erase with contents of" + ptr->contents);
	}
}

////////////////***********MESSAGE



std::ostream& Message::printFolders(std::ostream& os) {
	for (Folder* folder : folders) {
		os << folder->ID << " ";
	}
	return os;
}

void Message::save(Folder & fr) {
	this->folders.insert(&fr);
	fr.messages.insert(this);
}

void Message::remove(Folder & fr) {
	auto iter = this->folders.find(&fr);
	if (iter != this->folders.end()) {
		folders.erase(iter);
		fr.remMsg(this);
	}
	else {
		throw std::runtime_error::runtime_error("There isn't a folder that contains" + this->contents);
	}
}

void Message::addToFolders(const Message& m) {//we want this to have all the messages m has.
	for (Folder* folder : m.folders) {
		folder->addMsg(this);
	}
}

void Message::removeFromFolders() {//remove the folders this message appears in.
	for (Folder* folder : this->folders) {
		folder->remMsg(this);
	}
}
Message::Message(const Message& m) : contents(m.contents) {
	addToFolders(m);
}
Message::~Message() {
	removeFromFolders();
}
Message& Message::operator=(const Message& m) {
	auto tempF = m.folders;
	auto tempC = m.contents;
	removeFromFolders();
	folders = tempF;
	contents = tempC;
	return *this;
}

void Message::swap(Message& lhs, Message& rhs) {
	std::swap(lhs.contents, rhs.contents);
	std::swap(rhs.folders, lhs.folders);
}

#endif // !EMAIL
///////////////////////////////IN MAIN.CPP
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include "email.h"

using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector; 

void main() {
	Folder myfolder("myfolder"), nextfolder("nextfolder"), afterfolder("afterfolder");
	Message a("Hello world!");
	myfolder.addMsg(&a);
	nextfolder.addMsg(&a);
	afterfolder.addMsg(&a);
	Message b;
	b = a;
	a.printFolders(cout);
	myfolder.printMessages(cout);
	//system("pause");
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.39
/*
#pragma once
#include <string>
#include <utility>
#include <memory>
#include <new>
#include <initializer_list>
using std::string; using std::pair;
class StrVec {
public:
	StrVec() : // the allocator member is default initialized
		elements(nullptr), first_free(nullptr), cap(nullptr) {
	}
	StrVec(std::initializer_list<string>&);
	StrVec(const StrVec&); // copy constructor
	StrVec &operator=(const StrVec&); // copy assignment
	~StrVec(); // destructor
	void push_back(const std::string&); // copy the element
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	int memLeft() const { return cap - first_free; } // out vector.capacity
	void reserve(const int&);
	void resize(const int&);
	void resize(const int&, const string&);
private:
	std::allocator<std::string> alloc; // allocates the elements
									   // used by the functions that add elements to the StrVec
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	// utilities used by the copy constructor, assignment operator, and destructor
	std::pair<std::string*, std::string*> alloc_n_copy // will allocate spance and copy a given range of elements.
	(const std::string*, const std::string*);
	void free(); // destroy the elements and free the space
	void reallocate(); // get more space and copy the existing
		std::string *elements; // pointer to the first element in the array
	std::string *first_free; // pointer to the first free element in the array
	std::string *cap; // pointer to one past the end of the array
	string* StrVec::resizeNDeallocate(const int& size);
};

void StrVec::free() {
	if (elements) {
		while (elements != first_free) {
			alloc.destroy(--first_free);
		}
	}
	alloc.deallocate(elements, cap - elements);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* lhs, const std::string* rhs) {
	auto range = rhs - lhs;
	string* allocB = alloc.allocate(range);
	string* allocE = std::uninitialized_copy(elements, first_free, allocB);
	return{allocB,allocE};
}

void StrVec::reallocate() {
	auto range = (cap - elements) *2;
	string* allocB = alloc.allocate(range); 
	string* allocE = std::uninitialized_copy(elements, first_free, allocB);
	auto allocC = allocB + range;
	free();
	elements = allocB;
	first_free = allocE;
	cap = allocC;
}

StrVec::StrVec(const StrVec& temp) {
	auto pairs = alloc_n_copy(temp.begin(), temp.end());
	elements = pairs.first;
	first_free = pairs.second = cap;
}

StrVec::~StrVec() {
	free();
}

StrVec& StrVec::operator=(const StrVec& temp) {
	auto pairs = alloc_n_copy(temp.begin(), temp.end());
	free();
	elements = pairs.first;
	first_free = pairs.second = cap;
	return *this;
}

StrVec::StrVec(std::initializer_list<string>& temp) {
	auto range = temp.end() - temp.begin();
	string* allocBegin = alloc.allocate(range);
	string* allocEnd = std::uninitialized_copy(temp.begin(), temp.end(), allocBegin);
	elements = allocBegin;
	first_free = allocEnd;
	cap = allocBegin + range;
}

void StrVec::push_back(const string& temp) {
	chk_n_alloc();
	alloc.construct(first_free, temp);
	first_free++;
}

void StrVec::reserve(const int& size) {
	cap += size;
}

string* StrVec::resizeNDeallocate(const int& size) {
	if (size) {
		if (size > capacity()) {//check if we add elements
			alloc.allocate(size,cap);
			return cap + size;
		}
		else {//else we destroy elements and deallocate the memory.
			string* tempCap = elements + size;
			int deallocate = 0;
			while (cap != tempCap) {
				deallocate++;
				alloc.destroy(cap--);
			}
			alloc.deallocate(cap, deallocate);
			return cap;
		}
	}
	
}

void StrVec::resize(const int& size) {
	cap = resizeNDeallocate(size);
}

void StrVec::resize(const int& size, const string& temp) {
	string* tempCap = resizeNDeallocate(size);
	if (cap != tempCap) {
		while (tempCap != cap) {
			alloc.construct(cap++, temp);
		}
		cap = tempCap;
	}
	
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.43
/*
void StrVec::free() {
	std::for_each(elements, first_free, [this](const string& temp) {
		alloc.destroy(&temp);
	});
	alloc.deallocate(elements, cap - elements);
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.44
/*
#ifndef STRING
#define STRING

class String {
public:
	String() : begin(nullptr), end(nullptr) {};
	String(char*,int);
	~String();
	std::ostream& print(std::ostream&);
private:
	std::allocator<char> alloc;
	char* begin;
	char* end;
};

String::String(char* character,int size) {
	begin = alloc.allocate(size);
	end = begin + size;//off the end iterator.
	int iter = 0;
	for (char* fill = begin; fill != end; fill++) {
		*fill = *(character + iter++);
	}
}

std::ostream& String::print(std::ostream& os) {
	if (begin) {
		char* tempBegin = begin;
		while (tempBegin != end) {
			os << *tempBegin << std::flush;
			tempBegin++;
		}
	}
	return os;
}

String::~String() {
	if (begin) {
		for (char* tempBegin = begin; tempBegin != end; begin++) {
			alloc.destroy(tempBegin);
		}
		alloc.deallocate(begin, end-begin);
	}
	
}

#endif // !STRING
*/
//------------------------------------------------------------------------------------EXERCISE 13.48
/*
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include "StrVec.h"
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

int main() {
	vector<String> VEC{ {"Hello World",12}, {"The time is neigh",18} };
	String x("ASDLASD", 8);
	String y("I'm the end.", 13);
	VEC.push_back(x);
	VEC.push_back(y);
	cout << String::copy << endl;
	system("pause");
	return 0;
}
*/
//-----------------------------A LITTLE PRATICE WITH MOVE ASSIGNEMNT AND MOVE CONTRUCTORS
/*
class String {
public:
	String(const string& a = "", const int& b = 0) : contents(new string(a)),size(new int(b)) {};
	String(String&&); //move constructor.
	String& operator=(String&&); //move assignment operator
	~String() { free(); }
	String(String&) = delete;
	String& operator=(String&) = delete;
	void print() {
		cout << "Contents: " << *contents << " Size of contents: " << *size << endl;
	}
private:
	string* contents;
	int* size;
	void free();
};

String::String( String&& s) {
	contents = s.contents;
	size = s.size;
	s.contents = nullptr; s.size = nullptr;
}

String& String::operator=(String&& s) {
	if (this != &s) {
		free();
		contents = s.contents;
		size = s.size;
		s.contents = nullptr; s.size = nullptr;
	}
	return *this;
}

void String::free() {
	delete contents;
	delete size;
}

int main() {
	String b;
	String a("Hello World!", 12);
	b = std::move(a);
	b.print();
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.49
//--------------------------------------STRING CLASS, IN 'StrVec.h'.
/*
#ifndef STRING
#define STRING

class String {
public:
	String() : begin(nullptr), end(nullptr) {};
	String(char*,int);
	String(const String&) ;
	String& operator=(const String&);
	String(String&& s) : alloc(s.alloc), begin(s.begin), end(s.end) { s.begin = s.end = nullptr; s.alloc = std::allocator<char>(); };
	String& operator=(String&&);
	~String();
	std::ostream& print(std::ostream&) const;
	static int copy;
private:
	std::allocator<char> alloc;
	char* begin;
	char* end;
};
int String::copy = 0;

String& String::operator=(String&& s) {
	if (this != &s) {
		for (char* iter = begin; iter != end; iter++) {//first destroy all elements in original.
			alloc.destroy(iter);
		}
		alloc.deallocate(begin, end-begin);//then deallocate them.
		begin = s.begin; //then we steal from s to our original.
		end = s.end;
		alloc = s.alloc;
		s.begin = s.end =nullptr;//make s not equal to our original so when destructor is called it won't destroy ours.
		s.alloc = std::allocator<char>();
	}
	return *this;
}

String::String(char* character,int size) {
	begin = alloc.allocate(size);
	end = begin + size;//off the end iterator.
	int iter = 0;
	for (char* fill = begin; fill != end; fill++) {
		*fill = *(character + iter++);
	}
}

inline String::String(const String & temp) {
	begin = alloc.allocate(temp.end - temp.begin);
	end = std::uninitialized_copy(temp.begin, temp.end, begin);
	copy++;
}

inline String & String::operator=(const String & temp) {
	char* orgiBegin = begin;
	char* orgiEnd = end;
	begin = alloc.allocate(temp.end - temp.begin);
	end = std::uninitialized_copy(temp.begin, temp.end, begin);
	for (char* oriTemp = orgiBegin; oriTemp != orgiEnd; oriTemp++) {
		alloc.destroy(oriTemp);
	}
	alloc.deallocate(orgiBegin, orgiEnd - orgiBegin);
	copy++;
	return *this;
}

std::ostream& String::print(std::ostream& os) const {
	if (begin) {
		char* tempBegin = begin;
		while (tempBegin != end) {
			os << *tempBegin << std::flush;
			tempBegin++;
		}
	}
	return os;
}

String::~String() {
	if (begin) {
		for (char* tempBegin = begin; tempBegin != end; tempBegin++) {
			alloc.destroy(tempBegin);
		}
		alloc.deallocate(begin, end-begin);
	}
	
}


#endif // !STRING

*/
//------------------------------------------------IN MAIN.CPP
/*
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include "StrVec.h"
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

int main() {
	char x[] = "Hello world";
	String myString(x, 12);
	//String newString(std::move(myString));
	String newString;
	newString = std::move(myString);
	newString.print(cout) << endl;
	system("pause");
	return 0;
}
*/
//-----------------------------------------------------MESSAGE CLASS
/*
#pragma once
#ifndef EMAIL
#define EMAIL
#include <iostream>
#include <vector>
#include <string>
#include <set>
using std::vector; using std::endl; using std::set; using std::string;

class Folder;

class Message {
	friend class Folder;
public:
	explicit Message(const string& s = "") : contents(s) {};
	Message(const Message& m);
	Message& operator=(const Message& m);
	Message(Message&&);
	Message& operator=(Message&&);
	~Message();
	/////
	void swap(Message& lhs, Message& rhs);
	std::ostream& printFolders(std::ostream& os);
	void save(Folder& fr);
	void remove(Folder& fr);
private:
	string contents;
	set<Folder*> folders;
	void moveFolder(Message*);
	void addToFolders(const Message &m);
	void removeFromFolders();
};

class Folder {
	friend class Message;
public:
	Folder() = default;
	Folder(const string& a) : ID(a) {};
	~Folder();
	void addMsg(Message* ptr);
	void remMsg(Message* ptr);
	std::ostream& printMessages(std::ostream& os);
private:
	string ID;
	set<Message*> messages;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//move assignemnt and move constructors for message.
void Message::moveFolder(Message* m) {
	for (Folder* fold : m->folders) {
		fold->remMsg(m);
		fold->addMsg(this);
	}
	m->folders.clear();
}

Message::Message(Message&& m) : contents(m.contents) {
	moveFolder(&m);
	m.contents = "";
}

Message& Message::operator=(Message&& m) {
	if (this != &m) {
		moveFolder(&m);
		contents = m.contents;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& Folder::printMessages(std::ostream& os) {
	for (Message* m : messages) {
		os << m->contents << " ";
	}
	return os;
}

Folder::~Folder() {
	for (Message* mesg : messages) {
		delete mesg;
	}
}

void Folder::addMsg(Message* ptr) {
	ptr->save(*this);

}

void Folder::remMsg(Message* ptr) {
	decltype(messages.end()) findMSG = messages.end();
	for (auto begin = messages.begin(); begin != messages.end(); begin++) {
		if ((**begin).contents == ptr->contents) {
			findMSG = begin;
		}
	}
	if (findMSG != messages.end()) {
		messages.erase(findMSG);
		ptr->folders.erase(this);
	}
	else {
		throw std::runtime_error::runtime_error("There is no message to erase with contents of" + ptr->contents);
	}
}

//MESSAGESSSSS



std::ostream& Message::printFolders(std::ostream& os) {
	for (Folder* folder : folders) {
		os << folder->ID << " ";
	}
	return os;
}

void Message::save(Folder & fr) {
	this->folders.insert(&fr);
	fr.messages.insert(this);
}

void Message::remove(Folder & fr) {
	auto iter = this->folders.find(&fr);
	if (iter != this->folders.end()) {
		folders.erase(iter);
		fr.remMsg(this);
	}
	else {
		throw std::runtime_error::runtime_error("There isn't a folder that contains" + this->contents);
	}
}

void Message::addToFolders(const Message& m) {//we want this to have all the messages m has.
	for (Folder* folder : m.folders) {
		folder->addMsg(this);
	}
}

void Message::removeFromFolders() {//remove the folders this message appears in.
	if (!(this->folders.empty())) {
		for (Folder* folder : this->folders) {
			folder->remMsg(this);
		}
	}
	
}
Message::Message(const Message& m) : contents(m.contents) {
	addToFolders(m);
}
Message::~Message() {
	removeFromFolders();
}
Message& Message::operator=(const Message& m) {
	auto tempF = m.folders;
	auto tempC = m.contents;
	removeFromFolders();
	folders = tempF;
	contents = tempC;
	return *this;
}

void Message::swap(Message& lhs, Message& rhs) {
	std::swap(lhs.contents, rhs.contents);
	std::swap(rhs.folders, lhs.folders);
}

#endif // !EMAIL
*/
//----------------------------------------------------STRVEC
/*
#pragma once
#ifndef STRVEC
#define STRVEC

#include <string>
#include <utility>
#include <memory>
#include <new>
#include <initializer_list>
#include <algorithm>
#include <functional>
using std::string; using std::pair;
class StrVec {
public:
	StrVec() : // the allocator member is default initialized
		elements(nullptr), first_free(nullptr), cap(nullptr) {
	}
	StrVec(std::initializer_list<string>&);
	StrVec(const StrVec&); // copy constructor
	StrVec &operator=(const StrVec&); // copy assignment
	~StrVec(); // destructor
	StrVec(StrVec&&);//move constructor
	StrVec& operator=(StrVec&&); //move assignment


	void push_back(const std::string&); // copy the element
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	int memLeft() const { return cap - first_free; } // our vector.capacity
	void reserve(const int&);
	void resize(const int&);
	void resize(const int&, const string&);
private:
	std::allocator<std::string> alloc; // allocates the elements
									   // used by the functions that add elements to the StrVec
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	// utilities used by the copy constructor, assignment operator, and destructor
	std::pair<std::string*, std::string*> alloc_n_copy // will allocate spance and copy a given range of elements.
	(const std::string*, const std::string*);
	void free(); // destroy the elements and free the space
	void reallocate(); // get more space and copy the existing
		std::string *elements; // pointer to the first element in the array
	std::string *first_free; // pointer to the first free element in the array
	std::string *cap; // pointer to one past the end of the array
	string* StrVec::resizeNDeallocate(const int& size);
};

StrVec::StrVec(StrVec&& sV) : alloc(sV.alloc), elements(sV.elements), first_free(sV.first_free), cap(sV.cap) {
	sV.alloc = std::allocator<string>();
	sV.elements = sV.cap = sV.first_free = nullptr;
}

StrVec& StrVec::operator=(StrVec&& sV) {
	if (this != &sV) {
		free();
		alloc = sV.alloc; elements = sV.elements; first_free = sV.first_free; cap = sV.cap;
		sV.elements = sV.cap = sV.first_free = nullptr;
	}
}

void StrVec::free() {
	if (elements) {
		while (elements != first_free) {
			alloc.destroy(--first_free);
		}
	}
	alloc.deallocate(elements, cap - elements);
}

void StrVec::free() {
	std::for_each(elements, first_free, [this](const string& temp) {
		alloc.destroy(&temp);
	});
	alloc.deallocate(elements, cap - elements);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* lhs, const std::string* rhs) {
	auto range = rhs - lhs;
	string* allocB = alloc.allocate(range);
	string* allocE = std::uninitialized_copy(elements, first_free, allocB);
	return{allocB,allocE};
}

void StrVec::reallocate() {
	auto range = (cap - elements) *2;
	string* allocB = alloc.allocate(range); 
	string* allocE = std::uninitialized_copy(elements, first_free, allocB);
	auto allocC = allocB + range;
	free();
	elements = allocB;
	first_free = allocE;
	cap = allocC;
}

StrVec::StrVec(const StrVec& temp) {
	auto pairs = alloc_n_copy(temp.begin(), temp.end());
	elements = pairs.first;
	first_free = pairs.second = cap;
}

StrVec::~StrVec() {
	free();
}

StrVec& StrVec::operator=(const StrVec& temp) {
	auto pairs = alloc_n_copy(temp.begin(), temp.end());
	free();
	elements = pairs.first;
	first_free = pairs.second = cap;
	return *this;
}

StrVec::StrVec(std::initializer_list<string>& temp) {
	auto range = temp.end() - temp.begin();
	string* allocBegin = alloc.allocate(range);
	string* allocEnd = std::uninitialized_copy(temp.begin(), temp.end(), allocBegin);
	elements = allocBegin;
	first_free = allocEnd;
	cap = allocBegin + range;
}

void StrVec::push_back(const string& temp) {
	chk_n_alloc();
	alloc.construct(first_free, temp);
	first_free++;
}

void StrVec::reserve(const int& size) {
	cap += size;
}

string* StrVec::resizeNDeallocate(const int& size) {
	if (size) {
		if (size > capacity()) {//check if we add elements
			alloc.allocate(size,cap);
			return cap + size;
		}
		else {//else we destroy elements and deallocate the memory.
			string* tempCap = elements + size;
			int deallocate = 0;
			while (cap != tempCap) {
				deallocate++;
				alloc.destroy(cap--);
			}
			alloc.deallocate(cap, deallocate);
			return cap;
		}
	}
	
}

void StrVec::resize(const int& size) {
	cap = resizeNDeallocate(size);
}

void StrVec::resize(const int& size, const string& temp) {
	string* tempCap = resizeNDeallocate(size);
	if (cap != tempCap) {
		while (tempCap != cap) {
			alloc.construct(cap++, temp);
		}
		cap = tempCap;
	}
	
}

#endif // !STRVEC
*/
//------------------------------------------------------------------------------------EXERCISE 13.50
/*
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <new>
#include <memory>
#include <vector>
#include "StrVec.h"
using std::string; using std::cout; using std::cin; using std::endl; using std::flush; using std::vector;

int main() {
	vector<String> VEC{ {"Hello World",12}, {"The time is neigh",18} };
	String x("ASDLASD", 8);
	String y("I'm the end.", 13);
	VEC.push_back(std::move(x));
	VEC.push_back(std::move(y));
	cout << String::copy << endl;
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.53
/*
HasPtr::HasPtr(HasPtr&& hP)  : ps(hP.ps),i(hP.i),use(hP.use){
	use++;
}

HasPtr& HasPtr::operator=(HasPtr&& hP) {
	if (this != &hP) {
		if (--(*use) == 0) {
			delete use;
			delete ps;
		}
		ps = hP.ps;
		i = hP.i;
		use = hP.use++;

	}
	return *this;
}
*/
//------------------------------------------------------------------------------------EXERCISE 13.55
/*
void StrBlob::pushBack(const string& t) && {
	strData->push_back(t);
}
*/