#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int result=-1;
    void dfs(int u,vector<int>&vis,vector<int>&pathvis,vector<int> &len,vector<int>&edges){
        if(u!=-1){
            vis[u]=1;
            pathvis[u]=1;

            int v=edges[u];
            if(v!=-1 and !vis[v]){
                len[v]=len[u]+1;
                dfs(v,vis,pathvis,len,edges);
            }
            else if(v!=-1 and pathvis[v]){
                result=max(result,len[u]-len[v]+1);
                
            }

            pathvis[u]=0;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>len(n,1);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,len,edges);
            }
        }
        return result;
    }
};


// BRUTE FORCE
// class Solution {
// public:
//     bool dfs(int src,int node,vector<int>&vis,vector<int>&pathvis,vector<int>adj[],vector<int>&edges,int &len){
//         vis[node]=1;
//         pathvis[node]=1;
//         len=len+1; //1 2 3

//         cout<<node<<" " <<len<<endl;

//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 if(dfs(src,it,vis,pathvis,adj,edges,len)==true){
//                     return true;
//                 }
//             }
//             if(pathvis[it]){
//                 if(src==it){
//                     cout<<"yes"<<endl;
//                     return true;
//                 }
//                 return false;
//             }
//         }
//         return false;

//     }
//     int longestCycle(vector<int>& edges) {
//         int n=edges.size();
//         vector<int>adj[n];
//         for(int i=0;i<n;i++){
//             if(edges[i]!=-1){
//                 adj[i].push_back(edges[i]);
//             }
//         }

        
//         int maxlen=-1;
//         for(int i=0;i<n;i++){
//             vector<int>vis(n,0);
//             vector<int>pathvis(n,0);

//             int len=0; 
//             if(!vis[i]){
//                 if(dfs(i,i,vis,pathvis,adj,edges,len)){
//                     maxlen=max(len,maxlen);
//                     cout<<len<<"="<<endl;
//                 }
//             }
//         }

//         return maxlen;
//     }
// };


// // another sol
// class Solution {
// public:
//     bool dfs(int src,int node,vector<int>&vis,vector<int>&pathvis,vector<int>&edges,int &len){
//         vis[node]=1;
//         pathvis[node]=1;
//         len=len+1; //1 2 3

//         cout<<node<<" " <<len<<endl;
//             if(edges[node]!=-1){
//                 if(!vis[edges[node]]){
//                 if(dfs(src,edges[node],vis,pathvis,edges,len)==true){
//                     return true;
//                 }
//             }
//             if(pathvis[edges[node]]){
//                 if(src==edges[node]){
//                     cout<<"yes"<<endl;
//                     return true;
//                 }
//                 return false;
//             }
//             }
        
//         return false;

//     }
//     int longestCycle(vector<int>& edges) {
//         int n=edges.size();
//         int maxlen=-1;
//         for(int i=0;i<n;i++){
//             vector<int>vis(n,0);
//             vector<int>pathvis(n,0);

//             int len=0; 
//             if(!vis[i]){
//                 if(dfs(i,i,vis,pathvis,edges,len)){
//                     maxlen=max(len,maxlen);
//                     cout<<len<<"="<<endl;
//                 }
//             }
//         }

//         return maxlen;
//     }
// };
