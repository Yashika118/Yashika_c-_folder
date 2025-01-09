// MONOTONIC STACK --> WHEN WE STORE DATA IN STACK IN SOME SPECIFIC ORDER EITHER INCREASING OR DECREASING OR ANY SPECIFIC ORDER

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            
            st.push(arr[i]);
        }
        return ans;
    }
};
// TC:O(2N)
// SC:O(N)+O(N)