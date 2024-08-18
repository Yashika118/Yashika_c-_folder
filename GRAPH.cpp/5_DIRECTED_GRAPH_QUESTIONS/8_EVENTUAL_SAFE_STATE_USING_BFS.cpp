// USING TOPOLOGICAL SORT

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int indegree[V];
        memset(indegree,0,sizeof(indegree));
        vector<int>newadj[V];
        
        for(int i=0;i<V;i++){
            //reverse the graph
            for(auto it:adj[i]){
                newadj[it].push_back(i);
                //indegree[i]++;
                
            }
        }
        
        for(int i=0;i<V;i++){
            for(auto it:newadj[i]){
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
            
            for(auto it:newadj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
