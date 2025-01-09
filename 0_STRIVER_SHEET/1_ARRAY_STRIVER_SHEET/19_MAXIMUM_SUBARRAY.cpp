#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                maxi=max(maxi,sum);
            }
        }

        return maxi;
    }
    // TC: O(N^2)  -->GIVES TLE
    // SC: O(1)
};


// OPTIMAL SOLUTION
// KADANE'S ALGORIHTM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
    // TC:O(N)
    // SC:O(1)
};