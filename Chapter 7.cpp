//---------------------------------------------------------------------EXERCISE 7.1
/*#include <iostream>
#include <string>
#include <vector>
#include "Sales_Data.h"
using namespace std;
int main() {
	while (cin) {
		Sales_data data1, data2;
		double price;
		cin >> data1.bookNo >> data1.units_sold >> price;
		data1.revenue = data1.units_sold * price;
		cin >> data2.bookNo >> data2.units_sold >> price;
		data2.revenue = data2.units_sold * price;
		if (data1.bookNo == data2.bookNo) {
			cout << data1.bookNo << " " << data1.units_sold + data2.units_sold << " " << data1.revenue + data2.revenue << endl;
		}
		else {
			cout << "Must be same isbn" << endl;
			return -1;
		}
	}
	system("pause");
	return 0;
}*/
//---------------------------------------------------------------------EXERCISE 7.2
/*#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
using namespace std;
struct Sales_data
{
	string bookNo;
	unsigned int units_sold;
	unsigned int revenue;
	Sales_data& combine(const Sales_data rs);
	string isbn();
};
#endif
Sales_data& Sales_data::combine(const Sales_data rs) {
	this->units_sold += rs.units_sold; //equivalent to units_sold += rs.units_sold, see pg 337-339
	this->revenue += rs.revenue;
	return *this;
}
string Sales_data::isbn() {
	return this->bookNo;
}*/
//---------------------------------------------------------------------EXERCISE 7.3
/*
#include <iostream>
#include <string>
#include <vector>
#include "Sales_Data.h"
using namespace std;
int main() {
	while (cin) {
		Sales_data data1, data2;
		double price;
		cin >> data1.bookNo >> data1.units_sold >> price;
		data1.revenue = data1.units_sold * price;
		cin >> data2.bookNo >> data2.units_sold >> price;
		data2.revenue = data2.units_sold * price;
		if (data1.isbn() == data2.isbn()) {
			const Sales_data unitTotal = data1.combine(data2);
			cout << data1.bookNo << " " << unitTotal.revenue << " " << unitTotal.revenue << endl;
		}
		else {
			cout << "Must be same isbn" << endl;
			return -1;
		}
	}
	system("pause");
	return 0;
}*/
//---------------------------------------------------------------------EXERCISE 7.4 
/*
#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;
struct Person {
	const string name;
	const string address;
	const string getName();
	const string getaddress();
};
const string Person::getName() {
	return this->name;
}
const string Person::getaddress() {
	return this->address;
}
#endif*/
//---------------------------------------------------------------------EXERCISE 7.6
/*
#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
using namespace std;
struct Sales_data
{
	string bookNo;
	unsigned int units_sold;
	unsigned int revenue;
	Sales_data& combine(const Sales_data rs);
	string isbn();
	Sales_data add(const Sales_data ls,const Sales_data rs);
};
// see http://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/
Sales_data& Sales_data::combine(const Sales_data rs) {// the reason why there is a & is because reference returns are Lvalues, built in operaends return their l values.//REMEMEBER LVALUES ARE LOCATIONS/CONTAINERS, & RETURNS THE ADDRESS
	this->units_sold += rs.units_sold; //equivalent to units_sold += rs.units_sold, see pg 337-339
	this->revenue += rs.revenue;
	return *this;
}
string Sales_data::isbn() {
	return this->bookNo;
}
Sales_data Sales_data::add(const Sales_data ls, const Sales_data rs) {
	Sales_data total = ls;
	total.combine(rs);
	return total;
}
istream& read(istream &i, Sales_data& main) { // read is a reference because we cannot copy the value, and we are also changing it (>> operators.)
	double price;
	i >> main.bookNo >> main.units_sold >> price;
	main.revenue = main.units_sold * price;
	return i;//because io streams return their lvalue.
}

ostream &print(ostream &o, const Sales_data &main) {
	o << main.bookNo << " " << main.units_sold << " " << main.revenue;
	return o;
}
#endif
*/
//---------------------------------------------------------------------EXERCISE 7.7
/*
#include <iostream>
#include <string>
#include <vector>
#include "Sales_Data.h"
using namespace std;
int main() {
	Sales_data total;
	if (read(cin,total)) {// taking first input
		Sales_data transaction;
		while (read(cin,transaction)) {//read other inputs.
			if (total.isbn() == transaction.isbn()) {
				total.combine(transaction);
			}
			else {
				print(cout, total) << endl;
				total = transaction;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cout << "No data? " << endl;
	}
	system("pause");
	return 0;
}*/
//---------------------------------------------------------------------EXERCISE 7.9
/*
istream& read(istream& i, Person main) {
	i >> main.name >> main.address;
	return i;
}
ostream& print(ostream& o, Person main) {
	o << main.name << main.address;
	return o;
}*/
//---------------------------------------------------------------------EXERCISE 7.11
/* IN CLASS
Sales_data() = default;//constructor
Sales_data(string b) : bookNo(b) {};
Sales_data(string b, int u) :bookNo(b), units_sold(u) {};
Sales_data(string b, int u, int p) : bookNo(b), units_sold(u), revenue(u*p) {};
Sales_data(istream i); <------ declared in the body

Sales_data::Sales_data(istream i) { <---- defined outside, constructors does not return anything, so there isn't a type.
	read(i, *this);
}
//constructor
IN MAIN FUNCTION
Sales_data main = { "hello" ,50,25};
print(cout, main) << endl;
*/
//---------------------------------------------------------------------EXERCISE 7.13 
/*	Sales_data total = { cin };
		Sales_data transaction;
		while (read(cin,transaction)) {//read other inputs.
			if (total.isbn() == transaction.isbn()) {
				total.combine(transaction);
			}
			else {
				print(cout, total) << endl;
				total = transaction;
			}
		}
		print(cout, total) << endl;

	system("pause");
	return 0;
}*/
//---------------------------------------------------------------------EXERCISE 7.14
/*
Sales_data() = default;//constructor
Sales_data(string b) : bookNo(b) {};
Sales_data(string b, int u) :bookNo(b), units_sold(u) {};
Sales_data(string b, int u, int p) : bookNo(b), units_sold(0), revenue(u*p) {};
Sales_data(istream i); <------ declared in the body

Sales_data::Sales_data(istream i) { <---- defined outside, constructors does not return anything, so there isn't a type.
read(i, *this);
}
*/
//---------------------------------------------------------------------EXERCISE 7.15
/*
Person() = default;
Person(string n) : name(n) {};
Person(string n, string a) : name(n), address(a) {};
*/
//---------------------------------------------------------------NEAR-FINAL IMPLEMENTATION OF SALES_DATA.H AND MAIN.CPP, UP TO SUB CHAPTER 7.3
//------------IN SALES_DATA.H
/*

#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
	friend istream& read(istream &i, Sales_data& main);
	friend ostream &print(ostream &o, const Sales_data &main);
public://implementation
	Sales_data() = default;//constructor
	Sales_data(string b) : bookNo(b) {};
	Sales_data(string b, int u) :bookNo(b), units_sold(u) {};
	Sales_data(string b, int u, int p) : bookNo(b), units_sold(u), revenue(u*p) {};
	Sales_data(istream& i);

	inline int avg_price(const Sales_data &r);
	Sales_data& combine(const Sales_data rs);
string isbn();
private://interface
	string bookNo;//objects
	unsigned int units_sold;
	unsigned int revenue;
};

int Sales_data::avg_price(const Sales_data &r) {
	 int p = ( (this->revenue/this->units_sold) + (r.revenue/r.units_sold) ) /2;
	 return p;
}
// see http://www.learncpp.com/cpp-tutorial/74a-returning-values-by-value-reference-and-address/ 
Sales_data& Sales_data::combine(const Sales_data rs) {// the reason why there is a & is because reference returns are Lvalues, built in operaends return their l values.//REMEMEBER LVALUES ARE LOCATIONS/CONTAINERS, & RETURNS THE ADDRESS
	this->units_sold += rs.units_sold; //equivalent to units_sold += rs.units_sold, see pg 337-339
	this->revenue += rs.revenue;
	return *this;
}
string Sales_data::isbn() {
	return this->bookNo;
}
Sales_data add(const Sales_data ls, const Sales_data rs) {
	Sales_data total = ls;
	total.combine(rs);
	return total;
}
istream& read(istream &i, Sales_data& main) { // read is a reference because we cannot copy the value, and we are also changing it (>> operators.)
	double price;
	i >> main.bookNo >> main.units_sold >> price;
	main.revenue = main.units_sold * price;
	return i;//because io streams return their lvalue.
}

ostream &print(ostream &o, const Sales_data &main) {
	o << main.bookNo << " " << main.units_sold << " " << main.revenue;
	return o;
}
Sales_data::Sales_data(istream& i) {
	read(i, *this);
}

#endif

#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;
struct Person {
	friend istream& read(istream& i, Person main);
	friend ostream& print(ostream& o, Person main);
public:
	Person() = default;
	Person(string n) : name(n) {};
	Person(string n, string a) : name(n), address(a) {};
	const string getName();
	const string getaddress();
private:
	string name;
	string address;
};
const string Person::getName() {
	return this->name;
}
const string Person::getaddress() {
	return this->address;
}
istream& read(istream& i, Person main) {
	i >> main.name >> main.address;
	return i;
}
ostream& print(ostream& o, Person main) {
	o << main.name << main.address;
	return o;
}

#endif*/
//-------------IN MAIN.CPP
/*#include <iostream>
#include <string>
#include <vector>
#include "Sales_Data.h"
using namespace std;
int main() {
	Sales_data total = { cin };
		Sales_data transaction;
		while (read(cin,transaction)) {//read other inputs.
			if (total.isbn() == transaction.isbn()) {
				total.combine(transaction);
			}
			else {
				print(cout, total) << endl;
				total = transaction;
			}
		}
		print(cout, total) << endl;

	system("pause");
	return 0;
}*/
//-----------------------------------------------------EXERCISE 7.27 - 7.30
//IN SALES_DATA.H (We're not changing the name here.)
/*#ifndef SCREEN
#define SCREEN
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Screen {
	using len = string::size_type;
	using pos = string::size_type;
public:
	Screen() = default;
	Screen(len w, len h, int n) : width(w), height(h), content(n,' ') {};
	Screen(len w, len h, char c) : width(w), height(h), content(h * w,c) {};

	Screen& move(pos r, pos c);
	Screen& set(pos r, pos c, char x);
	Screen& set(char x);
	Screen& display(ostream& i);
	const Screen& display(ostream& i) const;
	char get(pos r, pos c);
private:
	void displayContent(ostream &i) const;
	len width = 0, height = 0, cursor = 0;
	string content;
};
//http://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-c-method-declaration
void Screen::displayContent(ostream &i) const {//the const at the end returns the *this pointer to become const* this. When we use displayContent, the non const version is converted to const.
	i << this->content;
}

Screen& Screen::display(ostream& i) {
	this->displayContent(i);
	return *this;
}

const Screen& Screen::display(ostream& i) const {
	this->displayContent(i);
	return *this;
}

Screen& Screen::move(pos r, pos c) {//row, column
	pos row = r * this->width; 
	this->cursor = row + c; 
	return *this;
}
Screen& Screen::set(pos r, pos c, char x) {
	pos row = r* this->width;
	this->content[row + c] = x;
	return *this;
}

Screen& Screen::set(char x) {
	this->content[this->cursor] = x;
	return *this;
}

char Screen::get(pos r, pos c) {
	pos row = r * this->width; // compute row location
	return this->content[row + c]; // return character at the given column
}
#endif*/
//IN MAIN.CPP
/*#include <iostream>
#include <string>
#include <vector>
#include "Sales_Data.h"
using namespace std;
int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	system("pause");
	return 0;
}*/
//----------------------------------------------------------------------EXERCISE 7.31
/*
class Y;

class X {
	Y* ptr = nullptr;
};

class Y {
	X obj;
};
*/
//-------------------------------------------------------------------EXERCISE 7.32
/*
#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class win_mag {
public:
	void clear(int i);
private:
	vector<Screen> windows = {Screen()};
};

void win_mag::clear(int i) {
	Screen &remove = this->windows[i];
	remove.content = string(remove.height* remove.height, ' ');
}

#endif
*/
//------------------------------------------------------------------EXERCISE 7.38
/*
Screen(istream  &i = cin);
*/
//------------------------------------------------------------------EXERCISE 7.40
/*class Employee {
public:
	Employee(unsigned a,string n, string o, string t) :name(n), occupation(o), tele(t), age(a) {};
	Employee(unsigned a,string n, string o) : Employee(a,n,o," ") {}; ///<-----EXERCISE 7.46
private:
	unsigned age;
	string name;
	string occupation;
	string tele;
};*/
//------------------------------------------------------------------EXERCISE 7.45
/*
Screen(len w, len h, int n) : width(w), height(h), content(n, ' ') { cout << "Called in main" << endl; };
Screen(len w, len h, char c) : width(w), height(h), content(h * w,c) {};
Screen() : Screen(0, 0, 0) { cout << "Called in Screen()" << endl; };
Screen(len w) : Screen(w, 0, 0) { cout << "Called in Screen(w)" << endl; };
Screen(len w, len h) : Screen(w, h, static_cast<int>(w)*static_cast<int>(h)) { cout << "Called in Screen(w,h)" << endl; };
*/
//------------------------------------------------------------------EXERCISE 7.43
/*class NoDefault {
public:
	NoDefault(int x) :m(x) {};

private:
	int m;
};
class C {
public:
	C(NoDefault m) : x(m) {};
	C() : x(0) {};
private:
	NoDefault x;
};*/
//------------------------------------------------------------------EXERCISE 7.53
/*struct Debug {
	Debug(bool s, bool h, bool i, bool o) : sys(s), hw(h), io(i), other(o) {};
	Debug() = default;
	void all() {
		sys = true;
		hw = true;
		io = true;
		other = true;
	}
	bool sys = false; //system
	bool hw = false; //hardware
	bool io = false;
	bool other = false;

};*/
//-----------------------------------------------------------------EXERCISE 7.57
/*class Account {
public:
	Account(string o, unsigned b, unsigned s) :owner(o), balance(b), savings(s) {};
private:
	string owner;
	unsigned balance;
	unsigned savings;
	static float interestRate;
};
float Account::interestRate = 0.14;
*/
//---------------------------------------------------------------LAST IMPLENTATION OF WINDOWS MANAGER AND SCREEN
//----------IN SALES_DATA.H
/*#ifndef SCREEN
#define SCREEN
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class win_mag;
class Screen {
	friend win_mag;
	using len = string::size_type;
	using pos = string::size_type;
public:
	Screen(len w, len h, int n) : width(w), height(h), content(n, ' ') { cout << "Called in main" << endl; };
	Screen(len w, len h, char c) : width(w), height(h), content(h * w,c) {};
	Screen() : Screen(0, 0, 0) { cout << "Called in Screen()" << endl; };
	Screen(len w) : Screen(w, 0, 0) { cout << "Called in Screen(w)" << endl; };
	Screen(len w, len h) : Screen(w, h, static_cast<int>(w)*static_cast<int>(h)) { cout << "Called in Screen(w,h)" << endl; };


	Screen& move(pos r, pos c);
	Screen& set(pos r, pos c, char x);
	Screen& set(char x);
	Screen& display(ostream& i);
	const Screen& display(ostream& i) const;
	char get(pos r, pos c);
private:
	void displayContent(ostream &i) const;
	len width = 0, height = 0, cursor = 0;
	string content;
};
//http://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-c-method-declaration
void Screen::displayContent(ostream &i) const {//the const at the end returns the *this pointer to become const* this. When we use displayContent, the non const version is converted to const.
	i << this->content;
}

Screen& Screen::display(ostream& i) {
	this->displayContent(i);
	return *this;
}

const Screen& Screen::display(ostream& i) const {
	this->displayContent(i);
	return *this;
}

Screen& Screen::move(pos r, pos c) {//row, column
	pos row = r * this->width; 
	this->cursor = row + c; 
	return *this;
}
Screen& Screen::set(pos r, pos c, char x) {
	pos row = r* this->width;
	this->content[row + c] = x;
	return *this;
}

Screen& Screen::set(char x) {
	this->content[this->cursor] = x;
	return *this;
}

char Screen::get(pos r, pos c) {
	pos row = r * this->width; // compute row location
	return this->content[row + c]; // return character at the given column
}
#endif


#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class win_mag {
public:
	void clear(int i);
private:
	vector<Screen> windows = {Screen()};
};

void win_mag::clear(int i) {
	Screen &remove = this->windows[i];
	remove.content = string(remove.height* remove.height, ' ');
}

#endif
*/
//NOTHING IN MAIN.CPP
//END OF CHAPTER.