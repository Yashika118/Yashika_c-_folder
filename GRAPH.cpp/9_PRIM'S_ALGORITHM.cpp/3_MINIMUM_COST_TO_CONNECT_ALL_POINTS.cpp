#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // typedef pair<int,int>P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(n,0);
        pq.push({0,0});  //wt,node
        int sum=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            if(!visited[node]){
                visited[node]=1;
                sum+=wt;
                for(auto it:adj[node]){
                    int adjNode=it.first;
                    int adjWt=it.second;
                    if(!visited[adjNode]){
                        pq.push({adjWt,adjNode});
                    }
                }
            }
        }

        return sum;
    }
};