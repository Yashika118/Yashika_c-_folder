#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<int>&visited,vector<vector<int>>& graph,vector<vector<int>>&ans,vector<int>&v,vector<int>&pathvis){
        int n=graph.size();
        visited[node]=1;
        pathvis[node]=1;
        v.push_back(node);
        for(auto it:graph[node]){
            if(!visited[it] and !pathvis[it]){
                dfs(it,visited,graph,ans,v,pathvis);
            }
            else if(visited[it] and !pathvis[it]){
                dfs(it,visited,graph,ans,v,pathvis);
            }
        }
        if(node==n-1){
            ans.push_back(v);
        }
        v.pop_back();
        pathvis[node]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>pathvis(n,0);
        vector<vector<int>>ans;
        vector<int>v;
                dfs(0,visited,graph,ans,v,pathvis);
        return ans;
    }
};




