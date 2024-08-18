//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] and grid[row][col] == 1)
                {
                    // bfs
                    vector<pair<int, int>> v;
                    queue<pair<int, int>> q;
                    q.push({row, col});
                    visited[row][col] = 1;
                    v.push_back({row - row, col - col});

                    while (!q.empty())
                    {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++)
                        {
                            int nrow = r + delrow[i];
                            int ncol = c + delcol[i];

                            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !visited[nrow][ncol] and grid[nrow][ncol] == 1)
                            {
                                q.push({nrow, ncol});
                                visited[nrow][ncol] = 1;
                                v.push_back({nrow - row, ncol - col});
                            }
                        }
                    }

                    st.insert(v);
                }
            }
        }
        // TC: (N*M*)*LOG(N*M)+(N*M*4)
        return st.size();
    }
};