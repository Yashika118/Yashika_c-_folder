// MEMOISATION
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(dp[row][col]!=1e9) return dp[row][col];
        if(row==triangle.size()-1) return triangle[row][col];

        int below=triangle[row][col]+func(row+1,col,triangle,dp);
        int diagonal=triangle[row][col]+func(row+1,col+1,triangle,dp);

        return dp[row][col]=min(below,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=i;j++){
        //         dp[i].push_back(1e9);
        //     }
        // }
        return func(0,0,triangle,dp);
    }
    // TC:O(N*N)
    // SC:O(N)
};

// TABULATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int below=triangle[i][j]+dp[i+1][j]; //2+
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(below,diagonal);
            }
        }

        return dp[0][0];
    }
    // TC:O(N*N)
    // SC:O(N*N)
    
};


// SPACE OPTIMISATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // prev row
        vector<int>prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            // curr row
            vector<int>curr(n,1e9);
            for(int j=i;j>=0;j--){
                int below=triangle[i][j]+prev[j]; //2+
                int diagonal=triangle[i][j]+prev[j+1];
                curr[j]=min(below,diagonal);
            }
            prev=curr;
        }

        return prev[0];
    }
    // TC:O(N*N)
    // SC:O(N)
    
};