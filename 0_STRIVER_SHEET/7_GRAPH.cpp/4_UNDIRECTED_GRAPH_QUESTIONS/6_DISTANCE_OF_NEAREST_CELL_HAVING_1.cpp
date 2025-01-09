//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            distance[row][col] = step;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and visited[nrow][ncol] == 0)
                {
                    q.push({{nrow, ncol}, step + 1});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return distance;
    }
    // TC=(N*M)+(4*N*M)=N*M
    // SC=(2*N*M)+(N*M)=N*M
};