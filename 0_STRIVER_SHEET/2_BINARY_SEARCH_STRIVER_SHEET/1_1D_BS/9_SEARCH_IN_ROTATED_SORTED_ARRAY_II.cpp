#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0; int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]) return true;
            if(nums[low]==nums[mid] and nums[mid]==nums[high]){
                low=low+1;
                high=high-1;
            }
            // if left half is sorted
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target and target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // right half is sorted
            else{
                if(nums[mid]<=target and target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        return false;
    }

    // TC:O(LOG(base 2)N) -->AVERAGE CASE
    // TClO(N/2) --->WORST CASE  EXAMPLE ARR[]={3,3,1,3,3,3,3}
};