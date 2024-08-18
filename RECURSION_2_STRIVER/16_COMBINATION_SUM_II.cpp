// #include<istream>/stdc++.h>
// using namespace std; 
// class Solution {
// public:
//     void func(int ind,int target,vector<int>&v,vector<vector<int>>&ans,vector<int>candidates,int n){
//         if(ind==n){
//             if(target==0){
//                 ans.push_back(v);
//             }
//             return;
//         }

//         if(target>=candidates[ind]){
//             v.push_back(candidates[ind]);
//             func(ind+1,target-candidates[ind],v,ans,candidates,n);
//             v.pop_back();
//         }
//         func(ind+1,target,v,ans,candidates,n);

//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         int n=candidates.size();
//         sort(candidates.begin(),candidates.end());
//         // set<int>st(candidates.begin(),candidates.end());
//         // candidates.assign(st.begin(),st.end());

//         vector<vector<int>>ans;
//         vector<vector<int>>result;
//         vector<int>v;
//         func(0,target,v,ans,candidates,n);

//         set<vector<int>>st(ans.begin(),ans.end());
//         result.assign(st.begin(),st.end());
//         return result;
//     }
// TC: TIME LIMIT EXCEEDED BEACUSE OF REPEATED COMBINATIONS
// };



// BETTER SOLUTION IS THIS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int ind,int target,vector<int>&v,vector<vector<int>>&ans,vector<int>&candidates,int n){

        if(target==0){
            ans.push_back(v);
            return;
        }
        if(ind==n) return;
        
        for(int i=ind;i<n;i++){
            if(i>ind and candidates[i]==candidates[i-1]) continue;
            // if(candidates[i]>target) break;
            if(target>=candidates[i]){
                v.push_back(candidates[i]);
                func(i+1,target-candidates[i],v,ans,candidates,n);
                v.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());

        vector<vector<int>>ans;
        vector<int>v;
        
        func(0,target,v,ans,candidates,n);

        return ans;
    }
    //TC: 2^N * K
    //SC: K*x
};  