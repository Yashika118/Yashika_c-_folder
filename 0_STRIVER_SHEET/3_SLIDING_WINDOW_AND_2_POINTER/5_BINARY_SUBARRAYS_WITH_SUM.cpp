#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal){
                    count++;
                }
            }
        }
        return count;
    }
    // TC:O(N^2);
    // SC: O(1)
};

// BETTER SOL
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        map<int,int>mp;
        int presum=0;
        int count=0;

        mp[0]=1;

        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-goal;
            count+=mp[remove];
            mp[presum]++;
        }

        return count;
        
    }
    // TC:O(N)
    // SC:O(N)
};

// OPTIMAL SOL
class Solution {
public:
    int lessEqualToGoal(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }

        int n=nums.size();
        int count=0;
        int sum=0;
        int l=0,r=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // sumEqualToGoal= lessEqualToGoal(nums,goal)-lessEqualToGoal(nums,goal-1)
        return lessEqualToGoal(nums,goal)-lessEqualToGoal(nums,goal-1);
    }
    // TC:O(2*2N)
    // SC:O(1)
};