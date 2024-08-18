#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int minimumCost(vector<int> &sticks)
    {
        priority_queue<int, vector<int>, greater<int>> pq; // minheap
        for (auto x : sticks)
        {
            pq.push(x);
        }

        int sum = 0;
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum = sum + a + b;
            pq.push(a + b);
        }
        return sum;
    }
};
