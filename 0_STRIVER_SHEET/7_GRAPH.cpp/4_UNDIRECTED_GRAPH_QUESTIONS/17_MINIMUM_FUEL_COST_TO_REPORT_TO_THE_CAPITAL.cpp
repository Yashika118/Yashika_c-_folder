#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long total_fuel;
    long long dfs(int node,int parent,vector<vector<int>>&adj,int &seats){
        int people=1;
        for(auto child:adj[node]){
            if(child!=parent){
                people+=dfs(child,node,adj,seats);
            }
        }
        if(node!=0)
            total_fuel+=ceil((double)people/seats);
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        total_fuel=0;
        dfs(0,-1,adj,seats);
        return total_fuel;
    }
};