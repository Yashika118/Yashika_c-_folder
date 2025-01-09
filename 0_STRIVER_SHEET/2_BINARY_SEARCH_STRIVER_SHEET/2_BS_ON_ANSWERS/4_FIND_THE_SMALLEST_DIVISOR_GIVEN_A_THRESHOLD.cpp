// LINEAR SEARCH
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool func(vector<int>& nums,int threshold,int i){
        int n=nums.size();
        int divisor=0;
        double sum=0;
            for(int j=0;j<n;j++){
                double a=nums[j], b=i;
                double quo=ceil(a/b);
                sum+=quo;
                if(sum>threshold) return 0;
            }
            // if(sum<=threshold){
            //     // divisor=i;
            //     return 1;
            //     // break;
            // }

            return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        for(int i=1;i<=INT_MAX;i++){
            if(func(nums,threshold,i)) return i; 
        }
        return 0;
    }
};


// BINARY SEARCH
class Solution {
public:
    bool func(vector<int>& nums,int threshold,int i){
        int n=nums.size();
        int divisor=0;
        double sum=0;
            for(int j=0;j<n;j++){
                double a=nums[j], b=i;
                double quo=ceil(a/b);
                sum+=quo;
                if(sum>threshold) return 0;
            }
            // if(sum<=threshold){
            //     // divisor=i;
            //     return 1;
            //     // break;
            // }

            return 1;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1; int high=INT_MAX;
        int ans=-1;
        while(low<=high){
            int mid=(low/2)+(high/2);

            if(func(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};