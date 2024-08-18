#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<int> v;
    v.push_back(5);
    v.push_back(15);
    v.push_back(35);
    v.push_back(40);
    v.push_back(60);
    v.push_back(70);

    cout << "size of vector :" << v.size() << endl;
    cout << "max size of vector :" << v.max_size() << endl;
    cout << "capacity of vector :" << v.capacity() << endl;

    if (v.empty())
    {
        cout << "vector is empty" << endl;
    }
    else
    {
        cout << "vector is not empty" << endl;
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    cout << "vector is ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    v.insert(v.begin(), 29);
    cout << "vector is ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    v.insert(v.begin() + 4, 68);
    cout << "vector elements are : ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "vector elements are : ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}