#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int least,int node,vector<int>&temp,vector<int>adj[],vector<int>newQuiet){
        if(temp[node]==-1){
            temp[node]=newQuiet[least];
        }
        for(auto it:adj[node]){
            if(temp[it]==-1){
                dfs(least,it,temp,adj,newQuiet);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>adj[n];
        for(auto it:richer){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>newQuiet(n,-1);
        for(int i=0;i<n;i++){
            newQuiet[quiet[i]]=i;
        }

        vector<int>temp(n,-1);

        for(int i=0;i<n;i++){
            dfs(i,newQuiet[i],temp,adj,newQuiet);
        }

        return temp;
    }
};