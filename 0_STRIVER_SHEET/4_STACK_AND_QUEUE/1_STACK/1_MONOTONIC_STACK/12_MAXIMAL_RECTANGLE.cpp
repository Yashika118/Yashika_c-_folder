#include<bits/stdc++.h>
using namespace std;
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>presum(n,vector<int>(m,0));
        int maxArea=INT_MIN;

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                presum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestRectangleArea(presum[i]));
        }
        return maxArea;
    }
};