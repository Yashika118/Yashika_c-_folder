// LS-60
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
            vp.push_back({start[i], end[i]});
        }
        sort(vp.begin(), vp.end(), cmp);

        int last_start = vp.back().first;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int curr_start = vp[i].first;
            int curr_end = vp[i].second;

            if (curr_end < last_start)
            {
                ans += 1;
                last_start = curr_start;
            }
            else
            {
                last_start = max(last_start, curr_start);
            }
        }
        return ans;
    }
};