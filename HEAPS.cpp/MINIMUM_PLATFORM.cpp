#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i], dep[i]});
        }

        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                pq.push(v[i].second);
            }
            else
            {
                if (pq.top() < v[i].first)
                {
                    pq.pop();
                }
                pq.push(v[i].second);
            }
        }

        return pq.size();
    }
};