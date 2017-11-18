// Group3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class A {
public:
	int x, y, z;
	string s;
	A() {}
	A(int x) {
		this->x = x;
	}
	A(int x, int y) : A(x) {
		this->y = y;
	}
	A(int x, int y, int z, string s) :A(x, y) {
		this->z = z;
		this->s = s;
	}
};

class String {
public:
	string *s;
	String() {}
	explicit String(string s) {
		this->s = new string(s);
	}
	~String() {
		delete s;
	}
};

class Vector {
public:
	String *arr;
	int *size;
	void print() const {
		cout << *size;
	}
	Vector(int n) {
		size = new int(n);
		arr = new String[n];
	}
	~Vector() {
		delete[] arr;
		delete size;
	}
	//const - чтобы обязательно указать, что первые вектор при создании второго в конструкторе не изменится
	Vector(Vector& const anotherVector) {
		size = new int(*anotherVector.size);
		arr = new String[*anotherVector.size];
		for (int i = 0; i < *anotherVector.size; ++i) {
			this->arr[i] = anotherVector.arr[i];
		}
	}
};

void f1() {
	A a(1, 2, 3, "asd");
	A b = a;
	b.s = "";
	cout << a.s;
}

void f2() {
	//shadow/shallow cloning
	//побитовое копирование
	Vector *v1 = new Vector(2);
	Vector *v2 = v1;
}

void f3() {
	//deep cloning
	Vector *v1 = new Vector(2);
	Vector *v2 = new Vector(*v1);
}

void f4() {
	Vector *v1 = new Vector(2);
	v1->print();
	delete v1;
}

void f5() {
	//проверьте с explicit и без
	/*String s1 = "csac";
	String s2("csac");*/
}

class Integer {
private:
	int value;
public:
	//Integer(Integer&&) = default;
	Integer() = default;
	explicit Integer(int x) : value(x) {
	}
	Integer operator =(const int& value) {
		this->value = value;
		return *this;
	}
	Integer operator =(const bool& value) {
		this->value = value;
		return *this;
	}
	//затирание
	friend Integer operator +(const Integer& left, const Integer& right);
	friend void test(Integer x);
	//prefix
	Integer operator ++() {
		++this->value;
		return *this;
	}
	//postfix
	Integer operator ++(int) {
		Integer old = Integer(value);
		++this->value;
		return old;
	}
	const bool operator ==(const Integer& another) const {
		return another.value == this->value;
	}
	Integer operator +=(const Integer& another) {
		this->value += another.value;
		return *this;
	}
	operator int() {
		return this->value;
	}
	int getValue() {
		return value;
	}
	/*ostream& operator <<(ostream& stream) {
		stream << this->value;
		return stream;
	}*/
};

Integer operator +(const Integer& left, const Integer& right) {
	Integer x = Integer(left.value + right.value);
	return x;
}
void test(Integer x) {
	x.value = 5;
	assert(x.getValue(), 5);
}

void f6() {
	/*Integer x(5);
	x = 10;
	cout << x.value << endl;
	Integer y(11);
	Integer z = x + y;
	cout << z.value << endl;
	cout << z++.value << endl;
	cout << z.value << endl;
	z += y;
	cout << z.value << endl;
	Integer k = move(z);
	Integer i();*/
}
class Progression {
	int a1, d;
public:
	Progression(int a1, int d) {
		this->a1 = a1;
		this->d = d;
	}
	//a(n) = a(1) + d(n - 1)
	int operator [](int n) {
		return n;
	}
	int operator()(int n) {
		return a1 + d * (n - 1);
	}
};

void f7() {
	Progression progression(5, 6);
	for (int i = 0; i < 10; ++i) {
		cout << "i: " << progression[i] << ", a(n): " << progression(i) << endl;
	}
}
int main() {
	Integer x(5), z(5);
	Integer j = x + z;
	int y = x;
	cout << y << endl;
	system("pause");
	return 0;
}
//*, ; .