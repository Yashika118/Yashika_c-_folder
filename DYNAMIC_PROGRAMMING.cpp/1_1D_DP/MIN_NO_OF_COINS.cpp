// LS-59
#include <bits/stdc++.h>
using namespace std;
int mincoinsneeded(int coins[], int amount, int n) // rec wala solution
{
    // base case
    if (amount == 0)
    {
        return 0;
    }
    // recursive case
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int rem_amt = amount - coins[i];
        if (rem_amt >= 0)
        {
            int rem_coins_ans = mincoinsneeded(coins, rem_amt, n);
            if (rem_coins_ans < ans)
            {
                ans = rem_coins_ans + 1;
            }
        }
    }
    return ans;
}
// top down
int topdownmincoinsneeded(int coins[], int amount, int n, int *arr) // dp wala sol
{
    // base case
    if (amount == 0)
    {
        return arr[amount] = 0;
    }

    // calculate krne se pehle check
    if (arr[amount] != -1)
    {
        return arr[amount];
    }

    // recursive case
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {

        int rem_amt = amount - coins[i];
        if (rem_amt >= 0)
        {
            int rem_coins_ans = topdownmincoinsneeded(coins, rem_amt, n, arr);
            if (rem_coins_ans < ans)
            {
                ans = rem_coins_ans + 1;
            }
        }
    }
    return arr[amount] = ans;
}

// bottom up
int bottomup(int *coins, int amount, int n)
{
    int *arr = new int[amount + 1];
    arr[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        arr[i] = INT_MAX;
    }
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int rem_amount = i - coins[j];
            if (rem_amount >= 0)
            {
                arr[i] = min(arr[rem_amount] + 1, arr[i]);
            }
        }
    }
    return arr[amount];
}

int main()
{
    int coins[] = {1, 7, 10, 15};
    int n = sizeof(coins) / sizeof(int);
    int amount;
    cin >> amount;

    int *arr = new int[amount + 1];
    for (int i = 0; i <= amount; ++i)
    {
        arr[i] = -1;
    }
    // top down
    cout << topdownmincoinsneeded(coins, amount, n, arr) << endl;
    // bottom up
    cout << bottomup(coins, amount, n) << endl;
    // recursion
    cout << mincoinsneeded(coins, amount, n) << endl; // ye time lega kyuki calls zyada lg rhi h
}