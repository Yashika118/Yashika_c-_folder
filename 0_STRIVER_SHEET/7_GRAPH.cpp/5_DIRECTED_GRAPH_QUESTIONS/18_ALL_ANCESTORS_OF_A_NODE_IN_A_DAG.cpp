#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int ancestor,int currNode,vector<int>adj[],vector<vector<int>>&ans){
        for(auto it:adj[currNode]){
            if(ans[it].size()==0 or ans[it].back()!=ancestor ){
                ans[it].push_back(ancestor);
                dfs(ancestor,it,adj,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            int ancestor=i;
            dfs(ancestor,i,adj,ans);
        }
        return ans;
    }
};