#include <iostream>
#include "Структуры_и_классы_struct.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int s1 = 2;
	int s2 = 2;
	int s3 = 10;
	int cor1 = 90;
	int cor2 = 45;
	int cor3 = 45;
	Triangle* triang=  new Triangle;
	triang->side1 = s1;
	triang->side2 = s2;
	triang->side3 = s3;
	triang->corner1 = cor1;
	triang->corner2 = cor2;
	triang->corner3 = cor3;

	//Задаем значение сторон и получаем их значения
	change_side1(triang,s1);
	cout << "Сторона 1 = " << get_side1(triang) << endl;

	change_side2(triang, s2);
	cout << "Сторона 2 = " << get_side2(triang) << endl;

	change_side3(triang, s3);
	cout << "Сторона 3 = " << get_side3(triang) << endl;

	//Задаем и получаем значения углов
	change_corner1(triang, cor1);
	cout << "Угол между 1 и 2 стороной = " << get_corner1(triang) << endl;

	change_corner2(triang, cor2);
	cout << "Угол между 2 и 3 стороной = " << get_corner2(triang) << endl;

	change_corner3(triang, cor3);
	cout << "Угол между 1 и 3 стороной = " << get_corner3(triang) << endl << endl;

	//Выводим параметры треугольника через функцию
	display(triang);

	//Создадим новую структуру
	Triangle* triang2 = new Triangle;
	triang2 = read();
	display(triang2);
	
	//Находим площадь треугольника

	cout <<endl<<endl<< "Площадь треугольника = " << get_square(triang) << endl;

	//Находим периметр треугольника

	cout << "Периметр треугольника = " << get_perimeter(triang) << endl;

	//Находим высоты треугольника

	cout << "Высота к 1-ой стороне = " << get_high(triang, 1) << endl;
	cout << "Высота к 2-ой стороне = " << get_high(triang, 2) << endl;
	cout << "Высота к 3-ой стороне = " << get_high(triang, 3) << endl << endl;

	//Определяем тип треугольника

	get_type(triang);
}