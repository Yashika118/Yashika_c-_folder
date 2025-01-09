//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
        //code here

        vector<int>adj[V];
	    for(auto it:prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
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
        
        if(ans.size()==V) return ans;
        return {};
    }
};

// COURSE SCHEDULE II --> ON LEET CODE