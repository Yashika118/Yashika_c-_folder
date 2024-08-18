#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int ind,vector<int>&v,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        func(ind+1,v,ans,nums);
        v.pop_back();
        func(ind+1,v,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        vector<vector<int>>ans;
        vector<vector<int>>result;
        func(0,v,ans,nums);
        set<vector<int>>st(ans.begin(),ans.end());
        result.assign(st.begin(),st.end());

        return result;
    }
};