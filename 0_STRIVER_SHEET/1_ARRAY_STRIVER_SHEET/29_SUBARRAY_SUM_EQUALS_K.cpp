#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int m=i;m<=j;m++){
                    sum+=nums[m];
                    
                }
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};

// BETTER FORCE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
    // TC:O(N^2)
};

// OPTIMAL SOL
// HERE NO. OF SUBARR = NO. OF TIMES SUM-K APPEARS
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<long long,int>mp;
        // presum  count
        mp[0]=1;
        int presum=0;
        int count=0;

        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            count+=mp[remove];
            mp[presum]+=1;
        }
        return count;

        
    }
};