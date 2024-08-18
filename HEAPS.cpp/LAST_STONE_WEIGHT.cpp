#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        priority_queue<int> pq; // decreasing order
        for (auto x : stones)
        {
            pq.push(x);
        }
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a - b != 0)
            {
                pq.push(a - b);
            }
        }

        return pq.size() > 0 ? pq.top() : 0;
    }
};