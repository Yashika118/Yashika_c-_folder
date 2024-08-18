// BRUTE FORCE SOLTUION
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // TC-->N*LOG(N)+N
    int removeDuplicates(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int index = 0;
        for (auto it : s)
        {
            nums[index] = it;
            index++;
        }
        return s.size();
    }
};

// OPTIMAL SOLTUION  --> TWO POINTERS APPROACH -->TC: O(N)
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i=0;
//         for(int j=1;j<nums.size();j++){
//             if(nums[i]!=nums[j]){
//                 nums[i+1]=nums[j];
//                 i++;
//             }
//         }
//         return i+1;
//     }
// };