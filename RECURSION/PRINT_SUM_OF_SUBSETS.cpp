#include <bits/stdc++.h>
using namespace std;
void subsetssum(int arr[], int n, int i, int sum, vector<int> &v)
{
    // base case
    if (i == n)
    {
        v.push_back(sum);
        return;
    }
    // recursive case
    // when pick
    subsetssum(arr, n, i + 1, sum + arr[i], v);
    // when not pick
    subsetssum(arr, n, i + 1, sum, v);
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    vector<int> v;
    subsetssum(arr, n, 0, 0, v);
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }
}