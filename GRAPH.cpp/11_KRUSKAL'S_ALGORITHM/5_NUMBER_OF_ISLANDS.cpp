// NUMBER OF ISLANDS II --> ON LEETCODE
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int>parent,size;
    public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int visited[n][m];
        memset(visited,0,sizeof(visited));
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(visited[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            visited[row][col]=1;
            cnt++;
            
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            for(int ind=0;ind<4;ind++){
                int adjr=row+dr[ind];
                int adjc=col+dc[ind];
                if(adjr>=0 and adjr<n and adjc>=0 and adjc<m){
                    if(visited[adjr][adjc]==1){
                        int nodeNo=row*m+col;
                        int adjNodeNo=adjr*m+adjc;
                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};