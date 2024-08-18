// LS-63
#include <bits/stdc++.h>
using namespace std;
int func(string s, int i, int j, vector<vector<int>> dp)
{
    // base case
    if (i > j)
    {
        return 0;
    }

    if (i == j)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // recursive case
    if (s[i] == s[j])
    {
        return dp[i][j] = 2 + func(s, i + 1, j - 1, dp);
    }
    return dp[i][j] = max(func(s, i + 1, j, dp), func(s, i, j - 1, dp));
}
int main()
{
    string s = "bbbab";
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
    cout << func(s, 0, s.length() - 1, dp);
}