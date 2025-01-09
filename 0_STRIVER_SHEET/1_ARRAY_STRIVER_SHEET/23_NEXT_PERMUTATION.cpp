#include<bits/stdc++.h>
using namespace std;

// PERMUTATION --> NO. OF WAYS = n!

// BRUTE FORCE
// 1. GENERATE ALL POSSIBLE WAYS IN SORTED ORDER
// 2. LINEAR SEARCH
// 3. NEXT INDEX
// NO NEED TO SOLVE THE QUES IN FRONT OF INTERVIEWER BUT EXPLAIN YOUR APPORACH
class Solution {
public:
    void allPermute(vector<int>&nums,vector<int>v,set<vector<int>>&ans,vector<int>&freq){
        if(v.size()==nums.size()){
            ans.insert(v);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                // pick
                v.push_back(nums[i]);
                freq[i]=1;
                allPermute(nums,v,ans,freq);
                freq[i]=0;
                v.pop_back();
            }
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>ans;
        vector<int>v;
        vector<int>freq(n,0);
        allPermute(nums,v,ans,freq);

        vector<vector<int>>finAns(ans.begin(),ans.end());
        for(int i=0;i<finAns.size();i++){
            if(finAns[i]==nums){
                if(i==finAns.size()-1){
                    nums=finAns[0];
                    return;
                }
                nums=finAns[i+1];
                return;
            }
        } 
    }
    // TC: O(N!*N)
};



//BETTER SOLUTION
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());  //STL
        return;
    }
}; 

// OPTIMAL SOLUTION
// 1. LONGER PREFIX MATCH a[i] < a[i+1]  (break point)
// 2. FIND > 1, BUT THE SMALLEST ONE SO THAT YOU STAY CLOSE
// 3. TRY TO PLACE REMAINING IN SORTED ORDER
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){  //where we got dip
                index=i;
                break;
            }
        }
        
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};