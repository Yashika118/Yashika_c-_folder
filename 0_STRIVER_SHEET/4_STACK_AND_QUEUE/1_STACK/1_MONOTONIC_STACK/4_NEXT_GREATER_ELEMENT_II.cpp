#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=2*n-1;j++){
                int ind=j%n;
                if(nums[ind]>nums[i]){
                    ans[i]=nums[ind];
                    break;
                }
            }

        }
        return ans;
    }
    // TC:O(2N^2)
    // SC:O(N)
};



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=(2*n-1);i>=0;i--){
            while(!st.empty() and st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                ans[i]=st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;

    }
}; 
// TC:O(4N)
// SC:O(2N)