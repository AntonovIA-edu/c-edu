#include <iostream>
using namespace std;


class Products		// определяем класс
{
private:
	float first;		//цена товара
	int second;			//стоимость товара

	// определяем конструктор

public:
	//КОНСТРУКТОР ИНИЦИАЛИЗАЦИИ
	Products (float cost, int num)
	{
		Products *prod=0;
		if (cost <= 0)
		{
			cout << "Сумма не может быть отрицательной или равной 0!" << endl;
		}
		if (num < 0)
		{
			cout << "Количество товаров не может быть отрицательным!" << endl;
		}
		cout << "Данные корректны. Элемент класса создан"<<endl;
		first = cost;
		second = num;
	}
	//Операция ввода значений структуры с клавиатуры
	Products read(Products prod)
	{
		float cost = 0;
		float num = 0;
		cout << "Введите стоимость товара cost: ";
		cin >> cost;
		cout <<endl<< "Введите количество товара num: ";
		cin >> num;
		while (cost <= 0)
		{
			cout << "Сумма не может быть отрицательной или равной 0! Введите другое значение!" << endl;
			cin >> cost;
		}
		while (num < 0)
		{
			cout << "Количество товаров не может быть отрицательным! Введите другое значение!" << endl;
			cin >> num;
		}
		first = cost;
		second = num;
		return  prod;
	}
	//Операция вывода структуры на экран
	void display(Products prod)
	{
		cout << "Стоимость товара: " << prod.first << endl;
		cout << "Количество товаров: " << prod.second << endl;
	}
	//Операция получения стоимости товаров
	void cost(Products prod)
	{
		float sum = 0;
		sum = prod.first * prod.second;
		cout << "Стоимость всего товара: " << sum << endl;
	}
};
