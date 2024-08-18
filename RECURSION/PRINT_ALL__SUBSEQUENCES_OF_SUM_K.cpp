#include <bits/stdc++.h>
using namespace std;
void printsubsequenceofsumk(int arr[], int n, list<int> l, int k, int i, int sum)
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
        }
        return;
    }

    // recursive case
    l.push_back(arr[i]);
    sum += arr[i];
    printsubsequenceofsumk(arr, n, l, k, i + 1, sum);

    sum -= arr[i];
    l.pop_back();
    printsubsequenceofsumk(arr, n, l, k, i + 1, sum);
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