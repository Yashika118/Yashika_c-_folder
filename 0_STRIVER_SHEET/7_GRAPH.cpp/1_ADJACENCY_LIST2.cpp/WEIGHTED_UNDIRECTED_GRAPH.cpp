#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=0;i<m;i++){
        cout<<i<<"-->";
        for(int j=0;j<adj[i].size();j++){
            cout<<"("<<adj[i][j].first<<",";
            cout<<adj[i][j].second<<")";
        }
        cout<<endl;
    }

}