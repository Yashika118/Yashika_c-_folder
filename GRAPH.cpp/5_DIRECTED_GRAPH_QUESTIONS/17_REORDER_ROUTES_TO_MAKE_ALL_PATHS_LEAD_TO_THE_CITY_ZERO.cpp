#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<int>&visited,vector<pair<int,int>>adj[],int &count){
        visited[node]=1;
        for(auto it:adj[node]){
            int Node=it.first;
            int val=it.second;
            if(!visited[Node]){
                if(val==1) count++;
                dfs(it.first,visited,adj,count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        vector<int>visited(n,0);
        int count=0;
            if(!visited[0]){
                dfs(0,visited,adj,count);
            }
        

        return count;
    }
};