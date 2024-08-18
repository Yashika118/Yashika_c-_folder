#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int maxSize=0;
        int node=-1;
        for(int i=0;i<=n;i++){
            int count=0;
            for(auto it:adj[i]){
                count++;
            }
            if(maxSize<count){
                maxSize=max(maxSize,count);
                node=i;
            }
            
        }
        return node;
    }
};