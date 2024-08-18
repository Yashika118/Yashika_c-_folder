#include <iostream>
// #include <unordered_map>
#include <map>
using namespace std;
// ordered map-->key ke according sorted o(logn)
// unordered map--> key ke according sorted nhi hota o(1)
int main()
{
    // unordered_map<string, int> h;
    map<string, int> h;
    h["Papaya"] = 1301; //-->also it can be use
    h.insert(make_pair("Apple", 1300));
    h.insert(make_pair("kiw", 2190));
    h.insert(make_pair("kiwi", 2490));
    h.insert(make_pair("mango", 8940));

    // for each loop
    for (auto x : h)
    {
        cout << x.first << " " << x.second << ", ";
        cout << endl;
    }

    // to store data like
    // key  value
    // abc  9867 4321

    // unordered_map<string, pair<int, int>> h;
    // h.insert(make_pair("abc", make_pair(9867, 4321)));

    // for (auto x : h)
    // {
    //     cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    //     ;
    // }

    return 0;
}