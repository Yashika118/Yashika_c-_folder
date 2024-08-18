// LS-63
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abcd";
    int n = s.length();
    int dp[n + 1][n + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    int ans = 0;
    for (int len = 2; len <= n; len++)
    {
        int i = 0;
        int j = len - 1;
        while (j < n)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
            ans = max(ans, dp[i][j]);
            i++;
            j++;
        }
    }
    cout << n - ans;
}