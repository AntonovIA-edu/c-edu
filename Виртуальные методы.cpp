#include <iostream>

using namespace std;


class Decimal
{
private:
    virtual void transform(const string& value) {
        size = value.length();
        int step = size - 1;
        int string_size = 0;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - size) {
                val[i] = value[string_size];
                int number = value[string_size] - '0';
                total_sum += number * pow(8, step);
                step--;
                string_size++;
            }
            else {
                val[i] = '0';
            }
        }
    }
    virtual void display() {
        cout << "Десятичное число число!" << endl;
    }
public:
    enum { SIZE = 100 };

    unsigned char val[SIZE];
    unsigned int size = 0;
    int total_sum = 0;

    Decimal() {}
    void init(const string& value)
    {
        transform(value);
    }
    void info() {
        display();
    }

    void full() {
        for (int i = 0; i < SIZE; i++) {
            cout << val[i];
        }
        cout << endl;
    }

    Decimal operator + (const Octal& other) {
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

class Bite : public Octal {

private:
    void display() {
        cout << "Битовое число" << endl;
    }
    void transform(const string& value) override {
        size = value.length();
        int step = size - 1;
        int string_size = 0;
        for (int i = 0; i < SIZE; i++) {
            if (i >= SIZE - size) {
                val[i] = value[string_size];
                int number;
                switch (value[string_size])
                {
                case '0':
                    number = 0;
                    break;
                case '1':
                    number = 1;
                    break;
                default:
                    number = value[string_size] - '0';
                }
                total_sum += number * pow(2, step);
                step--;
                string_size++;
            }
            else {
                val[i] = '0';
            }
        }
    }
    char transform(const int& number) {
        char letter;
        switch (number)
        {
        case '0':
            number = 0;
            break;
        case '1':
            number = 1;
            break;
        default:
            letter = number + '0';
        }
        return letter;
    }
public:
    Bite operator + (const Hex& other) {
        Hex b = *this;
        b.total_sum += other.total_sum;
        int level = 0;
        bool flag = true;
        while (flag) {
            if (pow(2, level) > b.total_sum) {
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
                b.val[i] = transform((int)(fake_summ / pow(2, level)));
                fake_summ -= (int)(fake_summ / pow(2, level)) * pow(2, level);
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
    Decimal a, b;
    a.init("14");
    b.init("101");
    Decimal c = (a + b);
    c.full();
    cout << "total_sum = " << c.total_sum << "\t size = " << c.size << endl;
    Bite d, e;
    d.init("2");
    e.init("1");
    Bite f = (d + e);
    f.full();


    return 0;
}