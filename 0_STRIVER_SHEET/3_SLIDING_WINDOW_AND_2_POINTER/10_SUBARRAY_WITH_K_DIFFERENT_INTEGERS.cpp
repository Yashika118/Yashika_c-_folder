#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()==k){
                    count++;
                }
                else if(mp.size()>k){
                    break;
                }
            }
        }
        return count;
    }
    // TC:O(N^2)
    // SC:O(N)
};

// OPTIMAL SOL
class Solution {
public:
    int lessThanEqualToK(vector<int>& nums, int k){
        int n=nums.size();
        int l=0,r=0;
        int count=0;
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);  
                }
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessThanEqualToK(nums,k)-lessThanEqualToK(nums,k-1);
    }
};