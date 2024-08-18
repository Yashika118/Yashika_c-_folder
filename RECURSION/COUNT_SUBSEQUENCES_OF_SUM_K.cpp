#include <bits/stdc++.h>
using namespace std;
int printsubsequenceofsumk(int arr[], int n, int k, int i, int sum)
{
    // base case
    if (sum > k)
    {
        return 0;
    }
    if (i == n)
    {
        if (sum == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // recursive case
    sum += arr[i];
    int left = printsubsequenceofsumk(arr, n, k, i + 1, sum);

    sum -= arr[i];
    int right = printsubsequenceofsumk(arr, n, k, i + 1, sum);

    return left + right;
}
int main()
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    // list<int> l;
    int k;
    cin >> k;

    cout << printsubsequenceofsumk(arr, n, k, 0, 0);
}