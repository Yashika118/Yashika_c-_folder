#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // node which large no. of outdegree/indegree and assign it large val 
        // then it gives maximum sum
        vector<int>outDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                outDegree[it]++;
            }
        }
        // priority_queue<int,vector<int>,greater<int>>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            pq.push({outDegree[i],i});
        }
        vector<int>v(n+1,-1);
        int count=1;
        while(!pq.empty()){
            int degree=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            v[node]=count;
            count++;
        }
        vector<int>importance;
        for(auto it:roads){
           int sum=v[it[0]]+v[it[1]];
           importance.push_back(sum); 
        }
        long long sumTotal=0;
        for(int i=0;i<importance.size();i++){
            sumTotal+=importance[i];
        }
        return sumTotal;
    }
};