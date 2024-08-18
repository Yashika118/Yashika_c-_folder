// USED TO FIND SHORTEST PATH
// THIS ALGO IS NOT CONSIDERED FOR NEGATIVE WEIGH CYCLE 
// BECAUSE OF INFINITE LOOP BECAUSE DIST REDUCES EVERYTIME IN NEGATIVE
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  // keep min dist at top
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        
        dist[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edgeWeight=it[1];
                
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
    }
};
// TC: O(E*LOG(V));
// 1 vertex can have (V-1) edges=ne
// O(V*(log(heap size)+ ne* log(heap size)))
// O(V* (heap size)*(ne+1))
// O(V*V*log(heap size))
// O(V^2 * log(heap size))
// O(V^2 * log(V^2))
// O(V^2 * 2* log(V))
// O(E*2*log(V))
//O(E*LOG(V))

