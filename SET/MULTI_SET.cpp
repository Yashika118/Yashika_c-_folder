#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // s.erase(3); // -->erase all duplicates
    // for (auto i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    s.erase(s.find(3)); // -->erase 1st occurence
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
}