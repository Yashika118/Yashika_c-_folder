#include <bits/stdc++.h>
using namespace std;
// recursive sol
int fibo(int pos)
{
    // base case
    if (pos == 0 || pos == 1)
    {
        return pos;
    }

    // recursive case
    return fibo(pos - 1) + fibo(pos - 2);
}

// top down approach
int topdownfibo(int pos, int *dp)
{
    // base case
    if (pos == 0 || pos == 1)
    {
        return dp[pos] = pos;
    }

    // calculate krne se pehle check already calculated toh nhi hai
    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    // recursive case
    return dp[pos] = topdownfibo(pos - 1, dp) + topdownfibo(pos - 2, dp);
}

int bottomupfibo(int pos)
{
    int *dp = new int[pos + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= pos; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[pos];
}

int main()
{
    int n;
    cin >> n;

    // cout << "simple recursion: " << endl;
    // cout << fibo(n) << endl;

    // int arr[n+1]-->aesa nhi kr skte isliye dynamically arr bnaenge

    // int *arr = new int[n + 1];
    int *dp = new int[n + 1]; // arr is replace by dp, dp is arr

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1; // -1 reperesent abhi tk uss index ka ans nhi aaya hai
    }
    // memset(dp, -1, sizeof(dp)); // to initialise arr with some value

    cout << "top down fibo : " << endl;
    cout << topdownfibo(n, dp) << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    cout << "bottom up fibo : " << endl;
    cout << bottomupfibo(n) << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    cout << "simple recursion: " << endl;
    cout << fibo(n) << endl;

    return 0;
}
