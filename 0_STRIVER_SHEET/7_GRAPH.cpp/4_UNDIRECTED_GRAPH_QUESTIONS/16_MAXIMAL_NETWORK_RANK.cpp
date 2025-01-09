#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int max_Rank=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int conn_i=adj[i].size();
                int conn_j=adj[j].size();
                int conn_tot=conn_i+conn_j;
                for(auto it:adj[i]){
                    if(it==j){
                        conn_tot=conn_tot-1;
                    }
                }
                max_Rank=max(max_Rank,conn_tot);
            }
        }
        return max_Rank;
    }
};