#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	int A;
	int B;
	cout << "Введите число А: ";
	cin >> A;
	cout <<endl<< "Введите число B: ";
	cin >> B;
	cout << "Логическое высказывание = " << ((A >= 0) || (B < -2));
}