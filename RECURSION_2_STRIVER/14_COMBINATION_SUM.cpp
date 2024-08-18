#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findComb(int ind,int target,vector<int>&v,vector<vector<int>>&ans,vector<int>candidates,int n){
        if(ind==n){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        if(target>=candidates[ind]){
            v.push_back(candidates[ind]);
            findComb(ind,target-candidates[ind],v,ans,candidates,n);
            v.pop_back();
        }
        findComb(ind+1,target,v,ans,candidates,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>v;
        vector<vector<int>>ans;
        findComb(0,target,v,ans,candidates,n);
        return ans;
    }
    //TC: (2^t * K)
    //SC: UNPREDICTABLE  --> K*x
};