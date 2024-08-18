// APPLICABLE FOR DIRECTED GRAPH ONLY
// COMPONENT IS STRONGLY CONNECTED IF ANY TWO NODES ARE REACHABLE TO EACH OTHER

// ALGO-->
// 1. SORT ALL THE EDGES ACC TO FINISHING TIME
// 2. REVERSE THE GRAPH
// 3. DO A DFS

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>>& adj,vector<int>&visited,stack<int>&st){
	    visited[node]=1;
	    for(auto it:adj[node]){
	        if(!visited[it]){
	            dfs(it,adj,visited,st);
	        }
	    }
	    st.push(node);
	}
	void dfs2(int node,vector<int>&visited, vector<int>adjT[]){
	    visited[node]=1;
	    for(auto it:adjT[node]){
	        if(!visited[it]){
	            dfs2(it,visited,adjT);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>visited(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        vector<int>adjT[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                scc++;
                dfs2(node,visited,adjT);
            }
        }
        
        return scc;
    }
};

// TC: 3*O(V+E)