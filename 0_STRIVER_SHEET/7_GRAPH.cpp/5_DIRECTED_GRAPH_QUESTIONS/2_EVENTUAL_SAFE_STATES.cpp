//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// any one who is a part of cycle cannot be a safe node
// anyone leading to a cycle cannot be a safe node
class Solution
{
private:
    bool dfs(int node, vector<int> adj[], int visited[], int pathvisited[], int check[])
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        check[node] = 0;

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                if (dfs(node, adj, visited, pathvisited, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
                else if (pathvisited[x])
                {
                    check[node] = 0;
                    return true;
                }
            }
        }
        check[node] = 1;
        pathvisited[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        int visited[V] = {0};
        int pathvisited[V] = {0};
        int check[V] = {0};
        vector<int> safenodes;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, pathvisited, check);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};


// MY SOLUTION --> BEST SOLUTION

// //{ Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// // User function Template for C++

// class Solution {
//   public:
//     bool dfs(int node, int visited[], int pathvisited[], vector<int> adj[])
//     {
//         visited[node] = 1;
//         pathvisited[node] = 1;

//         for (auto it : adj[node])
//         {
//             if (!visited[it])
//             {
//                 if (dfs(it, visited, pathvisited, adj) == true)
//                 {
//                     return true;
//                 }
//             }
//             // if node is already visited but it has to  be visited on same path
//             else if (pathvisited[it])
//             {
//                 return true;
//             }
//         }
        
//         pathvisited[node] = 0;
//         return false;
//     }
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         // code here
//         int visited[V] = {0};
//         int pathvisited[V] = {0};
//         vector<int>safeNodes;

//         for (int i = 0; i < V; i++)
//         {
//             if (!visited[i])
//             {
//                  dfs(i, visited, pathvisited, adj);
//             }
//         }
        
//         for(int i=0;i<V;i++){
//             if(visited[i]==1 and pathvisited[i]==0){
//                 safeNodes.push_back(i);
//             }
//         }
        
//         sort(safeNodes.begin(),safeNodes.end());
        
//         return safeNodes;
//     }


   
// };


