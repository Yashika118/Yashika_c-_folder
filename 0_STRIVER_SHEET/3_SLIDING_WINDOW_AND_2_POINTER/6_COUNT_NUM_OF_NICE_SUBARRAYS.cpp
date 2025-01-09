#include<bits/stdc++.h>
using namespace std;

// here we can assume odd num = 1 and even num =0
// if given arr is      1 5 1 2 1 1
// we can assume it as  1 1 1 0 1 1
// now do it in a same way as previous question

class Solution {
public:
     int lessEqualToK(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }

        int n=nums.size();
        int count=0;
        int sum=0;
        int l=0,r=0;
        while(r<n){
            sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
            
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lessEqualToK(nums,k)-lessEqualToK(nums,k-1);
    }
};