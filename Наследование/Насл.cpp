#include "Наследование.h"

Pair::Pair(int a, int b) {
	this->a = a;
	this->b = b;
}

Pair::Pair(void) {

	a = 0;

	b = 0;

}

Pair::~Pair(void) {

}

std::ostream& operator<< (std::ostream& out, Pair& p) {

	out << "(" << p.a << ", " << p.b << ")";

	return out;

}

bool Pair::isequal() {

	return (a == b);

}

int Pair::multiply() {

	return a * b;

}

Pair operator- (const Pair& q1, const Pair& q2) {

	return Pair(q1.a - q1.b, q2.a - q2.b);

}

Rational::Rational(int a, int b) {

	this->a = a;

	this->b = b;

}

Rational operator+ (const Rational& q1, const Rational& q2) {

	return Rational(q1.a * q2.b + q1.b * q2.a, q1.b * q2.b);

}

Rational operator/ (const Rational& q1, const Rational& q2) {

	return Rational(q1.a * q2.b, q1.b * q2.a);

}

Rational operator- (const Rational& q1, const Rational& q2) {

	return Rational(q1.a * q2.b - q1.b * q2.a, q1.b * q2.b);

}
