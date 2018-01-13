//A LOT OF EXERCISES DEFINED IN QUOTE.H COMBINED.
//EXERCISE 15.7
/*
class Book {
public:
	Book(const string b, const double n, const double d) : bookName(b), price(n), discount(d) {};
	string name() const { return bookName; };
	virtual double total() const {
		return price * discount;
	}
protected:
	double price;
	double discount;
private:
	string bookName;
};

std::ostream& print(const Book& b, const size_t& = 1) {
	double x = b.total();
	cout << b.name() << " " << b.total();
	return cout;
}

class Books : public Book {
public:
	Books(const string b, const double n, const double d, const int limits,const int qut) : Book(b, n, d), limit(limits), quantity(qut) {};
	double total() const override {
		if (quantity >= limit) {
			return this->price;
		}
		else {
			return this->price*discount;
		}
	}
private:
	int limit;
	int quantity;
};
*/

//EXERCISE 15.16
/*
class LDS  : public DiscQuote {
public:
	LDS() : DiscQuote("", 0, 0, 0) {};
	LDS(const string& book, const double& pri, const size_t& qty, const double& disc, const short& lim) : DiscQuote(book, pri, qty, disc), limit(lim) {};
	virtual double netPrice(const size_t&) override {
		if (limit < quantity) {
			return price* quantity;
		}
		else {
			return (price*quantity) * discount;
		}
	}
private:
	unsigned short limit;
};
*/
//EXERICSE 15.22
/*
class Geometry {
public:
	Geometry() = default;
	virtual ~Geometry() {};
	virtual int area() = 0;
};

class TwoDimensional : public Geometry {
public:
	TwoDimensional(const unsigned int& w = 0, const unsigned int& l = 0) : width(w),length(l){};

protected:
	unsigned int width;
	unsigned int length;
};

class ThreeDimensional : public Geometry{
public:
	ThreeDimensional(const unsigned int& w = 0, const unsigned int& l = 0, const unsigned int& h = 0) : width(w), length(l), height(h) {};
	virtual int volume() = 0 ;
protected:
	unsigned int height;
	unsigned int width;
	unsigned int length;
};

class Square : public TwoDimensional {
public:
	Square(const unsigned int& w, const unsigned int& l = 1) : TwoDimensional(w, l) {};
	virtual int area() const {
		return this->width * this->length;
	}
	int perimator() const {
		return this->width * 4;
	}
private:
};

class Cube : public ThreeDimensional {
public:
	Cube(const unsigned int& w, const unsigned int& l, const unsigned int & h) : ThreeDimensional(w, l, h) {};
	virtual int area() const {
		return (this->width* this->length) * 6;
	}
	virtual int volume() const {
		return this->height* this->length * this->width;
	}

};
*/
//EXERCISE 15.23
/*
class Base {
public:
	virtual int fn();
};

class D1 : public Base {
public:
	using Base::fn;
	virtual int fn(int&);
	virtual void f2();
};

int main() {
	D1 a;
	a.fn();
	system("pause");
	return 0;
}
*/
//EXERCISE 15.26
//VISUALIZATION OF HOW COPYING OCCURS IN DERIVED TO BASE CLASSES
/*
class Quote { //base class
public:
	//constructors
	Quote() = default;
	Quote(const string& id, const double& pr) : price(pr), bookNo(id) {};
	Quote(const Quote&);
	Quote& operator=(const Quote&);
	//methods
	virtual double netPrice(const size_t&);
	virtual std::ostream& debug(std::ostream& os) { std::cout << "Price: " << price << "BookNo: " << bookNo; return os; }
	string isbn() const { return bookNo; };
	virtual ~Quote() {};
protected:
	double price;
private:
	string bookNo;
};

Quote::Quote(const Quote& q) {
	price = q.price;
	bookNo = q.bookNo;
	printf("copy constructor");
}

Quote& Quote::operator=(const Quote& q) {
	price = q.price;
	bookNo = q.bookNo;
	printf("copy assignemnet operator/constructor");
	return *this;
}

double printTotal(std::ostream& os, Quote& qut, size_t quantity) { //returns the price of the total amount of books.
	double localPrice = qut.netPrice(quantity);
	os << "ISBN:: " << qut.isbn() << " Numbers sold:: " << quantity << " Amount due:: " << localPrice;
	return localPrice;
}

double Quote::netPrice(const size_t& sz = 1) {
	return sz * this->price;
}



class DiscQuote : public Quote {//our abstract base class
public:
	DiscQuote() = default;
	DiscQuote(const string& id, const double& pri, const size_t& quant, const double disc) : Quote(id, pri), quantity(quant), discount(disc) {};
	DiscQuote(const DiscQuote& dQ) : quantity(dQ.quantity), discount(dQ.discount) { Quote(dQ.isbn(), dQ.price); printf("copy constructor"); };
	DiscQuote& operator=(const DiscQuote& dQ);
	virtual double netPrice(const size_t&) override  = 0;
protected:
	size_t quantity = 0;
	double discount = 0;
};

DiscQuote& DiscQuote::operator=(const DiscQuote& dQ) {
	this->quantity = dQ.quantity;
	this->discount = dQ.discount;
	Quote::operator=(dQ);
	printf("copy assignment operaotr/constructor");
	return *this;
}

class BulkQuote : public DiscQuote {
public:
	BulkQuote() = default;
	BulkQuote(const string& id, const double& pri, const size_t& quant, const double disc) : DiscQuote(id,pri,quant,disc){};
	BulkQuote(const BulkQuote&);
	BulkQuote& operator=(const BulkQuote&);
	virtual double netPrice(const size_t&) override;
};

BulkQuote::BulkQuote(const BulkQuote& bQ)  : DiscQuote(bQ) {
	printf("Copy constructor");
}

BulkQuote& BulkQuote::operator=(const BulkQuote& bQ) {
	DiscQuote::operator=(bQ);
	printf("copy assignment operator/constructor");
	return *this;
}

double BulkQuote::netPrice(const size_t& a = 0) {
	return (price*quantity) * discount;
}
*/
//EXERCISE 15.28
/*
vector<std::shared_ptr<Quote>> quotes;
	quotes.emplace_back(new BulkQuote("hello", 23, 3, 0.5));

	double sum = 0;
	for (auto m : quotes) {
		sum+=m->netPrice();
	}
*/
