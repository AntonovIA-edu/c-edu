#include <iostream>
#include <string>
using namespace std;

class Man		// определяем базовый, абстрактный класс
{
public:
	string Name;
	int age;
	char sex;
	int weight;

	virtual bool isright_weight_and_age(int weight, int age) = 0; //Виртуальная функция

};

class Student : public Man
{
public: int year_edu;


public:
	Student() { //Конструктор по умолчанию
		Name = "Steve";
		weight = 50;
		age = 30;
		sex = 'М';
		year_edu = 0;
	}

public:
	//КОНСТРУКТОР ИНИЦИАЛИЗАЦИИ
	Student(string N, int a, char s, int w, int year)
	{
		Name = N;
		sex = s;
		weight = w;
		age = a;
		year_edu = year;
	}


	//Операция вывода структуры на экран
	void display(Student person)
	{
		cout << endl << "Имя -" << Name;
		cout << endl << "Возраст - " << age;
		cout << endl << "Пол - " << sex;
		cout << endl << "Вес - " << weight;
		cout << endl << "Год окончания обучения - " << year_edu << "\n\n";
	}
	//Операции получения и изменения значений
	void set_name(string N)
	{
		Name = N;
	}
	void set_age(int a)
	{
		age = a;
	}

	void set_weight(int w)
	{
		weight = w;
	}
	//Функция изменения года окончания обучения

	void change_year(int y)
	{
		year_edu = y;
	}

	//Функция увеличения года окончания обучения

	void add_yaer(int add)
	{
		year_edu = year_edu + add;
	}
	string getName()
	{
		return Name;
	}

	int getage()
	{
		return age;
	}

	int getweight()
	{
		return weight;
	}

	char getsex()
	{
		return sex;
	}

	//Реализуем виртуальный метод абстрактного класса - функция проверки возраста и веса
	bool isright_weight_and_age(int weight, int age) 
	{
		if (((weight > 0) && (age > 0)) && ((weight < 150) && (age < 120)))
		{
			return true;
		}
		return false;
	}

	//Функция проверки веса на корректность

	bool checweight(Student& person) 
	{
		if ((person.getweight() > 0) && (person.getweight() < 150))
		{
			return true;
		}
		return false;
	}

	//Фукнция проверки возраста на корректность

	bool checkage(Student& person)
	{
		if ((person.getage() > 0) && (person.getage() < 150))
		{
			return true;
		}
		return false;
	}

	//Функция проверки данных студента на корректность

	void checkperson(Student& person) 
	{ 
		if ((checkage(person) == true) && (checweight(person) == true))
			cout << "This person's data is correct!\n";
		else 
		{
			cout << "This person's data is NOT correct!\n";
		}
	}
};