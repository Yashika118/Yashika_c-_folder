#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int total;
    bool solve(vector<int> &nums, int i, int sum, vector<vector<int>> &dp)
    {
        if (i == nums.size())
        {
            return sum == (total - sum);
        }

        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        bool op1 = solve(nums, i + 1, sum + nums[i], dp);
        bool op2 = solve(nums, i + 1, sum, dp);

        return dp[i][sum] = (op1 | op2);
    }
    bool canpartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // int dp[n+1][sum+1];
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        total = sum;
        if (sum & 1)
        {
            return false;
        }
        return solve(nums, 0, 0, dp);
    }
};