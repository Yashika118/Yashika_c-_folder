// c1 --->component 1
// c2 --> component 2 and so on 

// c1           c2          c3          c4 .... cn
// n1 stones    n2          n3          n4 ..... n
// (n1-1)   +   (n2-1) +    (n3-1) +    (n4-1)....
// (n1+n2+n3+n4+.....) -1-1-1-1..
// (n1+n2+n3+n4......)-(1+1+1+1..)
//  n - no.of components    ---> ans


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        // ---> striver code
        // int maxRow=0;
        // int maxCol=0;
        // for(auto it:stones){
        //     maxRow=max(maxRow,it[0]);
        //     maxCol=max(maxCol,it[1]);
        // }
        // DisjointSet ds(maxRow+maxCol+2);
        // unordered_map<int,int>stoneNodes;
        // for(auto it:stones){
        //     int nodeRow=it[0];
        //     int nodeCol=it[1]+maxRow+1;
        //     ds.unionBySize(nodeRow,nodeCol);
        //     stoneNodes[nodeRow]=1;
        //     stoneNodes[nodeCol]=1;
        // }
        
        // int cnt=0;
        // for(auto it:stoneNodes){
        //         if(ds.findUPar(it.first)==it.first){
        //             cnt++;
        //         }
        // }
        
        // return n-cnt;
        // ---> striver code

        DisjointSet ds(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                    ds.unionBySize(i, j);
            }
        }
        int comp = 0;
        for(int i = 0;i<n;i++)
            if(ds.parent[i] == i) comp++;
        return n - comp;
    }
};
