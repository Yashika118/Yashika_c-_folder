// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     int furthestBuilding(vector<int> &heights, int bricks, int ladders)
//     {

//         priority_queue<int, vector<int>, greater<int>> pq;
//         int i = 0;
//         for (; i < heights.size() - 1; i++)
//         {
//             int diff = heights[i] - heights[i + 1];
//             if (diff >= 0)
//                 continue;
//             pq.push(abs(diff)); // ladder
//             if (pq.size() > ladders)
//             {
//                 if (bricks < pq.top())
//                     return i;
//                 bricks -= pq.top();
//                 pq.pop();
//             }
//         }
//         return i;
//     }
// };