//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// my solution
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int>dist(n,1e9);
        queue<int>q;
        dist[src]=0;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};



// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int dist[N];
        for(int i=0;i<N;i++){
            dist[i]=1e9;
        }
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i]!=1e9){
                ans[i]=dist[i];
            }
        }
        
        return ans;
    }
};

// or
// //{ Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function Template for C++
// class Solution {
//   public:
//     vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
//         // code here
//         vector<int>adj[N];
//         for(auto it:edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
        
//         vector<int>dist(N);
//         for(int i=0;i<N;i++){
//             dist[i]=1e9;
//         }
        
//         dist[src]=0;
//         queue<int>q;
//         q.push(src);
        
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
            
//             for(auto it:adj[node]){
//                 if(dist[node]+1<dist[it]){
//                     dist[it]=1+dist[node];
//                     q.push(it);
//                 }
//             }
            
//         }
        
//         for(int i=0;i<N;i++){
//             if(dist[i]==1e9){
//                 dist[i]=-1;
//             }
//         }
        
//         return dist;
//     }
// };


