#include <bits/stdc++.h>
using namespace std;

bool printsubsequenceofsumk(int arr[], int n, list<int> l, int k, int i, int sum)
{
    // base case
    if (i == n)
    {
        if (sum == k)
        {
            for (list<int>::iterator it = l.begin(); it != l.end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
            return true;
        }
        else
        {

            return false;
        }
    }

    // recursive case
    l.push_back(arr[i]);
    sum += arr[i];
    if (printsubsequenceofsumk(arr, n, l, k, i + 1, sum) == true)
    {
        return true;
    }

    sum -= arr[i];
    l.pop_back();
    if (printsubsequenceofsumk(arr, n, l, k, i + 1, sum) == true)
    {
        return true;
    }

    return false;
}
int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    list<int> l;
    int k;
    cin >> k;

    printsubsequenceofsumk(arr, n, l, k, 0, 0);
}