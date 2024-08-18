// CAR SORTING PROBLEM

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool compare(pair<int, int> p1, pair<int, int> p2)
// {
//     int d1 = p1.first * p1.first + p1.second * p1.second;
//     int d2 = p2.first * p2.first + p2.second * p2.second;

//     if (d1 == d2)
//     {
//         return p1.first < p2.first;
//     }
//     return d1 < d2;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> v;

//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         v.push_back(make_pair(x, y));
//     }
//     sort(v.begin(), v.end(), compare);

//     for (auto p : v)
//     {
//         cout << "Car "
//              << "(" << p.first << " " << p.second << ")" << endl;
//     }
// }

// 2ND APPROACH
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class car
{
public:
    string car_name;
    int x;
    int y;

    car(string n, int a, int b)
    {
        car_name = n;
        x = a;
        y = b;
    }
    int distance()
    {
        return x * x + y * y;
    }
};
bool compare(car A, car B) // A & B are objects of class
{
    int da = A.distance();
    int db = B.distance();

    if (da == db)
    {
        return A.car_name.length() < B.car_name.length();
    }
    return da < db;
}
int main()
{
    int n;
    cin >> n;
    vector<car> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        string name;

        cin >> name >> x >> y;
        car temp(name, x, y);
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);
    int a, b;

    for (auto c : v)
    {
        cout << "Car " << c.car_name << " Distance " << c.distance() << " "
             << "location " << c.x << " " << c.y << endl;
    }
}
