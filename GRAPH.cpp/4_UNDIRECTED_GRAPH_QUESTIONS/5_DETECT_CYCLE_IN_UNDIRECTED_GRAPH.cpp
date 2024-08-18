// USING BFS

// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution
// {
//     bool detect(int src, vector<int> adj[], int visited[])
//     {
//         visited[src] = 1;
//         queue<pair<int, int>> q;
//         q.push({src, -1});

//         while (!q.empty())
//         {
//             int node = q.front().first;    // 6
//             int parent = q.front().second; // 3
//             q.pop();

//             for (auto x : adj[node])
//             {
//                 if (!visited[x])
//                 {
//                     visited[x] = 1;
//                     q.push({x, node});
//                 }
//                 else if (parent != x)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

// public:
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[])
//     {

//         // Code here
//         int visited[V] = {0};
//         for (int i = 0; i < V; i++)
//         {
//             if (!visited[i])
//             {
//                 if (detect(i, adj, visited))
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     // TC: O(N+2E)
//     // SC:O(N)+O(N)=O(N)
// };

// USING DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int parent, vector<int> adj[], int visited[])
    {
        visited[node] = 1;
        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                if (dfs(x, node, adj, visited))
                {
                    return true;
                }
            }
            else if (parent != x)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adj, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }

    // SC: O(N)+O(N)=RECURSIVE STACK SPACE + VISITED ARR SPACE= O(N)
    // TC: O(N+2E)+ O(N)
};