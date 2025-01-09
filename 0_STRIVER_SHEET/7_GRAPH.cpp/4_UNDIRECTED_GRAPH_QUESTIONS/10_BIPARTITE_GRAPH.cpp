// USING BFS
// Bipartite graph is a graph in which we color the graph with 2 colors such that no adjacent nodes have same color
// LINEAR GRAPH WITH NO CYCLE are Bipartite
// Any Graph with EVEN cycle length is always Bipartite
// Any Graph with ODD cycle length is NOT Bipartite

// my solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool func(int start,vector<int>&visited,vector<vector<int>>& graph){
        int n=graph.size();
        queue<int>q;
        vector<int>color(n,-1);
        q.push(start);
        visited[start]=1;
        color[start]=0;
        

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:graph[node]){
                if(!visited[it]){
                    visited[it]=1;
                    color[it]=!color[node];
                    q.push(it);
                }
                else{
                    if(color[it]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(func(i,visited,graph)==false) return false;
            }
        }
        
        return true;
    }
};




// } Driver Code Ends
class Solution
{
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                // if adjacent node is not coloured
                // give adjacent node opposite color
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                // if adjacent node having the same color
                // someone did color it on other path
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        int color[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// // USING DFS
// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution {
//     bool dfs(int node,int col,int color[],vector<int>adj[]){
//         color[node]=col;

//         for(auto it:adj[node]){
//             if(color[it]==-1){
//                 if(dfs(it,!col,color,adj)==false){
//                     return false;
//                 }
//             }
//             else if(color[it]==col){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
// 	bool isBipartite(int V, vector<int>adj[]){
// 	    // Code here
// 	    int color[V];
// 	    for(int i=0;i<V;i++){
// 	        color[i]=-1;
// 	    }

// 	    for(int i=0;i<V;i++){
// 	        if(color[i]==-1){
// 	            if(dfs(i,0,color,adj)==false){
// 	                return false;
// 	            }
// 	        }
// 	    }
// 	    return true;
// 	}

// };