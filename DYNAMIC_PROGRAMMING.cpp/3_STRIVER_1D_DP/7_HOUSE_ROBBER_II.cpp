#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func1(int ind,vector<int>nums,vector<int>&dp1){
        if(ind==1) return nums[ind];
        if(ind<1) return 0;
        if(dp1[ind]!=-1) return dp1[ind];

        int pick=nums[ind]+func1(ind-2,nums,dp1);
        int notPick=0+func1(ind-1,nums,dp1);

        return dp1[ind]=max(pick,notPick);
    }
    int func2(int ind,vector<int>nums,vector<int>&dp2){
        
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp2[ind]!=-1) return dp2[ind];

        int pick=nums[ind]+func2(ind-2,nums,dp2);
        int notPick=0+func2(ind-1,nums,dp2);

        return dp2[ind]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n,-1);
        int ans1=func1(n-1,nums,dp1);
        int ans2=func2(n-2,nums,dp2);

        return max(ans1,ans2);
    }
};



// SPACE OPTIMISATION
// class Solution {
// public:
//     int func(vector<int>&nums){
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
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         vector<int>temp1;
//         vector<int>temp2;

//         for(int i=0;i<n;i++){
//             if(i!=0) temp1.push_back(nums[i]);
//             if(i!=n-1) temp1.push_back(nums[i]);
//         }

//         int f1=func(temp1);
//         int f2=func(temp2);
//         return max(f1,f2);
//     }
// };