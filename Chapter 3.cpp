//----------------------------------------EXERCISE 3.42-------------------------------------------//
/*
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>
using std::string; using std::cin; using std::cout; using std::endl; using std::vector; using std::end; using std::begin;
int main()
{
vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
int m = v1.size();
int a[10] = {};
vector<int>::iterator b = v1.begin();
for (int *s = begin(a); s != end(a); s++) {
	*s = *b;
	b++;
}
for (auto &x : a) {
	cout << x << endl;
}
system("pause");
return 0;
}*/
//----------------------------------------EXERCISE 3.43-3.45------------------------------------------//
/*
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>
using std::string; using std::cin; using std::cout; using std::endl; using std::vector; using std::end; using std::begin;
int main()
{
const int rowCount = 3, rowColumb = 4;
int ia[rowCount][rowColumb] = { 0,1,2,3,
								4,5,6,7,
								8,9,10,11 };
//Third way using pointers and iterators (iterators are pointers).
for (int(*x)[4] = begin(ia); x != end(ia); x++) {
	for (int *z = begin(*x); z != end(*x); z++) {
		cout << *z << endl;
	}
}
//
//Second Way - subscripts.
for (int x = 0; x <= rowCount -1; x++) {
	for (int z = 0; z <= rowColumb -1; z++) {
		cout << ia[x][z] << endl; // ia[2] == *(ia + 3)
	}
}
//

//First Way - Ranged Loops.
for (int(&x)[4] : ia) {
	for (int &z : x) {
		cout << z << endl;
	}
}
//Note-
The reason why there is a parenthesis around the reference with a subscript four is because the reference and the array your making a refernece to must be equal types
When you are accessing ia, remember that the statement ia is finding the first element with the index of 0.
In this example ia in index 0 is an array of ints, which means the reference must also have an array of four ints for it to be the same.
Without the (), it creates a array of four references.
The same is with pointers.
//
system("pause");
return 0;
}
*/