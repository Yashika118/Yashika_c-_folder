#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>next_smaller_ele_index(vector<int>& heights,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prev_smaller_ele_index(vector<int>& heights,int n){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>heights[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev=prev_smaller_ele_index(heights,n); //O(2N)
        vector<int>next=next_smaller_ele_index(heights,n);  //O(2N)

        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){   //O(N)
            maxArea=max(maxArea,(next[i]-prev[i]-1)*heights[i]);
        }
        return maxArea;

    }
    // TC:O(5N)
    // SC:O(4N)
};

// OPTIMAL SOLTUION
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){

            while(!st.empty() and heights[st.top()]>heights[i]){
                int ind=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,(nse-pse-1)*heights[ind]);
                
            }

            st.push(i);
        }
        while(!st.empty()){
            int ind=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,(nse-pse-1)*heights[ind]);
        }
        return maxArea;
    }
    // TC:O(N)+O(N)
    // SC:O(N)
};