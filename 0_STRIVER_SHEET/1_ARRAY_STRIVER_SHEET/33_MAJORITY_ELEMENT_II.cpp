#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        set<int>ans;
        vector<int>v;

        for(int i=0;i<n;i++){
            int val=nums[i];
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]==val){
                    count++;
                }
            }
            if(count > (n/3)){
                ans.insert(val);
            }
        }
        for(auto it:ans){
            v.push_back(it);
        }
        return v;
    }

    // TC: O(n^2) + O(n)
    // SC: 
};


// BRUTE FORCE 2
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;

        for(int i=0;i<n;i++){
            int val=nums[i];
            if(v.size()==0 || v[0]!=val){
                int val=nums[i];
                int count=0;
                for(int j=0;j<n;j++){
                    if(nums[j]==val){
                        count++;
                    }
                }
                if(count > (n/3)){
                    v.push_back(val);
                }
            }
            if(v.size()==2) break;

        }
       
        return v;
    }
    // TC: O(n^2)
    // TC: O(1)
};

// BETTER SOLTUION 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<n;i++){  // o(log n)
            mp[nums[i]]++;
        }
        for(auto it:mp){  // o(n)
            int a=it.first;
            int b=it.second;
            if(b > (n/3)){
                ans.push_back(a);
            }
        }

        return ans;
    }
};


// BETTER SOL 2
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int min=(n/3)+1;
        map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==min){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
    // TC: O(n) * O(log n)
};


// OPTIMAL SOL
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int ele1; int cnt1=0;
        int ele2; int cnt2=0;

        for(int i=0;i<n;i++){
            if(cnt1==0 and nums[i]!=ele2){
                cnt1++;
                ele1=nums[i];
            }
            else if (cnt2 == 0 and nums[i]!=ele1){
                cnt2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0; cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
        }
        int mini = (int) (n/3) +1;
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;

    }
};