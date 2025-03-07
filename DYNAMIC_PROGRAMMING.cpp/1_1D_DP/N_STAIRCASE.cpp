#include <bits/stdc++.h>
using namespace std;
int nstaircase(int n, int k)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    // recursive case
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += nstaircase(n - i, k);
    }
    return ans;
}

// top down
int tdnstaircase(int n, int k, int *arr)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[n] = 1;
    }
    if (arr[n] != 0)
    {
        return arr[n];
    }

    // recursive case
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += tdnstaircase(n - i, k, arr);
    }
    return arr[n] = ans;
}
// bottom up
int bottomup(int n, int k)
{
    int arr[100];
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= k; j++)
        {
            // if(i>=j)
            if (i - j >= 0)
            {
                ans += arr[i - j];
            }
        }
        arr[i] = ans;
    }
    return arr[n];
}
int main()
{
    int n, k; // n->steps, k->jumps
    cin >> n >> k;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    cout << tdnstaircase(n, k, arr) << endl;

    cout << bottomup(n, k) << endl;

    cout << nstaircase(n, k) << endl;
}