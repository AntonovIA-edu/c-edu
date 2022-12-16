#include <iostream>
#include <algorithm>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

int root_of_equation(const int& a, const int& b, const int& c ) 
{
    return ((((b * (-1)) / 2) + sqrt(b*b-4*a*c))/2*a);
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

    if(root_of_equation(a, b, c)!=0)
        cout << "Корень квадратного уравения = "<< root_of_equation(a, b, c) << endl;
    else
        cout << "Корень квадратного уравнения равен 0!" << endl;
}