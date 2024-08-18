#include<bits/stdc++.h>
using namespace std;
vector<int>bfs(int n,int m, vector<int>adj[]){
    int vis[n+1]={0};
    vis[1]=1;
    queue<int>q;
    q.push(1);

    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
    // SC: O(3N)=O(N) --->QUEUE,VIS,ANS
    // TC: O(N)--> queue + O(2E)--> for loop is running for all nodes = O(N)+O(2E)
}
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

    vector<int>answer=bfs(n,m,adj);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    
}