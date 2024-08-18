#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> adj,string src,string dest,unordered_set<string>&visited,double product,double &ans){

        if(visited.find(src)!=visited.end()){ // src is already visited h 
            return;
        }

        visited.insert(src);  // if src is not visited then insert in set

        if(src==dest){
            ans=product;
            return;
        } 

        for(auto it : adj[src]){
            string v=it.first;
            double val=it.second;
            dfs(adj,v,dest,visited,product*val,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<n;i++){
            string u=equations[i][0]; //a
            string v=equations[i][1]; //b
            double val=values[i]; // 2.0

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }

        vector<double>result;
        for(auto it:queries){
            string src=it[0];
            string dest=it[1];

            double ans=-1.0;
            double product=1.0;

            if(adj.find(src)!=adj.end()){  // if src is available the loop works
                unordered_set<string>visited;
                dfs(adj,src,dest,visited,product,ans);
            }
            result.push_back(ans);
        }

        return result;

    }
};