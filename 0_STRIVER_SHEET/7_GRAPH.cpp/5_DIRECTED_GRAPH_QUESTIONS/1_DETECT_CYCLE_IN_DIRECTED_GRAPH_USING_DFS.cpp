        //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool dfs(int node, int visited[], int pathvisited[], vector<int> adj[])
    {
        visited[node] = 1;
        pathvisited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it, visited, pathvisited, adj) == true)
                {
                    return true;
                }
            }
            // if node is already visited but it has to  be visited on same path
            else if (pathvisited[it])
            {
                return true;
            }
        }
        pathvisited[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int visited[V] = {0};
        int pathvisited[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, pathvisited, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
//TC: V+E