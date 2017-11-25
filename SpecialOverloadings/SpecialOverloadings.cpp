// SpecialOverloadings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

istream& operator >> (istream& is, Integer& x) {
	is >> x.value;
	return is;
}

ostream& operator <<(ostream& os, const Integer& x) {
	os << x.value;
	return os;
}

Integer operator +(const Integer& x, const Integer& y) {
	return Integer(x.value + y.value);
}
class TestUnit;
class Unit {
	int hp;
	Unit(int hp = 100) {
		this->hp = hp;
	}
	void injure() {
		hp -= 25;
	}
	void heal() {
		hp += 25;
	}
	friend class TestUnit;
	friend void test(Unit x);
};
void test(Unit x) {
	x.injure();
	assert(x.hp == 75);
}
void print(Integer x) {
	cout << x.value << endl;
}

class TestUnit {
	void print(Unit u) {
		cout << u.hp;
	}
};

void f1() {
	Integer x(5);
	double s = (double)x;
	system("pause");
}

int main() {
	Integer x(5);
	cin >> x;
	cout << x << endl;
	system("pause");
	return 0;
}
