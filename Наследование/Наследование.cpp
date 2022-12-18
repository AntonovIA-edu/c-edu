#include "Наследование.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Pair q(10, 9);
	if (q.isequal()) std::cout << "Числа равны\n";
	else std::cout << "Числа не равны\n";
	std::cout << "Произведение полей равно " << q.multiply();
	std::cout << "\n";
	Pair q1(10, 4);
	Pair q2(5, 1);
	Pair q3 = q1 - q2;
	std::cout << q3 << "\n";
	Rational w1(4, 1);
	Rational w2(5, 5);
	Rational w3 = w1 - w2;
	std::cout << "Разность пар " << w1 << " и " << w2 << " равно " << "\n";
	std::cout << w3 << "\n";
	Rational e1(8, 1);
	Rational e2(3, 4);
	std::cout << "Сумма пар " << e1 << " и " << e2 << " равно " << "\n";
	Rational e3 = e1 + e2;
	std::cout << e3 << "\n";
	Rational r1(9, 0);
	Rational r2(3, 3);
	std::cout << "Частное пар " << r1 << " и " << r2 << " равно " << "\n";
	Pair r3 = r1 / r2;
	std::cout << r3 << "\n";
	return 0;
}