#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    // set<int, greater<int>> s; // using custom comparator--> print set in descending order
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);

    // print elements in set
    // for (auto i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // // print in reverse
    // for (auto i = s.rbegin(); i != s.rend(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;
    // cout << s.size() << endl;

    // cout << *s.lower_bound(2) << endl;
    // cout << *s.lower_bound(3) << endl;
    // cout << *s.upper_bound(3) << endl;
    // cout << (s.upper_bound(5) == s.end()) << endl;
    // cout << *s.upper_bound(6) << endl;

    // erase
    s.erase(3);
    s.erase(s.begin());
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // set<pair<int,int>>st;
    // while(!s.empty()){
    //         auto it=*(s.begin());
    //         // st.begin() --> address of starting value
    //         // * --> it is the value at that address
    //         int node=it.second;
    //         int dis=it.first;
    //     }
}