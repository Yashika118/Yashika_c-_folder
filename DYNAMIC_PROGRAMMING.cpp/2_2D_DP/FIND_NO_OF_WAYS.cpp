// find number of ways to reach from a starting position to an ending position
// travelling in specified directions only;
#include <bits/stdc++.h>
using namespace std;
int totalways(int x, int y)
{
    // base case
    if (x == 0 and y == 0)
    {
        return 1;
    }

    // recursive case
    int ans = 0;
    // first row pe kaam kr rhe h
    for (int i = 0; i <= x - 1; i++)
    {
        ans = ans + totalways(i, y);
    }

    // first column pe kaam kr rhe h
    for (int j = 0; j <= y - 1; j++)
    {
        ans = ans + totalways(x, j);
    }

    return ans;
}

// top down
int tdtotalways(int x, int y, int dp[100][100])
{
    // base case
    if (x == 0 and y == 0)
    {
        return dp[x][y] = 1;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    // recursive case
    int ans = 0;
    // first row pe kaam kr rhe h
    for (int i = 0; i <= x - 1; i++)
    {
        ans = ans + tdtotalways(i, y, dp);
    }

    // first column pe kaam kr rhe h
    for (int j = 0; j <= y - 1; j++)
    {
        ans = ans + tdtotalways(x, j, dp);
    }

    return dp[x][y] = ans;
}

// bottom up
int bottomup(int x, int y)
{
    int arr[100][100];

    for (int i = 0; i <= x; i++)
    {

        for (int j = 0; j <= y; j++)
        {

            if (i == 0 and j == 0)
            {
                arr[i][i] = 1;
            }
            else
            {
                int ans = 0;
                // col
                for (int k = 0; k < i; k++)
                {
                    ans += arr[k][j];
                }
                // row
                for (int l = 0; l < j; l++)
                {
                    ans += arr[i][l];
                }

                arr[i][j] = ans;
            }
        }
    }

    return arr[x][y];
}

int main()
{
    int x, y;
    cin >> x >> y;

    int dp[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << tdtotalways(x, y, dp) << endl;

    cout << bottomup(x, y) << endl;

    cout << totalways(x, y) << endl;

    return 0;
}