// geeks
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});

        visited[row][col] = 1;

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int neirow = row + delrow;
                    int neicol = col + delcol;
                    if (neirow >= 0 and neirow < n and neicol >= 0 and neicol < m and grid[neirow][neicol] == '1' and !visited[neirow][neicol])
                    {
                        visited[neirow][neicol] = 1;
                        q.push({neirow, neicol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 and grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }

        return count;
    }
    // TC:O(N^2)
    // SC:O(N^2)
};
// } Driver Code Ends

// leetcode
// class Solution {
//   public:

//     void bfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>grid){
//         int n=grid.size();
//         int m=grid[0].size();
//         queue<pair<int,int>>q;
//         q.push({row,col});

//         visited[row][col]=1;

//         while(!q.empty()){
//             int row=q.front().first;
//             int col=q.front().second;
//             q.pop();

//             int delrow[]={-1,1,0,0};
//             int delcol[]={0,0,-1,1};

//             for(int i=0;i<4;i++){
//                 int neirow=row+delrow[i];
//                     int neicol=col+delcol[i];
//                     if(neirow>=0 and neirow<n and neicol>=0 and neicol<m and grid[neirow][neicol]=='1' and !visited[neirow][neicol] ){
//                         visited[neirow][neicol]=1;
//                         q.push({neirow,neicol});
//                     }
//             }
//         }
//     }
//     // Function to find the number of islands.
//     int numIslands(vector<vector<char>>& grid) {
//         // Code here
//     int n=grid.size();
//     int m=grid[0].size();

//     int count=0;
//     vector<vector<int>>visited(n,vector<int>(m,0));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(visited[i][j]==0 and grid[i][j]=='1'){
//                 count++;
//                 bfs(i,j,visited,grid);
//             }
//         }
//     }

//     return count;

//     }
// };