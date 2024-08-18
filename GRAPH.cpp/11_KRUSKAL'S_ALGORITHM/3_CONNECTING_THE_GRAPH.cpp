//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);  // Path compression
    }

    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            
            if(ds.findUPar(u)==ds.findUPar(v)){
                cntExtras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        
        int cntComp=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                cntComp++;
            }
        }
        
        int ans=cntComp-1;
        if(cntExtras>=ans){
            return ans;
        }
        
        return -1;
    }
};

