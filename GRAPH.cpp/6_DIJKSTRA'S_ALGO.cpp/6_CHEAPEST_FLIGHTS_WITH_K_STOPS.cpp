//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        // {stop,{src,cost}}
        q.push({0,{src,0}});
        vector<int>mincost(n,1e9);
        mincost[src]=0;
        
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            
            if(stop>K) continue;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjcost=it.second;
                
                if(cost+adjcost<mincost[adjNode] and stop<=K){
                    mincost[adjNode]=cost+adjcost;
                    q.push({stop+1,{adjNode,mincost[adjNode]}});
                }
                
            }
        }
        
        if(mincost[dst]==1e9) return -1;
        return mincost[dst];
        
    }
};

//TC: E*LOG(V)