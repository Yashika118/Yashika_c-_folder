#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(); 
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                return i;
            }
            
        }

        return n;
    }
    // TC:O(N^2)
    // SC:O(1)
};


// BETTER SOLUTION
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                return i;
            }
        }

        return n;
        // TC:O(nlogn + n)
    }
};

// BETTER SOLUTION
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[n]={0};
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            if(mp[i]==0){
                return i;
            }
        }

        return n;
        // TC:O(2N)
        // SC: O(N)
    }
};


// OPTIMAL SOLUTION
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        // int sum=n*((n+1)/2);
        int sum=(n*(n+1))/2;
        int sum2=0;
        for(int i=0;i<n;i++){
            sum2+=nums[i];
        }

        return (sum-sum2);
    }
};