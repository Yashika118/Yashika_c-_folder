#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            int number=nums[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[j]==number){
                    cnt++;
                }
            }
            if(cnt==1) return number;
        }

        return -1;
    }
    // TC:O(N^2)
};


// BETTER SOLUTION

        // --> UNORDERED MAP
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;  // O(N) in wosrt case and O(1) in average case
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
        }

        return -1;
        // TC:O(2N)
        // SC:O(N)
    }
};
        // --> ORDERED MAP
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;  
        for(int i=0;i<n;i++){  // O(N)
            mp[nums[i]]++;   // O(LOG M) 

        } // TOTAL : O(N * LOG M)

        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
        }

        return -1;
        // TC:O(N LOG M)+M      N-->ARR , SIZE M-->MAP SIZE (M=(N/2 +1))
        // SC:O(N)
    }
};


// OPTIMAL SOLUTION
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xo_r=0;
        for(int i=0;i<n;i++){
            xo_r= xo_r ^ nums[i]; 
        }

        return xo_r;
    }
    // TC:O(N)
    // SC:O(1)
};