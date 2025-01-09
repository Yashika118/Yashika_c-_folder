#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&visited,int &count){
        count++;
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,count);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
            for(auto it:edges){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        vector<int>visited(n,0);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count=0;
                dfs(i,adj,visited,count);
                q.push({i,count}); //0,3 3,2 5,1
            }
        }
        vector<int>vis(n,0);
        int noOfComp=0;
        while(!q.empty()){
            int node=q.front().first;
            int maxNode=q.front().second;
            q.pop();
            queue<int>newq;
            newq.push(node);
            vis[node]=1;
            int flag=0;
            while(!newq.empty()){
                int a=newq.front();
                newq.pop();
                if(adj[a].size()!=maxNode-1){
                    flag=1;
                    break;
                }
                for(auto it:adj[a]){
                    if(!vis[it]){
                        newq.push(it);
                        vis[it]=1;
                    }
                }
            }
            if(flag==0) noOfComp++;
        }
        return noOfComp ;
    }
};