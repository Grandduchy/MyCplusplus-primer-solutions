//------------------------------------------------------------------------------EXERCISE 16.4
/*
template<typename IterT, typename VT>
IterT find(const IterT a, const IterT b, const VT c) {
	IterT OA = a, OB = b;
	while (OA != OB) {
		if (*OA == c)
			return OA;
		OA++;
	}
		return OB;
}
*/
//------------------------------------------------------------------------------EXERCISE 16.5
/*
template<typename T,unsigned int N>
void print(const T(&a)[N]) {
	int x = 0;
	while (x != N) {
		cout << *(a+x) << endl;
		x++;
	}
}

*/
//------------------------------------------------------------------------------EXERCISE 16.6
/*
//there are errors.
template<unsigned N, typename T>
T* begin(const T (&a)[N]) {
	return &a[0];
}

template<typename T>
auto begin(T a) {
	return a.begin();
}

template<unsigned N,typename T>
T* end(const T(&a)[N]) {
	return &a[N];
}

template<typename T>
auto end(const T a) {
	return a.end();
}
*/
//------------------------------------------------------------------------------EXERCISE 16.7
/*
template<unsigned N, typename T> constexpr
int size(const T (&a)[N]) {
	return N;
}
*/
//------------------------------------------------------------------------------EXERCISE 16.19
/*
template<typename T = vector<string>>
void print(const T& container) {
	typename T::size_type x = container.size();
	for (int m = 0; m != x; m++) {
		cout << container[m] << endl;
	}
}

*/
//------------------------------------------------------------------------------EXERCISE 16.20
/*
template<typename T = vector<string>>
void print(const T& container) {
	typename T::const_iterator begin = container.begin();
	typename T::const_iterator end = container.end();
	while (begin != end) {
		cout << *begin << endl;
		begin++;
	}
}
*/
//------------------------------------------------------------------------------EXERCISE 16.21
/*
struct DebugDelete {
	template<typename T>
	void operator()(T& p) {
		cout << "Deleting : "<<typeid(T).name() <<" : "<< endl;
		delete p;
	}
};
*/
//------------------------------------------------------------------------------NON REVISED BLOB, BEFORE 16.2 CHAPTER.
/*
#pragma once
#include <string>
#include <new>
#include <memory>
#include <vector>
#include <initializer_list>
using std::string; using std::endl; using std::flush; using std::vector; using std::shared_ptr; using std::weak_ptr;

template<typename> class BlobPtr;
template<typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

#ifndef BLOB
#define BLOB

template<typename T> class Blob {
	friend class BlobPtr<T>;
public:
	Blob() : data(new vector<T>) {};
	Blob(std::initializer_list<T>);
	template<typename Iter> Blob(Iter&, Iter&);
	T& operator[](const int&) const;
	void pushBack(const T&);
	T& back() const;
	T& front() const;
private:
	shared_ptr<vector<T>> data;
	void check(const int&, const string&) const;
};

template<typename T> template<typename Iter>
Blob<T>::Blob(Iter& begin, Iter& end) {
	while (begin != end) {
		data->push_back(*begin);
		begin++;
	}
}

template<typename T>
void Blob<T>::check(const int& integer, const string& message) const {
	if (integer <= 0) {
		std::runtime_error::runtime_error(message);
	}
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(new vector<T>()){
	auto b = il.begin();
	while (b != il.end()) {
		this->data->push_back(*b);
		b++;
	}
}

template<typename T>
T& Blob<T>::back() const {
	check(data->size(), "Back called on empty Blob");
	return this->data->back();
}

template<typename T>
T& Blob<T>::front() const {
	check(data->size(), "Front called on empty Blob");
	return this->data->front();
}

template<typename T>
T& Blob<T>::operator[](const int& i) const {
	check(data->size() - i, "Subscript operator out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::pushBack(const T& item) {
	data->push_back(item);
}

#endif // !BLOB

#ifndef BLOBPTR
#define BLOBPTR


template<typename T>
class BlobPtr {
	friend class Blob<T>;
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() : index(0), wkptr(nullptr) {};
	BlobPtr(const Blob<T>& b) : index(0), wkptr(b.data) {};
	BlobPtr(const Blob<T>& b, const int i) : index(i), wkptr(b.data) {};
	BlobPtr<T>& operator++(); //prefix
	BlobPtr<T>& operator--();
	BlobPtr<T> operator++(int);//postfix
	BlobPtr<T> operator--(int);
	T& operator*();
private:
	unsigned int index;
	weak_ptr<vector<T>> wkptr;
	shared_ptr<vector<T>> check(const int& integer, const string& message) const;
};

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(const int& integer, const string& message) const {
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

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	index++;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	check("Pre/Postfix decrement operator on BlobPtr<" + T + ">, reached out of bounds.");
	index--;
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr<T> t = *this;
	index++;
	return t;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr<T> t = *this;
	BlobPtr<T>::operator--();
	return t;
}

template<typename T>
T& BlobPtr<T>::operator*() {
	auto m = check(index, "Dereference on BlobPtr out of bounds");
	return (*m)[index];
}

template<typename T> 
bool operator==(const BlobPtr<T>& rhs, const BlobPtr<T>& lhs) {
	return lhs.index == rhs.index && lhs.wkptr.lock() == rhs.wkptr.lock();
}

template<typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	return !(lhs == rhs);
}

#endif // !BLOBPTR
*/
//------------------------------------------------------------------------------EXERCISE 16.41
/*
template<typename T1, typename T2>
sum(T1 a, T2 b) -> decltype(a + b) { return a + b; }
*/
//------------------------------------------------------------------------------EXERCISE 16.48-16.50
/*
template<typename T>
void debug(const T* a) {
	cout << "in const T* a" << endl;
	cout << string(a) << endl;
}

template<typename T>
void debug(const T& a) {
	cout << "in const T& a" << endl;
	cout << a << endl;
}

template<typename T>
void debug(T a) {
	cout << "in T" << endl;
	cout << a << endl;
}

void debug(const string& a) {
	cout << "in string" << endl;
	cout << a << endl;
}

*/
//------------------------------------------------------------------------------EXERCISE 16.53
/*
template<typename T>
void print(ostream& os , T&& t) {
	os << t << flush;
}

template<typename T,typename...Args>
void print(ostream& os, T&& t, Args... args) {
	os << t << endl;
	print(os, args...);
}
*/

//------------------------------------------------------------------------------EXERCISE 16.61
/*
template<typename T,typename ...ArgsT>
std::shared_ptr<T> share(ArgsT&&... args) {
	return std::shared_ptr<T>(new T(std::forward<ArgsT>(args)...));
}
*/

//------------------------------------------------------------------------------EXERCISE 16.63-16.64
/* //NOTE - cannot figure out how to make the vector work with occurances since vector has <allocator> and a lot more stuff.
template<typename C,typename T>
size_t occurances(C&& vec, T&& value) {
	size_t occ = 0;
	std::for_each(vec.begin(), vec.end(), [&](const T& a) { if (a == value) { occ++; }});
	return occ;
}

template<>
size_t occurances(const vector<const char*>&& vec, char&& value) {
	size_t occ = 0;
	auto begin = vec.begin(), end = vec.end();
	while (begin != end) {
		if (**begin == value) {
			occ++;
		}
	}
	return occ;
}
*/
