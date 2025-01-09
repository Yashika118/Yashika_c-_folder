// leetcode
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int i, vector<int> adj[], int vis[])
    {
        vis[i] = 1;
        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                dfs(x, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int s = isConnected.size();
        vector<int> adj[s];
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        // for(int i=0;i<s;i++){
        // cout<<i+1<<"-->";
        // for(auto x:adj[i]){
        // cout<<x+1<<" ";
        // }
        // cout<<endl;
        // }

        int visited[s];
        memset(visited, 0, sizeof(visited));
        int count = 0;
        for (int i = 0; i < s; i++)
        {
            if (visited[i] != 1)
            {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};

//USING BFS
// class Solution {
// public:
//     void bfs(int node,vector<int>adj[],vector<int>&visited){
//         queue<int>q;
//         q.push(node);
//         visited[node]=1;

//         while(!q.empty()){
//             int val=q.front();
//             q.pop();
//              for(auto it:adj[val]){
//                 if(!visited[it]){
//                     bfs(it,adj,visited);
//                 }
//              }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         int m=isConnected[0].size();
//         vector<int>adj[n]; 
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(isConnected[i][j]==1 and i!=j){
//                     adj[i].push_back(j);
//                     // adj[j].push_back(i);
//                 }
//             }
//         }

//         vector<int>visited(n,0);
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//             cnt++;
//             bfs(i,adj,visited);

//             }
//         }
//         return cnt;
//     }
// };