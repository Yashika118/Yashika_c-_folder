#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int row,int col,vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(row==0 and col==0) return grid[row][col];
        if(row<0 || col<0) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];

        int up=INT_MAX; int left=INT_MAX;
        if(row>0) up=grid[row][col]+func(row-1,col,grid,dp);
        if(col>0) left=grid[row][col]+func(row,col-1,grid,dp);

        return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,grid,dp);
    }
    // TC:O(N*M)
    // SC:O(N*M)+O((M-1)+(N-1))
};


// // TABULATION
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 and j==0){
//                     dp[i][j]=grid[i][j];
//                 } 
//                 else{

//                     int right=INT_MAX; int down=INT_MAX;
//                     if(i>0) right=grid[i][j]+dp[i-1][j];
//                     if(j>0) down=grid[i][j]+dp[i][j-1];
//                     dp[i][j]=min(right,down);
//                 }
//             }
//         }

//         return dp[m-1][n-1];
//     }
//     // TC:O(N^2)
//     // SC:O(M*N)
// };


// // SPACE OPTIMISATION
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<int>prev(4,0);
//     prev[0]=max(points[0][1],points[0][2]);
//     prev[1]=max(points[0][0],points[0][2]);
//     prev[2]=max(points[0][0],points[0][1]);
//     prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

//     for(int day=1;day<n;day++){
//         vector<int>temp(4,0);
//         for(int last=0;last<4;last++){
//             temp[last]=0;

//             for(int task=0;task<3;task++){

//                 if(task!=last){
//                     temp[last]=max(temp[last],points[day][task]+prev[task]);
//                 }
//             }
            
//         }
//         prev=temp;
//     }
//     return prev[3];
//  // TC:O(N*4*3)
//  // SC:O(4)
// }