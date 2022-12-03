#include <iostream>
#include "Структура-пара.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	float cost = 2.99;
	int num = 20;

	//Используем конструктор инициализации
	Products prod(cost, num);

	//Выводим элемент класса
	prod.display(prod);
	
	//Используем конструктор копирования
	Products prod1(prod);

	//Создаем элемент кдасса через чтение
	prod1.read(prod1);

	//Выводим элемент класса
	prod1.display(prod1);

	//Вычисляем стоимость товаров
	prod.cost(prod1);
}