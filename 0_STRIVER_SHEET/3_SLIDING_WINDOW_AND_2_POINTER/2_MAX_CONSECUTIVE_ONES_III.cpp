#include<bits/stdc++.h>
using namespace std;

// /BRUTE FORCE
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            int cntZeroes=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0) cntZeroes++;
                if(cntZeroes<=k){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
        // TC:O(N^2)
        // SC:O(1)
    }
};

// BETTER APPROACH
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int cntZeroes=0;
        int maxlen=0;
        while(r<n){
            if(nums[r]==0) cntZeroes++;
            while(cntZeroes>k){
                if(nums[l]==0){
                    cntZeroes--;
                }
                    l++;
            }
            if(cntZeroes<=k){
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            r++;  
        }
        return maxlen;
    }
    // TC:O(N)+O(N)
    // SC:O(1)
};

// OPTIMAL APPROACH
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int cntZeroes=0;
        int maxlen=0;
        while(r<n){
            if(nums[r]==0) cntZeroes++;
            if(cntZeroes<=k){
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            if(cntZeroes>k){
                if(nums[l]==0){
                    cntZeroes--;
                }
                l++;
            }
            r++;
        }
        return maxlen;
    }
    // TC:O(N)
    // SC:O(1)
};