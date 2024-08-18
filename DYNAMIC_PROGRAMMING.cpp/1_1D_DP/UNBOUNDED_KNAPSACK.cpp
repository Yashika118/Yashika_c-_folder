#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W + 1, INT_MIN);
        dp[0] = 0;
        int ans = 0;
        for (int weight = 1; weight <= W; weight++)
        {
            for (int i = 0; i < N; i++)
            {
                if (wt[i] <= weight)
                {
                    dp[weight] = max(dp[weight], val[i] + dp[weight - wt[i]]);
                }
            }
            ans = max(ans, dp[weight]);
        }
        return ans;
    }
};