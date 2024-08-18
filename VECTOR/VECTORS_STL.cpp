#include <iostream>
#include <vector>
using namespace std;
int main()
{

    // vector<int> b(5, 10); // 10 10 10 10 10
    // vector<int> d{1, 2, 3, 10, 14};
    // vector<int> c(b.begin(), b.end());

    // for (int i = 0; i < b.size(); i++)
    // {
    //     cout << b[i] << " ";
    // }

    // for (int i = 0; i < c.size(); i++)
    // {
    //     cout << c[i] << " ";
    // }

    //     for (int x : d)
    //     { // here we can use auto in place of int
    //         cout << x << " ";
    //     }

    //     cout << endl;

    // vector<int> v;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int num;
    //     cin >> num;
    //     v.push_back(num);
    // }
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // cout << "size " << v.size() << endl;         // 5
    // cout << "capacity " << v.capacity() << endl; // 8
    // cout << "max size " << v.max_size() << endl;

    // vector<int> d{1, 2, 3, 10, 14};
    // cout << "capacity of d " << d.capacity() << endl; // 5
    // cout << "max size of d " << d.max_size() << endl; // same as vector v

    // vector<int> d{1, 2, 10, 8, 12};
    // d.push_back(16);
    // d.push_back(14);

    // for (auto x : d)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // d.pop_back();

    // for (auto x : d)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // d.insert(d.begin() + 3, 71);
    // for (auto x : d)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // d.insert(d.begin() + 3, 5, 71);
    // for (auto x : d)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // erase some elements in middle
    // d.erase(d.begin() + 3);
    // for (auto x : d)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // d.erase(d.begin() + 2, d.begin() + 4);
    // for (auto x : d)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // d.resize(18);
    // cout << d.capacity() << endl;

    // // remove all vectors
    // // d.clear();

    // if (d.empty())
    // {
    //     cout << "this is empty vector" << endl;
    // }
    // else
    // {
    //     cout << "this is not empty vector" << endl;
    // }

    // cout << d.front() << endl;   //1
    // cout << d.back() << endl;    //0 -->because we resize the vector above ,otherwise it will give 14

    // reverse function is used to avoid doubling in memory
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        cout << "changing capacity " << v.capacity() << endl;
    }
    cout << "final capacity" << v.capacity() << endl;

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
