#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        // 0,0,1,0,0
        // -1,-1,1,-1,-1

        unordered_map<int, int> mp;
        int sm = 0;
        int len = INT_MIN;
        mp[0] = -1;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == 0)
            {
                sm = sm + -1;
            }
            else
            {
                sm = sm + 1;
            }

            if (mp.find(sm) != mp.end())
            {
                len = max(len, i - mp[sm]);
            }
            else
            {
                mp[sm] = i;
            }
        }
        return len == INT_MIN ? 0 : len;
    }
};
