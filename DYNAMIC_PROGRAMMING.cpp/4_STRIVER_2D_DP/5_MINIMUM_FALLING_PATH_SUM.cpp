#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>& matrix,int n,vector<vector<int>>&dp){
        if(row==n-1){
            return matrix[row][col];
        }
        if(dp[row][col]!=1e9) return dp[row][col];

        int below=INT_MAX; int diaLeft=INT_MAX; int diaRight=INT_MAX;
        
        below=matrix[row][col]+func(row+1,col,matrix,n,dp);
        if(col>0) diaLeft=matrix[row][col]+func(row+1,col-1,matrix,n,dp);
        if(col<n-1) diaRight=matrix[row][col]+func(row+1,col+1,matrix,n,dp);
        return dp[row][col]=min(below,min(diaLeft,diaRight));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int result=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            int ans=func(0,i,matrix,n,dp);
            result=min(result,ans);
        }

        return result;
    }
    // TC: O(3^(N))  
    // SC: O(N)      

    
};



// TABULATION
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int result=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int below=INT_MAX; int diaLeft=INT_MAX; int diaRight=INT_MAX;
                below=matrix[i][j]+dp[i+1][j];
                if(j>0) diaLeft=matrix[i][j]+dp[i+1][j-1];
                if(j<n-1) diaRight=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min(below,min(diaLeft,diaRight));
            }
        }
        for(int k=0;k<n;k++){
            if(dp[0][k]<result){
                result=dp[0][k];
            }
        }
        return result;
    }
    // TC:O(N*M)
    // SC:O(N*M)+O(N)
};


// SPACE OPTIMISATION
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int result=INT_MAX;
        vector<int>prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,1e9);
            for(int j=0;j<n;j++){
                int below=INT_MAX; int diaLeft=INT_MAX; int diaRight=INT_MAX;
                below=matrix[i][j]+prev[j];
                if(j>0) diaLeft=matrix[i][j]+prev[j-1];
                if(j<n-1) diaRight=matrix[i][j]+prev[j+1];
                curr[j]=min(below,min(diaLeft,diaRight));
            }
            prev=curr;
        }
        for(int k=0;k<n;k++){
            if(prev[k]<result){
                result=prev[k];
            }
        }
        return result;
    }
};