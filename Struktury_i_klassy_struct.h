#include<iostream>

float PI = 3.1415926;
using namespace std;

//Определяем структуру

struct Triangle
{
	int side1;		//стороны
	int side2;
	int side3;
	int corner1;	//углы
	int corner2;
	int corner3;
};
//Функция создани структуры с вводом данных с клавиатуры

Triangle* read()
{
	int s1;
	int s2;
	int s3;
	int cor1;
	int cor2;
	int cor3;
	cout <<endl<< "Введите сторону 1: ";
	cin >> s1;
	cout << endl << "Введите сторону 2: ";
	cin >> s2;
	cout << endl << "Введите сторону 3: ";
	cin >> s3;
	cout << endl << "Введите угол 1: ";
	cin >> cor1;
	cout << endl << "Введите угол 2: ";
	cin >> cor2;
	cout << endl << "Введите угол 3: ";
	cin >> cor3;
	Triangle* triag = new Triangle;
	triag->side1 = s1;
	triag->side2 = s2;
	triag->side3 = s3;
	triag->corner1 = cor1;
	triag->corner2 = cor2;
	triag->corner3 = cor3;
	return triag;
}

//Функция вывода стурктуры

void display(Triangle* triag)
{
	cout << endl << "Сторона 1 = "<<triag->side1;
	cout << endl << "Сторона 2 = " << triag->side2;
	cout << endl << "Сторона 3 = " << triag->side3;
	cout << endl << "Угол 1 = " << triag->corner1;
	cout << endl << "Угол 2 = " << triag->corner2;
	cout << endl << "Угол 3 = " << triag->corner3;
}

//Функции изменения значения сторон

void change_side1(Triangle* triag, int size)
{
	triag->side1 = size;
}

void change_side2(Triangle* triag, int size)
{
	triag->side2 = size;
}

void change_side3(Triangle* triag, int size)
{
	triag->side3 = size;
}

//Функции изменения значения углов

void change_corner1(Triangle* triag, int cor)
{
	triag->corner1 = cor;
}

void change_corner2(Triangle* triag, int cor)
{
	triag->corner2 = cor;
}

void change_corner3(Triangle* triag, int cor)
{
	triag->corner3 = cor;
}

//Функции получения значения сторон

int get_side1(Triangle* triag)
{
	return triag->side1;
}

int get_side2(Triangle* triag)
{
	return triag->side2;
}

int get_side3(Triangle* triag)
{
	return triag->side3;
}

//Функции получения значений углов

int get_corner1(Triangle* triag)
{
	return triag->corner1;
}

int get_corner2(Triangle* triag)
{
	return triag->corner2;
}

int get_corner3(Triangle* triag)
{
	return triag->corner3;
}

//Функция получения площади

float get_square(Triangle* triag)
{
	float square = 0;
	square= 0.5 * triag->side1 * triag->side2 * sin(triag->corner1 * PI / 180);
	return square;
}

//Функция получения периметра

int get_perimeter(Triangle* triag)
{
	int perim = 0;
	perim = triag->side1 + triag->side2 + triag->side3;
	return perim;
}

//Функция получения высот

float get_high(Triangle* triag, int number_of_side) // номер стороны, высоту к которой надо посчитать
{
	int high = 0;
	if (number_of_side == 1)
	{
		high = triag->side2 * sin(triag->corner1 * PI / 180);
		return high;
	}
	if (number_of_side == 2)
	{
		high = triag->side1 * sin(triag->corner1 * PI / 180);
		return high;
	}
	high = triag->side1 * sin(triag->corner3 * PI / 180);
	return high;
}

// Функция определения типа треугольника
void get_type(Triangle* triag)
{
	if (((triag->side1 == triag->side2) || (triag->side2 == triag->side3) || (triag->side1 == triag->side3)) && (!(triag->side1 == triag->side2 == triag->side3)))
	{
		cout << "Треугольник - равнобедренный" << endl;
	}
	if (triag->side1 == triag->side2 == triag->side3)
	{
		cout << "Треугольник - равносторонний" << endl;
	}
	if ((triag->corner1 = 90) || (triag->corner2 == 90) || (triag->corner3 == 90))
	{
		cout << "Треугольник -  прямоугольный" << endl;
	}
}