//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1]; // 1 based array or vector
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        
        vector<int>dist(n+1,1e9),parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        dist[1]=0;
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wei=it.second;
                
                if(dis+wei < dist[adjNode]){
                    dist[adjNode]=dis+wei;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode]=node;
                }
            }
            
        }
        if(dist[n]==1e9) return {-1};
        
        vector<int>path;
        int node=n;
        
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        path.insert(path.begin(),dist[n]);
        
        return path;
        
    }
};

//TC:O(N)