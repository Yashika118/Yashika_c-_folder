#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int ind,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[ind]);
        func(ind+1,nums,v,ans);
        v.pop_back();
        func(ind+1,nums,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;

        func(0,nums,v,ans);
        return ans;
    }
};