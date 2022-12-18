#include <iostream>
class Pair {
public:
	Pair(void);
	Pair(int, int);
	~Pair(void);
	bool isequal();
	int multiply();
	friend Pair operator- (const Pair&, const Pair&);
	friend std::ostream& operator<< (std::ostream& out, Pair& p);
	int a, b;
};
class Rational : public Pair {
public:
	friend Rational operator+ (const Rational&, const Rational&);
	friend Rational operator/ (const Rational&, const Rational&);
	friend Rational operator- (const Rational&, const Rational&);
	Rational(int, int);
};