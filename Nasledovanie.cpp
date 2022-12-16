#include <iostream>
#include "Наследование.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	string N = "John";
	int a = 20;
	char s = 'М';
	int w = 0;
	int corr = 1;
	int year = 2025;

	//Конструктор инициализации
	Student person("John", 24, 'М', 70, 2025);

	//Вывод на экран
	person.display(person);

	//Устанваливаем новый возраст
	person.set_age(180);

	//Вывод на экран
	person.display(person);

	//Проверяем данные на корректность
	person.checkperson(person);

	return 1;
}