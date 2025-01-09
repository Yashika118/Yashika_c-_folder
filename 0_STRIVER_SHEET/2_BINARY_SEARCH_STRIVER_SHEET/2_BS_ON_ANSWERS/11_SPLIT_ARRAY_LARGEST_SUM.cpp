#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    bool canWeSplit(vector<int>& nums,int k,int sum){
        int cntSubArr=1;
        int subArrSum=0;
        for(int i=0;i<nums.size();i++){
            if(subArrSum+nums[i]<=sum){
                subArrSum+=nums[i];
            }
            else{
                subArrSum=nums[i];
                cntSubArr++;
            }
        }
        if(cntSubArr<=k){
            return true;
        }
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxVal=INT_MIN; int maxSum=0;
        for(int i=0;i<n;i++){
            maxVal=max(maxVal,nums[i]);
            maxSum+=nums[i];
        }

        for(int i=maxVal;i<=maxSum;i++){
            if(canWeSplit(nums,k,i)){
                return i;
            }
        }

        return -1;

    }
};


// OPTIMAL SOL
class Solution {
public:
    bool canWeSplit(vector<int>& nums,int k,int sum){
        int cntSubArr=1;
        int subArrSum=0;
        for(int i=0;i<nums.size();i++){
            if(subArrSum+nums[i]<=sum){
                subArrSum+=nums[i];
            }
            else{
                subArrSum=nums[i];
                cntSubArr++;
            }
        }
        if(cntSubArr<=k){
            return true;
        }
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxVal=INT_MIN; int maxSum=0;
        for(int i=0;i<n;i++){
            maxVal=max(maxVal,nums[i]);
            maxSum+=nums[i];
        }

        int low=maxVal;
        int high=maxSum;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(canWeSplit(nums,k,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        

        return ans;

    }
};