#include<bits/stdc++.h>
using namespace std;

// PRINT NODES
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<vector<int>>& adj,vector<int>&visited,vector<int>&ans){
        visited[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<int>visited(n,0);
        
        dfs(0,adj,visited,ans);
        
        return ans;
    }
};




// same
void dfs(int node,vector<int>adj[],int vis[],vector<int>&ans){
    vis[node]=1;
    ans.push_back(node);

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}

vector<int>dfs(int n,vector<int>adj[]){
    int vis[n+1]={0};
    vector<int>ans;
    int start=1;

    dfs(start,adj,vis,ans);
    return ans;

}
//SC: O(N)+O(N)+O(N)=O(N)
//TC: O(N)+O(2E)= FUNC runs for every node + FOR LOOP runs for neighbour of every node 
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>answer=dfs(n, adj);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}