#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>  
#include <algorithm>
using namespace std;

bool greater6(int value)
{
    return value>9;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int x;
    cout << "Введите Х: ";
    cin >> x;
    using namespace std;
    vector<int> v;

    for (int i = 0; i <= 15; i++)
    {
        v.push_back(i);
    }

    cout << "До замены:\n ( ";
    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << ")." << endl;

    // Replace elements satisfying the predicate greater6
    // with a value of 70
    replace_if(v.begin(), v.end(), greater6, x);

    cout << "После замены:\n ( ";
    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << ").";
}