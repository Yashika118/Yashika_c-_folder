#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int i = 0;
        int j = costs.size() - 1;
        long long tot_cost = 0;

        while (k--)
        {

            while (pq1.size() < candidates and i <= j)
            {
                pq1.push(costs[i++]);
                // i++;
            }

            while (pq2.size() < candidates and j >= i)
            {
                pq2.push(costs[j--]);
                // j--;
            }

            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if (a <= b)
            {
                tot_cost += a;
                pq1.pop();
            }
            else
            {
                tot_cost += b;
                pq2.pop();
            }
        }

        return tot_cost;
    }
};