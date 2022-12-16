#include <iostream>
#include <string>
using namespace std;

class Man		// ���������� �������, ����������� �����
{
public:
	string Name;
	int age;
	char sex;
	int weight;

	virtual bool isright_weight_and_age(int weight, int age) = 0; //����������� �������

};

class Student : public Man
{
public: int year_edu;


public:
	Student() { //����������� �� ���������
		Name = "Steve";
		weight = 50;
		age = 30;
		sex = '�';
		year_edu = 0;
	}

public:
	//����������� �������������
	Student(string N, int a, char s, int w, int year)
	{
		Name = N;
		sex = s;
		weight = w;
		age = a;
		year_edu = year;
	}


	//�������� ������ ��������� �� �����
	void display(Student person)
	{
		cout << endl << "��� -" << Name;
		cout << endl << "������� - " << age;
		cout << endl << "��� - " << sex;
		cout << endl << "��� - " << weight;
		cout << endl << "��� ��������� �������� - " << year_edu << "\n\n";
	}
	//�������� ��������� � ��������� ��������
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
	//������� ��������� ���� ��������� ��������

	void change_year(int y)
	{
		year_edu = y;
	}

	//������� ���������� ���� ��������� ��������

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

	//��������� ����������� ����� ������������ ������ - ������� �������� �������� � ����
	bool isright_weight_and_age(int weight, int age) 
	{
		if (((weight > 0) && (age > 0)) && ((weight < 150) && (age < 120)))
		{
			return true;
		}
		return false;
	}

	//������� �������� ���� �� ������������

	bool checweight(Student& person) 
	{
		if ((person.getweight() > 0) && (person.getweight() < 150))
		{
			return true;
		}
		return false;
	}

	//������� �������� �������� �� ������������

	bool checkage(Student& person)
	{
		if ((person.getage() > 0) && (person.getage() < 150))
		{
			return true;
		}
		return false;
	}

	//������� �������� ������ �������� �� ������������

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