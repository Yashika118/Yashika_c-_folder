//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]+wt < dist[v] and dist[u]!=1e8){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        // Nth relaxaxtion to check -ve cycle
        for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                if(dist[u]+wt < dist[v] and dist[u]!=1e8){
                   return {-1};
                }
            }
        
        return dist;
    }
};
//TC: V*E

