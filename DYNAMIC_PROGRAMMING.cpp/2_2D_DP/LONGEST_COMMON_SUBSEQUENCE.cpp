#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int func(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i >= s1.size() or j >= s2.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // recursive case
        int op1 = 0;
        if (s1[i] == s2[i])
        {
            op1 = 1 + func(s1, s2, i + 1, j + 1, dp);
            return dp[i][j] = op1;
        }
        int op2 = max(func(s1, s2, i + 1, j, dp), func(s1, s2, i, j + 1, dp));
        return dp[i][j] = op2;
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()), -1);
        return func(text1, text2, 0, 0, dp);
    }
};