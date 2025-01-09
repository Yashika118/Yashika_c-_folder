#include<bits/stdc++.h>
using namespace std;
// BETTER SOLUTION
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(); int count=0;
        int first=nums[0]; int last=nums[n-1];
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
        }

        if(last>first){
            count++;
        }

        if(count==1 || count==0) return true;
        return false;
    }
    // TC:O(N)
};