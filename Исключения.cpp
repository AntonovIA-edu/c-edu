#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
const char* msg;

int root_of_equation(const int& a, const int& b, const int& c ) 
{
    int d = b * b - 4 * a * c;
    if (d < 0)
        throw msg =  "Дискриминант меньше 0!";
    return((b * -1) + d) / (2 * a);
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int a=0;
    int b=0;
    int c=0;
    cout << "Введите a =  ";
    cin >> a;
    cout << "\n\nВведите b =  ";
    cin >> b;
    cout << "\n\nВведите c =  ";
    cin >> c;
    
    try
    {
        cout << "Корень квадратного уравения = " << root_of_equation(a, b, c) << endl;
    }
    catch(const char* msg)
    {
        cout << "Ошибка! "<<msg<<"\n" << endl;
    }
    cout << "Конец работы программы!\n";
}

