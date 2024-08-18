#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0; int high=n-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;
            // if arr is already sorted
            if(nums[low]<=nums[high]){
                ans=min(ans,nums[low]);
            }
            // if left half is sorted then pick the first element of left half
            // because it might be minimum
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
               low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
                
            }
        }

        return ans;
    }
};