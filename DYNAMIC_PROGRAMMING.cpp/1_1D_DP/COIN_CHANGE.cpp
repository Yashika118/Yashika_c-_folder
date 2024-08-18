#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int amt = coins[i]; amt <= amount; amt++)
            {
                dp[amt] = dp[amt] + dp[amt - coins[i]];
            }
        }
        return dp[amount];
    }
};