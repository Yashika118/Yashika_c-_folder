// map are used to store key:values
//    for example [2K21/EP/118: YASHIKA]
// map are of two types :
// 1. unordered map(store randomly)
//   --> hashing is used
// 2. ordered map(store in order)
//   --> tress

#include <bits/stdc++.h>
using namespace std;

// insert in map
map<int, int> insertinmap(int arr[], int n)
{
    map<int, int> mp;
    // Insert arr[i] as key and i as value
    for (int i = 0; i < n; i++)
    {
        // mp[key]=value
        mp[arr[i]] = i;
    }
    return mp;
}

void displaymap(map<int, int> mp)
{
    // print every key and value in a pair in a new line
    map<int, int>::iterator it;
    // it+1 -->invalid
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

void erasemap(map<int, int> &mp, int x)
{
    // map<int,int> :: iterator it;
    // also-->
    auto it = mp.find(x);
    if (it != mp.end())
    {
        mp.erase(it);
        cout << "erased" << x;
    }
    else
    {
        cout << "not found";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertinmap(arr, n);
}
