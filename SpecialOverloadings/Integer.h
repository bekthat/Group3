#pragma once
class Integer {
	int value;
public:
	explicit Integer(int i) : value(i) {
	}
	explicit operator double() {
		return value;
	}
	friend void print(Integer x);
	//Test Driven Development
	//Unit tests
	friend void test(Integer x);
	friend Integer operator +(const Integer& x, const Integer& y);
	friend std::ostream& operator <<(std::ostream& os, const Integer& x);
	friend std::istream& operator >> (std::istream& is, Integer& x);
};