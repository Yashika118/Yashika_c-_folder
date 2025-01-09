#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(n,-1);

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};