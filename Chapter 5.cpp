//EXERCISE 5.5
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string grades[6] = { "F","D","C","B","A","A++"};
	int grade;
	while (cin >> grade) {
		if (grade) {
			break;
		}
	}
	if (grade <= 50) {
		cout << "F-" << endl;
	}
	else if (grade <= 100) {
		cout << grade << endl;
		string g;
		if (grade == 100) {
			g = grades[5];
		}
		else if (grade <= 60) {
			g = grades[0];
		}
		else {
			g = grades[(grade - 50) / 10];
		}

		if (grade % 10 > 7) {
			g = g + '+';
		}
		else if (grade % 10 < 3) {
			g = g + '-';
		}
		cout << g << endl;
	}
	else {
		cout << "Give a grade between 0 and 100. " << endl;
	}
	system("pause");
	return 0;
}
*/
//EXERCISE 5.6
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
	string grades[6] = { "F","D","C","B","A","A++"};
	int grade;
	while (cin >> grade) {
		if (grade) {
			break;
		}
	}
	if (grade <= 50) {
		cout << "F-" << endl;
	}
	else if (grade <= 100) {
		cout << grade << endl;
		string g;
		(grade == 100) ? (g = grades[5]) : (grades <=60) ? (g = grades[0]) : (g = grades[(grades-50)/10]);

		(grade %10 > 7) ? (g= g+ '+') : (grade %10 < 3) ? (g = g+ 'i') : g;

		cout << g << endl;
	}
	else {
		cout << "Give a grade between 0 and 100. " << endl;
	}
	system("pause");
	return 0;
}*/
//EXERCISE 5.9 & 5.10
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input;
	unsigned int va = 0, vu = 0, vi = 0, vo = 0, ve = 0;
	while (getline(cin, input)) {
		for (auto &m : input) {
			switch (m) {
			case 'A': case 'a':
				va++;
				break;
			case 'U': case 'u':
				vu++;
				break;
			case 'I' :case 'i':
				vi++;
				break;
			case 'O' :case 'o':
				vo++;
				break;
			case 'E' :case 'e':
				ve++;
				break;
			}
		}
		cout << "A :" << va << "\n";
		cout << "U : " << vu << "\n";
		cout << "I : " << vi << "\n";
		cout << "O : " << vo << "\n";
		cout << "E : " << ve << endl;
	}
	system("pause");
	return 0;
}
*/
//EXERCISE 5.11
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input;
	unsigned int space = 0, tab = 0, nl = 0;
	while (getline(cin, input)) {
		for (auto &m : input) { 
			switch (m) {
			case '\40': // note /40 is ASCII encoding for a space, same with \11 and \12.
				space++;
				break;
			case '\11':
				tab++;
				break;
			case '\12':
				nl++;
				break;
			}
		}
		cout << "Spaces : " << space << "\n";
		cout << "Tabs : " << tab << "\n";
		cout << "New Lines : " << nl << endl;
	}
	system("pause");
	return 0;
}*/
//EXERCISE 5.12
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input;
	unsigned int ff = 0, fl = 0, fi = 0;
	while (getline(cin, input)) {
		char c = '\0';
		for (auto &m : input) {
			switch (m) {
				case 'f':
					if (c == 'f') {
						ff++;
					}
					break;
				case 'l':
					if (c == 'f') {
						fl++;
					}
					break;
				case 'i':
					if (c == 'f') {
						fi++;
					}
					break;
			}
			c = m; // check previous character.
		}
		cout << "ff : " << ff << "\n";
		cout << "fl : " << fl << "\n";
		cout << "fi : " << fi << "\n";
	}
	system("pause");
	return 0;
}
*/
//EXERCISE 5.14
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string entireWord;;
	while (getline(cin, entireWord)) {
		vector<string> words;
		string::iterator beg = entireWord.begin();
		string::iterator beg1 = entireWord.begin();
		string::iterator x = entireWord.end();
		int m = *(--x);
		while (beg != entireWord.end()) {//first we put all the words into vector, words.
			if (beg == entireWord.end() - 1) {
				words.push_back(entireWord.substr(beg1 - entireWord.begin(), beg - beg1));
				beg1 = beg + 1;
				beg++;
			}
			else if (*beg != ' ') {
				beg++;
			}
			else {
				words.push_back(entireWord.substr(beg1 - entireWord.begin(), beg-beg1));
				beg1 = beg+1;
				beg++;
			}
		}
		bool occurence = false;
		vector<string> repeatedWords; // since we must use two iterators, we need to see if we are repeating our process.
		for (vector<string>::iterator begin = words.begin(); begin != words.end(); begin++) { //then we must use two iterators to see if one element has duplicate copies.
			int sum = 0;
			string str = *begin;
			if (find(repeatedWords.begin(), repeatedWords.end(), str) != repeatedWords.end()) {//checks if we have already done that word
				;
			}
			else {
				bool occurence1 = false;// checking if there is a word that repeats.
				for (vector<string>::iterator begin1 = begin; begin1 != words.end(); begin1++) {
					if (*begin1 == str) {
						occurence1 = true;
						sum++;
					}
				}
				if (occurence1) {
					repeatedWords.push_back(str);
				}
			}
			

			if (sum > 1) {// one since when begin1 passes, it will count the one its on.
				cout << str << " occured " << sum << " times." << endl;
				occurence = true;
			}
		}
		if (!occurence) {
			cout << "No repeated words." << endl;
		}
	}
	system("pause");
	return 0;
}*/
//EXERCISE 5.17
/*Cannot understand its meaning.*/
//EXERCISE 5.19
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
	string m;
	do {
		cout << "Input two strings, and see which is larger." << endl;
		string s, s1;
		getline(cin, s);
		getline(cin, s1);
		if (s.size() > s1.size()) {
			cout << s << " is bigger." << endl;
		}
		else if (s1.size() > s.size()) {
			cout << s1 << " is bigger." << endl;
		}
		else {
			cout << "Strings are similar in length. " << endl;
		}
		cout << "Do you want to run it again? Y/N" << endl;
		cin >> m;
		cin.ignore(); //cin >> inputs a '\n', and cin and getline both read up to the first '\n', so without this s string would be empty.
	} while (m == "y" || m=="Y");
	system("pause");
	return 0;
}*/
//EXERCISE 5.20
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout << "Enter words to see if they are repeated. " << endl;
	string x;
	string m = "\0";
	bool n = true;
	while (cin >> x) {
		if (x == m) {
			cout << x << " used in sucession. " << endl;
			n = false;
			break;
		}
		else {
			m = x;
		}
	}
	if (n) {
		cout << "No words repeated" << endl;
	}
	system("pause");
	return 0;
}*/
//EXERCISE 5.21
/*#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	cout << "Enter words to see if the first character is repeated. " << endl;
	string x;
	string m = "";
	bool n = true;
	while (cin >> x) {
		if (isupper(x[0]) == isupper(m[0]) && x[0] == m[0]) {
			cout << x[0] << " used in sucession. " << endl;
			n = false;
			continue;
		}
		else {
			m = x;
		}
	}
	if (n) {
		cout << "No words repeated" << endl;
	}
	system("pause");
	return 0;
}*/
//EXERCISE 5.22
/*#include <iostream>
using namespace std;
int main()
{
	int sz = get_size();
	while (sz <= 0) {
		sz = get_size();
	}
	system("pause");
	return 0;

}*/
//EXERCISE 5.23-5.25
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout << "Enter two numbers, the first will be divided by the second." << endl;
	int one = 0, two = 0;
	while (cin >> one >> two) {
		try {
			if (two == 0) {
				throw invalid_argument("Cannot divide by zero");
			}
			else {
				cout << static_cast<float>(one)/two << endl;
				cout << "Enter two numbers, the first will be divided by the second." << endl;
			}
		}
		catch (invalid_argument err) {
			cout << "Invalid number entered, Try again? y/n" << endl;
			char x;
			cin >> x;
			if (x == 'n' || x == 'N')
				break;
			else
				cout << "Enter two numbers, the first will be divided by the second." << endl;
				continue;
		}
	}
	system("pause");
	return 0;
}*/