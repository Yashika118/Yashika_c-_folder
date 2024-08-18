//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long,long>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        vector<long long>time(n,LLONG_MAX),ways(n,0);
        pq.push({0,0});
        time[0]=0;
        ways[0]=1;
        int mod=(int)(1e9+7);
        // int mod=1000000000+7;
        
        while(!pq.empty()){
            long long t=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            
            
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long adjtime=it.second;
                
                if(t+adjtime <time[adjNode]){
                    time[adjNode]=(t+adjtime);
                    pq.push({time[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(t+adjtime==time[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

