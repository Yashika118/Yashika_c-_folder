// PEAK ELEMENT ---> arr[i-1] < arr[i] > arr[i+1]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            // striver
            // if(( i==0 || nums[i-1] < nums[i]) and ( i==n-1 || nums[i]>nums[i+1] )){
            //     return i;
            // }
            

            // this is my solution
            if(i==0){
                if(nums[i] > nums[i+1]) return i;
            }
            else if( i==n-1){
                if(nums[i]>nums[i-1]) return i;
            }
            else{
                if(nums[i]>nums[i-1] and nums[i]>nums[i+1]) return i;
            }
        }

        return -1;
    }
    // TC: O(N)  --> INTERVIEWER WILL NOT HAPPY FOR THIS
};



// USING BINARY SEARCH
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        else if(nums[0]>nums[1]) return 0;
        else if(nums[n-1]> nums[n-2]) return n-1;
        else{
            int low=1; int high=n-2;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]) return mid;
                else{
                    if(nums[mid]>nums[mid+1]){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
            }
        }
       return -1;
    }
};