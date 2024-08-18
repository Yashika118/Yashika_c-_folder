#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void combinationsum(vector<int> &candidates, int i, int target, vector<int> v)
    {
        // base case
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (target < 0)
        {
            return;
        }
        if (i == candidates.size())
        {
            // if (target == 0)
            // {
            //     ans.push_back(v);
            // }
            return;
        }

        combinationsum(candidates, i + 1, target, v);
        // if (arr[i] <= target)
        // {
        v.push_back(candidates[i]);
        combinationsum(candidates, i, target - candidates[i], v);
        v.pop_back();
        // }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        combinationsum(candidates, 0, target, v);
        return ans;
    }
};