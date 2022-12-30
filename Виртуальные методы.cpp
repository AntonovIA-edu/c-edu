#include <iostream>

using namespace std;

//класс десятичных чисел

class Decimal
{
private:
    //Виртуальный метод записи числа

    virtual void transform(const string& value,const int signn) {
        size = value.length();
        int step = size - 1;
        int string_size = 0;
        if (signn == 0)
            sign = -1;
        else
            sign = 1;
        for (int i = 0; i < SIZE; i++) {    //цикл по всему массиву
            if (i >= SIZE - size) {
                val[i] = value[string_size];
                int number = val[i]-48;        //запоминаем цифру
                total_sum += number * pow(10, step);    //умножаем цифру на 10 в степени ее позиции
                step--;         //уменьшаем число позиций на 1
                string_size++;  //прочитанный string +1
            }
            else {
                val[i] = '0';
            }
        }
    }

    //Виртуальный метод вывода числа

    virtual void display() {
        cout << "Десятичное  число:" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << val[i]; 
        }
        cout << "\n\n";
    }


public:
    enum { SIZE = 100 };        //максимальный размер числа

    unsigned char val[SIZE];    //размер 
    unsigned int size = 0;
    int sign=0;                 //знак
    int total_sum = 0;

    Decimal() {}        //констркутор инициализации

    void init(const string& value, int signn)        //считывание и запись в массив типа unsigned char 
    {
        transform(value, signn);
    }


    void info() {
        display();
    }


    Decimal operator + (const Decimal& other) {
        Decimal b = *this;
        b.total_sum += other.total_sum;
        int level = 0;
        bool flag = true;
        while (flag) {
            if (pow(10, level) > b.total_sum) {
                flag = false;
            }
            else {
                level++;
            }
        }
        b.size = level;
        level--;
        int fake_summ = b.total_sum;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - b.size) {
                b.val[i] = (int)(fake_summ / pow(10, level)) + '0';
                fake_summ -= (int)(fake_summ / pow(10, level)) * pow(10, level);
                level--;
            }
            else {
                val[i] = '0';
            }
        }
        return b;
    }

};

class BiteString :
    public Decimal {

private:
    void display() {
        cout << "\n\nДвоичное число" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << val[i];
        }
        cout << "\n\n";
    }
    void transform(const string& value)  
    {
        size = value.length();
        int step = size - 1;
        int string_size = 0;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - size) {
                val[i] = value[string_size];
                int number;
                number = value[string_size] - '0';
                total_sum += number * pow(2, step);
                step--;
                string_size++;
            }
            else {
                val[i] = '0';
            }
        }
    }

public:
    BiteString operator + (const BiteString& other) {
        BiteString b = *this;
        b.total_sum += other.total_sum;
        int level = 0;
        bool flag = true;
        while (flag) {
            if (pow(10, level) > b.total_sum) {
                flag = false;
            }
            else {
                level++;
            }
        }
        b.size = level;
        level--;
        int fake_summ = b.total_sum;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - b.size) {
                b.val[i] = (int)(fake_summ / pow(10, level)) + '0';
                fake_summ -= (int)(fake_summ / pow(10, level)) * pow(10, level);
                level--;
            }
            else {
                val[i] = '0';
            }
        }
        return b;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    //Для десятичного числа

    Decimal a, b;
    a.init("14",1);
    b.init("101",1);
    a.info();
    b.info();
    Decimal c = (a + b);
    cout << "\n\nРезультаты суммирования:\n\n";
    c.info();
    cout << "total_sum = " << c.total_sum << "\t size = " << c.size << endl;

    //Для двоичного числа

    BiteString d, e;
    d.init("100",1);
    e.init("1",1);
    d.info();
    e.info();
    BiteString f = (d + e);
    cout << "\n\nРезультаты суммирования:\n\n";
    f.info();
    cout << "total_sum = " << f.total_sum << "\t size = " << f.size << endl;

    return 0;
}