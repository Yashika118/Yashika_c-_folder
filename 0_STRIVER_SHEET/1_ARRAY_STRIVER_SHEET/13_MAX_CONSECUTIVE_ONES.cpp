#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0; int cnt=0;

        for(int i=0;i<n;i++){
            cnt=0;
            if(nums[i]==1){
                for(int j=i;j<n;j++){
                    if(nums[j]==1){
                        cnt++;
                        ans=max(ans,cnt);
                    }
                    else{
                        break;
                    }
                }
            }
        }

        return ans;
        // TC:O(N^2)
        // SC:O(1)
    }
};


// OPTIMAL SOLUTION
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0; int cnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                ans=max(ans,cnt);
            }
            else {
                cnt=0;
            }
        }

        return ans;
    }
    // TC:O(N)
};