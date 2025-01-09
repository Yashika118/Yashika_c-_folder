#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int src,vector<int>&visited,vector<vector<int>>&adj,int destination,int n){
        visited[src]=1;
        for(auto it:adj[src]){
            if(it==destination){
                return true;
            }
            if(!visited[it]){
               if(dfs(it,visited,adj,destination,n)) return true;
            }
        } 
        return false;  
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(source==destination) return true;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>visited(n,0);

        for(int i=0;i<n;i++){
            if(i==source and !visited[i]){
                if(dfs(i,visited,adj,destination,n)) return true;
            }
        }

        return false;
    }
};