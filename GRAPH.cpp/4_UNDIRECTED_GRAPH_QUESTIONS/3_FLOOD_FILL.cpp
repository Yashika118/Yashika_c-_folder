// leetcode
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> image, vector<vector<int>> &ans, int new_color, int delrow[], int delcol[], int ini)
    {

        ans[row][col] = new_color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and image[nrow][ncol] == ini and ans[nrow][ncol] != new_color)
            {
                dfs(nrow, ncol, image, ans, new_color, delrow, delcol, ini);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int initial_pixel = image[sr][sc];
        int new_color = color;
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        dfs(sr, sc, image, ans, new_color, delrow, delcol, initial_pixel);
        return ans;
    }
};

// TC: LET (N*M)=X NODES
// EVERY NODES CALLS 4 NEIGHBOURD=4*X
// AND X NO. OF NODES DFS CALLS
// TOTAL TC: X+(4*X)=O(X)=O(N*M)
// SC: TO STORE ANS =O(N*M)  + RECURSION STACK SPACE=O(N*M) => O(N*M)

//using bfs
// class Solution {
// public:
//     void bfs(int sr,int sc,vector<vector<int>>image,vector<vector<int>>&ans,vector<vector<int>>&visited,int ini_pix,int new_color){
//         int n=image.size();
//         int m=image[0].size();

//         int delrow[]={-1,1,0,0};
//         int delcol[]={0,0,-1,1};
//         visited[sr][sc]=1;
//         ans[sr][sc]=new_color;
//         queue<pair<int,int>>q;
//         q.push({sr,sc});

//         while(!q.empty()){
//             int a=q.front().first;
//             int b=q.front().second;
//             q.pop();

//             for(int i=0;i<4;i++){
//                 int neirow=a+delrow[i];
//                 int neicol=b+delcol[i];
//                 if(neirow>=0 and neirow<n and neicol>=0 and neicol<m and !visited[neirow][neicol] and image[neirow][neicol]==image[sr][sc]){
//                     visited[neirow][neicol]=1;
//                     ans[neirow][neicol]=new_color;
//                     q.push({neirow,neicol});

//                 }
//             }
//         }

//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int n=image.size();
//         int m=image[0].size();
//         int ini_pix=image[sr][sc];
//         int new_color=color;
//         vector<vector<int>>ans=image;
//         vector<vector<int>>visited(n,vector<int>(m,0));
//         bfs(sr,sc,image,ans,visited,ini_pix,new_color);
        
//         return ans;
//     }
// };


// USING BFS --> ANOTHER SOLUTION

// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         // Code here 
//         int n=image.size();
//         int m=image[0].size();
//         int color=image[sr][sc];
        
//         vector<vector<int>>visited(n,vector<int>(m,0));
//         vector<vector<int>>ans=image;
//         queue<pair<int,int>>q;
//         q.push({sr,sc});
//         visited[sr][sc]=1;
//         ans[sr][sc]=newColor;
        
//         int delrow[]={-1,1,0,0};
//         int delcol[]={0,0,-1,1};
        
//         while(!q.empty()){
//             int r=q.front().first;
//             int c=q.front().second;
//             q.pop();
            
//             for(int i=0;i<4;i++){
//                 int nrow=r+delrow[i];
//                 int ncol=c+delcol[i];
                
//                 if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==color and !visited[nrow][ncol])
//                 {
//                     visited[nrow][ncol]=1;
//                     q.push({nrow,ncol});
//                     ans[nrow][ncol]=newColor;
//                 }
//             }
            
            
//         }
//         return ans;
        
//     }
// };
