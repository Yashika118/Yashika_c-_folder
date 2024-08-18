// MEMOISATION
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxMoney(int ind,vector<int>& nums,int dp[]){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+maxMoney(ind-2,nums,dp);
        int notPick=0+maxMoney(ind-1,nums,dp);
        return dp[ind]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return maxMoney(n-1,nums,dp);
    }
    // TC:O(N)
    // SC:O(N)+O(N)
};



// TABULATION
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         int dp[n];
//         memset(dp,-1,sizeof(dp));
//         dp[0]=nums[0];
//         int neg=0;
//         for(int i=1;i<n;i++){
//             int take=nums[i];
//             if(i>1) take+=dp[i-2];
//             int notTake=0+dp[i-1];
//             dp[i]=max(take,notTake);
//         }

//         return dp[n-1];
//         // TC:O(N)
//         // SC:O(N)
//     }
// };


//SPACE OPTIMISATION
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size()==1) return nums[0];
//         int n=nums.size();
//         int prev=nums[0];
//         int prev2=0;
//         int curi;
//         for(int i=1;i<n;i++){
//             int take=nums[i];
//             if(i>1) take+=prev2;
//             int notTake=0+prev;
//            curi=max(take,notTake);
//            prev2=prev;
//            prev=curi;
//         }

//         return curi;
//     }
// };