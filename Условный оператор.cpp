#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a;
    int b;
    int c;
    int count = 0;
    cout << "Введите а: " << endl;
    cin >> a;
    cout << "Введите b: " << endl;
    cin >> b;
    cout << "Введите c: "<<endl;
    cin >> c;
    if (a > 0)
        count++;
    if (b > 0)
        count++;
    if(c>0)
        count++;
    cout << "Кол-во положительных: " << count;
}
