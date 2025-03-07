//{ Driver Code Starts
// Initial Template for C++
// USING DFS

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> mat, int delrow[], int delcol[])
    {
        visited[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !visited[nrow][ncol] and mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, visited, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        // traverse first row and last row
        for (int j = 0; j < m; j++)
        {
            // fisrt row
            if (!visited[0][j] and mat[0][j] == 'O')
            {
                dfs(0, j, visited, mat, delrow, delcol);
            }
            // last row
            if (!visited[n - 1][j] and mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, visited, mat, delrow, delcol);
            }
        }
        // traverse first col and last col
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] and mat[i][0] == 'O')
            {
                dfs(i, 0, visited, mat, delrow, delcol);
            }
            if (!visited[i][m - 1] and mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, visited, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 and mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

// USING BFS
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int n=board.size();
//         int m=board[0].size();
//         vector<vector<int>>visited(n,vector<int>(m,0));
//         queue<pair<int,int>>q;
//         for(int j=0;j<m;j++){
//             if(!visited[0][j] and board[0][j]=='O'){
//                 q.push({0,j});
//                 visited[0][j]=1;
//             }
//             if(!visited[n-1][j] and board[n-1][j]=='O'){
//                 q.push({n-1,j});
//                 visited[n-1][j]=1;
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(!visited[i][0] and board[i][0]=='O'){
//                 q.push({i,0});
//                 visited[i][0]=1;
//             }
//             if(!visited[i][m-1] and board[i][m-1]=='O'){
//                 q.push({i,m-1});
//                 visited[i][m-1]=1;
//             }
//         }

//         int delrow[]={-1,1,0,0};
//         int delcol[]={0,0,-1,1};

//         while(!q.empty()){
//             int row=q.front().first;
//             int col=q.front().second;
//             q.pop();

//             for(int i=0;i<4;i++){
//                 int nrow=row+delrow[i];
//                 int ncol=col+delcol[i];

//                 if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited[nrow][ncol] and board[nrow][ncol]=='O'){
//                     q.push({nrow,ncol});
//                     visited[nrow][ncol]=1;

//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!visited[i][j] and board[i][j]=='O'){
//                     board[i][j]='X';
//                 }
//             }
//         }
//     }
// };