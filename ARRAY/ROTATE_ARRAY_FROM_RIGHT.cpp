// BRUTE FORCE SOL  -->TC: O(K)+O(N-K)+O(K)=O(N-K)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        if (nums.size() == 1 || k == 0)
        {
            return;
        }
        int temp[k];
        for (int i = n - k; i < n; i++)
        {
            temp[(n - k - i) * (-1)] = nums[i];
        }
        for (int j = n - k - 1; j >= 0; j--)
        {
            nums[j + k] = nums[j];
        }
        for (int m = 0; m < k; m++)
        {
            nums[m] = temp[m];
        }
    }
};
