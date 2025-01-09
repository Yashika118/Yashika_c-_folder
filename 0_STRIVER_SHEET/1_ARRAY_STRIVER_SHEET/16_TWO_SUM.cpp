#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
    // TC: O(N^2)
    // SC: O(N)
};


// BETTER SOLUTION
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;  // O(LOG N)
        for(int i=0;i<n;i++){ //O(N)
            int a=nums[i];
            int more=target-a;
            if(mp.find(more)!=mp.end()){  // does exist
                ans.push_back(i);
                ans.push_back(mp[more]);
                break;
            }
            if(mp.find(more)==mp.end()){
                mp[a]=i;
            }
        }
        return ans;
        // TC:O(N LOG N)
        // SC: O(N)
    }
    // TC: O(N LOG N)
};




// OPTIMAL SOLUTION BUT IT CAN ONLY RETURN ELEMENTS NOT INDICES
// OR IF ARR IS SORTED THEN IT CAN RETURN INDICES
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0; int right=n-1;
        sort(nums.begin(),nums.end());
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                return {left,right};
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }

        return {};
    }
};