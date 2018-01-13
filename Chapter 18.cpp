//EXERCISE 18.3
/*
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	std::ifstream in("ints");
	if (in) {

	}
	else {
		delete p;
	}
}

void secondexercise(int*b, int*e) {
	vector<int> v(b, e);
	int *p = new int[v.size()];
	try {
		std::ifstream in("ints");
		in.exceptions(std::ifstream::failbit);
	}
	catch (std::ios_base::failure& fail) {
		cout << fail.what() << " \nat:" << fail.code() << endl;
	}
}
*/
//SIMPLE EXCEPTION CLASS
/*
class MyException : public std::out_of_range {
public:
	MyException(const std::string& a = "Error occured; no Message", const std::string& b = "") : std::out_of_range(a) {
		if (b.empty()) {
			programInfo.append("ERROR DETECTED IN FILE :  ");
			programInfo.append(__FILE__);
			programInfo.append("  ");
			programInfo.append(__TIME__);
		}
		else {
			programInfo.append(b);
		}
	};
	string myWhat() const {
		return programInfo;
	}
private:
	string programInfo;
};

int main() {
	try {
		throw MyException();
	}
	catch (const MyException& error) {
		cout << error.what() << endl;
		cout << error.myWhat() << endl;
	}
	catch (const std::out_of_range& err) {
		cout << err.what() << endl;
	}
	catch (...) {
		cout << "In catch all " << endl;
	}
	system("pause");
	return 0;
}
*/
