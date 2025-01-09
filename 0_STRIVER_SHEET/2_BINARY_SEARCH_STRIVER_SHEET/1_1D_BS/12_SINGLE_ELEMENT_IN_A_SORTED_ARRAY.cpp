#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        // for one size array
        if(n==1) return nums[0];

        for(int i=0;i<n;i++){
            // for first element
            if(i==0){
                if(nums[i]!=nums[i+1]) return nums[i];
            }
            // for last element
            else if(i==n-1){
                if(nums[i]!=nums[i-1]) return nums[i];
            }
            // for all elements except first and last
            else{
                if(nums[i]!=nums[i-1] and nums[i]!=nums[i+1]) return nums[i];
            }
        }

        return -1;
        // TC: O(N)  --> INTERVIEWER WILL NOT HAPPY WITH THIS
    }
};



// USING BINARY SEARCH
// (even,odd) --> ele is on right half
// (odd,even) --> ele is on left half
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1]) return nums[i];
            }
            else if(i==n-1){
                if(nums[i]!=nums[i-1]) return nums[i];
            }
            else{

                int low=1; int high=n-2;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1]){
                        return nums[mid];
                    }
                    // we are in left of our ans
                    else if(( mid%2==1 and nums[mid]==nums[mid-1] ) || (mid%2==0 and nums[mid]==nums[mid+1] )){
                        low=mid+1;
                    }
                    // we are in right of our ans
                    else{
                        high=mid-1;
                    }

                }
            }
        }

        return -1;
    }
};

