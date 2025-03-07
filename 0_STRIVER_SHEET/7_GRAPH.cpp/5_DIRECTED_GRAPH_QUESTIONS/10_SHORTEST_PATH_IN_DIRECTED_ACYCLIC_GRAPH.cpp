// 1. DO A TOPO SORT ON THE GRAPH
// 2. TAKE THE NODE OUT OF STACK AND RELAX THE EDGES  


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
     void toposort(int node,vector<pair<int,int>>adj[],int visited[],stack<int>&s,int N){
         visited[node]=1;
         for(auto it:adj[node]){
             int v=it.first;
             if(!visited[v]){
                 toposort(v,adj,visited,s,N);
             }
         }
             s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        
            for(int i=0;i<M;i++){
                int u=edges[i][0];
                int v=edges[i][1];
                int wt=edges[i][2];
                
                adj[u].push_back({v,wt});
            }
            //toposort
            int visited[N];
            memset(visited,0,sizeof(visited));
            stack<int>s;
            
            for(int i=0;i<N;i++){
                if(!visited[i]){
                    toposort(i,adj,visited,s,N);
                }
            }
            
            
            vector<int>dist(N);
            for(int i=0;i<N;i++){
                dist[i]=1e9;
            }
            // int src=0;
            dist[0]=0;
            
            while(!s.empty()){
                int node=s.top();
                s.pop();
                
                for(auto it:adj[node]){
                    int v=it.first;
                    int wt=it.second;
                    
                    if(dist[node]+wt <dist[v]){
                        dist[v]=dist[node]+wt;
                    }
                }
            }
            
            for(int i=0;i<N;i++){
                if(dist[i]==1e9){
                    dist[i]=-1;
                }
            }
            
            return dist;
            //tc: O(N+M);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends


// my solution
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
        }
        
        int src=0;
        vector<int>dist(V,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            int d=dist[node];
            
            for(auto it:adj[node]){
                int v=it.first;
                int w=it.second;
                
                if(d+w < dist[v]){
                    q.push(v);
                    dist[v]=d+w;
                }
            }
            
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};