#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        for(int i=0;i<pos.size();i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
    // TC: O(N)+O(N)
    // SC: O(2N)
};


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        for(int i=0;i<pos.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }

        return nums;
    }
    // TC: O(N)+O(N)
    // SC: O(N)
};

// OPTIMAL SOLUTION
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                    pos=pos+2;
            }
            else{
                ans[neg]=nums[i];
                    neg=neg+2;
            }
        }
        return ans;
    }

    // TC:O(N)
    // SC:O(N)
};