#include <bits/stdc++.h>
using namespace std;
void printvector(list<int> l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    if (l.size() == 0)
    {
        cout << "[]";
    }
    cout << endl;
}
void printsubsequences(int arr[], int n, list<int> l, int i)
{
    // base case
    if (i == n)
    {
        printvector(l);
        return;
    }
    // recursive case
    l.push_back(arr[i]);
    printsubsequences(arr, n, l, i + 1);
    l.pop_back();
    printsubsequences(arr, n, l, i + 1);
}
int main()
{
    int arr[] = {0, 1, 2, 2};
    int n = sizeof(arr) / sizeof(int);
    list<int> l;

    printsubsequences(arr, n, l, 0);
}