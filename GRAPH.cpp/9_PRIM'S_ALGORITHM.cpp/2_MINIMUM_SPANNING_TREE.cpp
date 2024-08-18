// USED TO FIND MINIMUM SPANNING TREE
// PRIM'S ALGORITHM
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis( V,0);
        // vector<pair<int,int>>MST(n-1);
        //{wt,node,parent}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
                pq.pop();
                
                // if(vis[node]==1) continue;
                // HERE WE CAN ADD MST ARRAY TO FIND EDGES OF MIN SPANNING TREE
                if(!vis[node]){
                    vis[node]=1;
                    sum=sum+wt;
                    for(auto it:adj[node]){
                        int adjNode=it[0];
                        int adjWt=it[1];
                        if(!vis[adjNode]){
                            pq.push({adjWt,adjNode});
                        }
                    }
                }
        }
        
        return sum;
    }
};
//TC: E LOG(V) + E LOG(V)= O(E LOG(V) )
//SC: O(E)

