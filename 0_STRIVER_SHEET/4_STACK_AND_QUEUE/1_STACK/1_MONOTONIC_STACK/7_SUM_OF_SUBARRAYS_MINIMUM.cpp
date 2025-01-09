#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=(int) (1e9+7);
        int sum=0;
        int mini;
        for(int i=0;i<n;i++){
            mini=arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum=(sum+mini)%mod;
            }
        }

        return sum;
    }
};
// TC:O(N^2)
// SC:O(1)


class Solution {
public:
    vector<int>prev_smaller_ele_index(vector<int>& arr,int n){
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]= st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>next_smaller_ele_index(vector<int>& arr,int n){
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]= st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(n);
        vector<int> next(n);
        int mod=(int)(1e9+7);
        prev=prev_smaller_ele_index(arr,n);
        next=next_smaller_ele_index(arr,n);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long left=i-prev[i];
            long long right=next[i]-i;
            sum=(sum+(left*right*arr[i])%mod)%mod;
        }
        return sum;
    }
    // TC:O(5N)
    // SC:O(5N)
};