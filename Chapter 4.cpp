//EXERCISE 4.21
/*#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>
using std::string; using std::cin; using std::cout; using std::endl; using std::vector; using std::end; using std::begin;
int main()
{
	vector<int> numbers{ 3,6,4,2,9,2435,435,34,53,45,34,7,4,52,3,21,4326,7,86,687,432,43,1,4534,76,45,6,456,45,6,324,21,321,3,3,1,53,58,67,9,70,854,54,23,42,34,234,23,42 };
	for (int &n : numbers) {
		(n % 2 == 0) ? n : n *=2; //check precedence for why we put ()
	}
	for (int &n : numbers) {
		cout << n << endl;
	}
	system("pause");
	return 0;
	}
*/
//EXERCISE 4.22
/*
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>
using std::string; using std::cin; using std::cout; using std::endl; using std::vector; using std::end; using std::begin;
int main()
{
	int grade = 0;
	while (cin >> grade) {
		if (grade <0 || grade >100) {
			cout << "Enter valid grade"<< endl;
		}else {
			(grade > 75) ? (cout << "High Pass" << endl) : (grade > 60) ? (cout << "Pass" << endl) : (cout << "Fail" << endl)
		}
	}
	system("pause");
	return 0;
}*/
//EXERCISE 4.29
/*
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <array>
using std::string; using std::cin; using std::cout; using std::endl; using std::vector; using std::end; using std::begin;
int main()
{
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short : " << sizeof(short) << endl;
	cout << "Size of long : " << sizeof(long) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
	cout << "Size of long double : " << sizeof(long double) << endl;
	cout << "Size of string : " << sizeof(string) << endl;
	system("pause");
	return 0;
}
*/