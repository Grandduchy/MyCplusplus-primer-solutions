//--------------------------------------------EXERCISE 6.3 - 6.4
/*#include <iostream>
#include <string>
using namespace std;
int factorial(int v1, int v2) { // accepts two numbers and checks their factorial.
	if (v2 > v1) {
		int m = v1;
		v1 = v2;
		v2 = m;
	}
	int sum = 0;
	while (v1 >= v2) {
		sum += v1--;
	}
	return sum;
}
int main() {
	int v1, v2;
	while (cin >> v1 >> v2) {
		cout << factorial(v1,v2)<< endl;
	}
	system("pause");
	return 0;
}*/
//--------------------------------------------EXERCISE 6.7
/*#include <iostream>
#include <string>
using namespace std;
int count() { 
	static int x= 0;
	return x++;
}
int main() {
	count();
	count();
	cout << count() << endl;
	system("pause");
	return 0;
}*/
//--------------------------------------------EXERCISE 6.8
// IN A .H(HEADER) FILE
/*
#include <iostream>
#include <string>
int count() { 
	static int x= 0;
	return x++;
}
int factorial(int v1, int v2) { // accepts two numbers and checks their factorial.
	if (v2 > v1) {
		int m = v1;
		v1 = v2;
		v2 = m;
	}
	int sum = 0;
	while (v1 >= v2) {
		sum += v1--;
	}
	return sum;
}
*/
// IN .CPP(C++) FILE
/*
int count ();
int factorial;
*/
//--------------------------------------------EXERCISE 6.10
/*int swap(int *n, int *n1) {
	int m = *n;
	*n = *n1;
	*n1 = m;
	return 0;
//////////////////////
#include <iostream>
#include <string>
#include "Functions_6.h"
using namespace std;
int main() {
	int q = 20, w = 50;
	int *m = &q, *n = &w;
	swap(m, n);
	cout << *m << " "<< *n << endl;
	system("pause");
	return 0;
}
}*/
//--------------------------------------------EXERCISE 6.16- 6.17
/*
#include <iostream>
#include <string>
#include <cctype>
#include "Functions_6.h"
using namespace std;
string capital(string x,int&z);
int main() {
	int count = 0;
	string x = "Hello World! Its a Good Day Today!";
	x = capital(x, count);
	cout << x << "\n contains " << count << " capital letters." << endl;
	system("pause");
	return 0;
}


string capital (string x,int&z) {
	z = 0;

	for (char &n : x) {
		if (isupper(n)) {
			z++;
			n = tolower(n);
		}
	}
	return x;
}*/
//--------------------------------------------EXERCISE 6.25-6.26
/*#include <iostream>
#include <string>
#include <cctype>
#include "Functions_6.h"
using namespace std;

int main(int argc, char *args[]) { // first argument is amount of args, second argument is an array with c style strings(which is an array of characters).
	for (int x = 0; x < argc; x++) {
		cout << args[x] << endl;
	}
	system("pause");
	return 0;
}*/
//--------------------------------------------EXERCISE 6.27
/*#include <iostream>
#include <initializer_list>
#include "Functions_6.h"
using namespace std;
int sum(initializer_list<int> numbers) {//initalizer_lists are const values.
	int sum = 0;
	for (const int x : numbers) {
		sum += x;
	}
	return sum;
}
int main() {
	cout << sum({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 92 }) << endl;
	system("pause");
	return 0;
}
*/
//--------------------------------------------EXERCISE 6.33
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;

void content(vector<string> strings, int const index) {
	if (index >= 0 && index != strings.size()) {
		cout << strings[index] << endl;
		content(strings, index + 1);
	}
	else {
		return;
	}
}

int main() {
	vector<string> s = { "Hello","world","How","Do","you","do?" };
	content(s,0);
	system("pause");
	return 0;
}
*/
//--------------------------------------------EXERCISE 6.37
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int(&arr(int a[10]))[10] {};//Without any
using a = int[10];// Using 
a &arr(int a[10]) {}; // Type Alsis
auto &ar(int a[10]) -> int(&)[10] {};//Trailing return

int main() {
	system("pause");
	return 0;
}
*/
/*
Trailing Returns
void foo (void ) {
    cout << "Meaning of life: " << 42 << endl;
}
====
auto bar (void) -> void {
    cout << "More meaning: " << 43 << endl;
}
*/
//--------------------------------------------EXERCISE 6.38
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int odd[] = { 1,3,5,7,9 };
int even[] = { 0,2,4,6,8 };
decltype(odd) &arrPtr(int i) {
	return (i % 2) ? odd : even; // returns a pointer to the array
}
int main() {
	system("pause");
	return 0;
}
*/
//--------------------------------------------EXERCISE 6.54-6.56
/*#include <iostream>
#include <string>
#include <vector>
using namespace std;

int add(int &n1, int &n2) {
	return n1 + n2;
}
int subtract(int &x, int &y) {
	return x - y;
}
int multiply(int &x, int &y) {
	return x * y;
}
int divide(int &x, int &y) {
	return x / y;
}

int main() {
	int n1 = 5, n2 = 20;
	vector<int*> g{&n1, &n2};
	add(n2, n1);
	multiply(n1, n2);
	add(n2, n1);
	subtract(n1, n2);
	divide(n1, n2);
	for (int* &m : g) {
		cout << *m << endl; // same values because we did not do anything with the function results.
	}

	system("pause");
	return 0;
}*/
