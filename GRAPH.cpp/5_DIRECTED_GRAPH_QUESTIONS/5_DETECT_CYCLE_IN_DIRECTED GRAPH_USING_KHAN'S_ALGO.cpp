// TOPO SORT OF KHAN ALGO IS USED IN DAG
// IF GRAPH IS DAG THEN TOPO SORT GIVES ALL THE N ELEMENTS : CYCLE IS NOT PRESENT
// IF GRAPH IS DIRECTED AND CYCLIC THEN TOPO SORT DOES NOT GIVE N ELEMNETS : CYCLE IS PRESENT

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indegree[V];
        memset(indegree,0,sizeof(indegree));
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size()==V) return false;
        else return true;
    }
};