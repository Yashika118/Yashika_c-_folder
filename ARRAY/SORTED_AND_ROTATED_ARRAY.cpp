// 1ST APPROACH --> BRUT FORCE
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checksame(vector<int> nums, vector<int> v)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != v[i])
            {
                return false;
            }
        }
        return true;
    }
    bool check(vector<int> &nums)
    {
        vector<int> mynums;
        for (auto x : nums)
        {
            mynums.push_back(x);
        }
        sort(mynums.begin(), mynums.end());

        vector<int> v;
        for (auto i : mynums)
        {
            v.push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (checksame(nums, v))
            {
                return true;
            }
            else
            {
                int val = v[0];
                vector<int>::iterator it;
                it = v.begin();
                v.erase(it);
                v.push_back(val);
            }
        }
        return false;
    }
};

// // 2ND -->
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int min=INT_MAX; int ind=0;
//         for(int i=nums.size()-1;i>=0;i--){
//            if(nums[i]<min){
//                min=nums[i];
//                ind=i;
//            }
//         }
//         while(1){
//             if(ind ==0){
//                 break;
//             }
//            if(nums[ind-1]==nums[ind]){
//                ind--;
//            }
//            else{
//                break;
//            }
//         }

//         int n=nums.size()-1;
//         for(int i=ind;n--;i++){
//             // cout<<i%nums.size()<<" "<<(i+1)%nums.size()<<endl;
//             if(nums[i%nums.size()]>nums[(i+1)%nums.size()]){
//                 return false;
//             }

//         }

//         return true;
//     }
// };

// // 3RD APPROACH
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n=nums.size(); int problem=0;
//         for(int i=0;n--;i++){
//             if(nums[i%nums.size()]>nums[(i+1)%nums.size()]){
//                 problem++;
//                 if(problem>1){
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };