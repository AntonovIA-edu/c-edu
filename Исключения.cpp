#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
const char* msg;
const bool* error;

int root_of_equation_d(const int& a, const int& b, const int& c)
{
    int d = b * b - 4 * a * c;
    if (d < 0)
        throw msg = "Дискриминант меньше 0!";
    return((b * -1) + d) / (2 * a);
    
}
void equation(const int& a)
{
    
    if (a == 0)
        throw error = 0;
    
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "Введите a =  ";
    cin >> a;
    cout << "\n\nВведите b =  ";
    cin >> b;
    cout << "\n\nВведите c =  ";
    cin >> c;

    try
    {
        equation(a);
        cout<<"\n\nКорень уравнения = "<<root_of_equation_d(a, b, c)<<"\n\n";
    }
    catch (const bool* error)
    {
        cout << "\n\nОшибка! " <<  "A равно 0!" << "\n" << endl;
        cout << "Конец работы программы!\n";
        return 1;
    }
    catch (const char* msg)
    {
        cout << "\n\nОшибка! " << msg << "\n" << endl;
    }
    cout << "Конец работы программы!\n";
    return 1;
}

