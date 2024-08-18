#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&visited,int destination){
        visited[node]=1;
        for(auto it:adj[node]){
            if(it==destination){
                visited[it]=1;
                return true;
            }
            if(!visited[it]){
                if(dfs(it,adj,visited,destination)){ // true
                return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(source==destination) return true;
            if(i==source){
                if(!visited[i]){
                    if(dfs(i,adj,visited,destination)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};