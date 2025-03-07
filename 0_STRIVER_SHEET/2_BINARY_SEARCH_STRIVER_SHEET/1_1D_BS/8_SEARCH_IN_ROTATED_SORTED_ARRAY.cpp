#include<bits/stdc++.h>
using namespace std;
// FIRST APPROACH CAN BE LINEAR SEARCH ---> TC: O(N)


// 2ND APPROACH
// FIRST IDENTIFY THE SORTED HALF : LEFT OR RIGHT
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0; int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            // if left half is sorted
            else if(nums[low]<=nums[mid]){  // it means left half is sorted
                if(nums[low]<= target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // if right half is sorted
            else{
                if(nums[mid]<=target and target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        return -1;
    }
};