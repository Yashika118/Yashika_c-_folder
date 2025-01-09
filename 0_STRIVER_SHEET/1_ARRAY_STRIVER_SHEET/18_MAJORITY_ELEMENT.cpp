#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int val=nums[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(val==nums[j]){
                    cnt++;
                }
            }
            if(cnt>(n/2)){
                return val;
            }
        }
        return -1;
    }
    // TC:O(N^2)
    // SC:O(1)
};

// BETTER SOUTION
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int x=n/2;
        map<int,int>mp;     // LOG N FOR ORDERED MAP
        for(int i=0;i<n;i++){  // N LOG N    FOR LOOP+MAP
            mp[nums[i]]++;
        }

        for(auto it:mp){        // O(N)
            int a=it.first;
            int b=it.second;
            if(b>x){
                return a;
            }
        }

        return -1;
        // TC: O(N LOG N) + O(N)
        // SC: O(N)
    }
};


// OPTIMAL SOLUTION
// MOORE'S VOTING ALGORITHM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ele;

        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt++;
                ele=nums[i];
            }
            // cnt != 0
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) cnt1++;
        }
        if(cnt1>(n/2)) return ele;
        return -1;
    }
    // TC:O(N)+O(N)
    // SC:O(1)
};
