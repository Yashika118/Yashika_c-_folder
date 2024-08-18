#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void func(int ind,int sum,vector<int>&ans,vector<int>arr,int n){
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        
        func(ind+1,sum+arr[ind],ans,arr,n);
        func(ind+1,sum,ans,arr,n);
        
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ans;
        func(0,0,ans,arr,n);
        return ans;
    }
};