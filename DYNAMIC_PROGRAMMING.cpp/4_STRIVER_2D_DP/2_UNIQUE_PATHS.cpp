#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>&dp){
        if(row==0 and col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        int up=func(row-1,col,dp);
        int left=func(row,col-1,dp);
        return dp[row][col]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
    // TC:O(N*M);
    // O((N-1)+(M-1))+O(N*M);  --> RECURSION STACK SPACE + DP SPACE
};


// // TABULATION
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         // dp[0][0]=1;

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 and j==0){
//                      dp[i][j]=1;
//                 }
//                 else{
//                     int up=0; int left=0;
//                     if(i>0) up=dp[i-1][j];
//                     if(j>0) left=dp[i][j-1];
//                     dp[i][j]=up+left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//         // TC:O(N*M)
//         // SC:O(N*M)
//     }
// };