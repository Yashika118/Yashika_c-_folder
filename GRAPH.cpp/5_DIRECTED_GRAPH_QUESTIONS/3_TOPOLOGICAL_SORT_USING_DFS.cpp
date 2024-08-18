//{ Driver Code Starts
//TOPOLOGICAL SORT is done for DAG(DIRECTED ACYCLIC GRAPH)
// linear ordering of vertices if there is an edge between u & v ,u appears before v int that ordering 
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int node, vector<int> adj[], int visited[], stack<int> &st)
    {
        visited[node] = 1;
        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                dfs(x, adj, visited, st);
            }
        }
            st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        int visited[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//SC :O(N);
//TC: V +E


//
// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution
// {
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// 	void topo(int node,vector<int>adj[],vector<int>&visited,stack<int>&st){
// 	    visited[node]=1;
// 	    for(auto it:adj[node]){
// 	        if(!visited[it]){
// 	            topo(it,adj,visited,st);
// 	        }
// 	    }
// 	   st.push(node);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    stack<int>st;
// 	    vector<int>visited(V,0);
// 	    vector<int>ans;
	    
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i]){
// 	            topo(i,adj,visited,st);
// 	        }
// 	    }
	    
// 	    while(!st.empty()){
// 	        ans.push_back(st.top());
// 	        st.pop();
// 	    }
	    
// 	    return ans;
// 	}
// };


