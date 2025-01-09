#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int largest=nums[i]; int smallest=nums[i];
            for(int j=i;j<n;j++){
                largest=max(largest,nums[j]);
                smallest=min(smallest,nums[j]);
                sum+=largest-smallest;
            }
        } 
        return sum;  
    }
    // TC:O(N^2)
    // SC:O(1)
};

// OPTIMAL SOL
class Solution {
public:
    vector<int>prev_greater_ele_index(vector<int>& nums,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>next_greater_ele_index(vector<int>& nums,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prev_smaller_ele_index(vector<int>& nums,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>next_smaller_ele_index(vector<int>& nums,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumOfSubarrayMin(vector<int>& nums,int n){
        vector<int>prev(n),next(n);
        prev=prev_smaller_ele_index(nums,n);
        next=next_smaller_ele_index(nums,n);
        int mod=(int)(1e9+7);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-prev[i];
            int right=next[i]-i;
            sum+=(left*right*1LL*nums[i]);
        }
        return sum;
    }
    long long sumOfSubarrayMax(vector<int>& nums,int n){
        vector<int>prev(n),next(n);
        prev=prev_greater_ele_index(nums,n);
        next=next_greater_ele_index(nums,n);
        int mod=(int)(1e9+7);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-prev[i];
            int right=next[i]-i;
            sum+=(left*right*1LL*nums[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=sumOfSubarrayMax(nums,n)-sumOfSubarrayMin(nums,n);
        return sum;
    }
};