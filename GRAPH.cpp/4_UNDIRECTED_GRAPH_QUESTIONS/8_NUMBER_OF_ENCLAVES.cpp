#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // void fun(vector<vector<int>>visited,int n,int m){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             cout<<visited[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] and grid[0][j] == 1)
            {
                q.push({0, j});
                visited[0][j] = 1;
            }
            if (!visited[n - 1][j] and grid[n - 1][j] == 1)
            {
                q.push({n - 1, j});
                visited[n - 1][j] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] and grid[i][0] == 1)
            {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if (!visited[i][m - 1] and grid[i][m - 1] == 1)
            {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        // we can use this for loop for instead of above two for loops
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         // first row ,first col,last row, last col
        //         if(i==0 || j==0 || i==n-1 || j==m-1){
        //             if(grid[i][j]==1){
        //                 q.push({i,j});
        //                 visited[i][j]=1;
        //             }
        //         }
        //     }
        // }

        // fun(visited,n,m);
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !visited[nrow][ncol] and grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        // fun(visited,n,m);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] and grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};