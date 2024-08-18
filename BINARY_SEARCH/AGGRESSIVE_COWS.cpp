// LS-58
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &stalls, int dis, int cows)
    {
        int placed_cow = 1;
        int last_cow_placed = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last_cow_placed >= dis)
            {
                placed_cow++;
                last_cow_placed = stalls[i];
            }
        }

        if (placed_cow >= cows)
        {
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls.back() - stalls[0];
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2; // itna distance place krna chah rhe h kya cow place ho skti h ya nhi

            if (check(stalls, mid, k) == true)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};