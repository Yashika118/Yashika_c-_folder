//{ Driver Code Starts
// Initial Template for C++

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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,1,0,0};
                int dc[]={0,0,-1,1};
                for(int ind=0;ind<4;ind++){
                    int nrow=row+dr[ind];
                    int ncol=col+dc[ind];
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==1){
                        int nodeNo=row*n+col;
                        int adjNodeNo=nrow*n+ncol;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        
        int maxSize=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,1,0,0};
                int dc[]={0,0,-1,1};
                set<int>components;
                for(int ind=0;ind<4;ind++){
                    int nrow=row+dr[ind];
                    int ncol=col+dc[ind];
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n    ){
                        if(grid[nrow][ncol]==1){
                            components.insert(ds.findUPar(nrow*n+ncol));
                        }
                    }
                }
                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }
                    maxSize=max(maxSize,sizeTotal+1);
            }
        }

        for(int cellNo=0;cellNo<n*n;cellNo++){
            maxSize=max(maxSize,ds.size[ds.findUPar(cellNo)]);
        }
        return maxSize;
        
    }
};

// MY SOLUTION
// //{ Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// // User function Template for C++
// class DisjointSet{
//     public:
//     vector<int>parent,size;
//     DisjointSet(int n){
//         parent.resize(n+1,0);
//         size.resize(n+1,0);
//         for(int i=0;i<n;i++){
//             parent[i]=i;
//             size[i]=1;
//         }
//     }

//     int findUPar(int node){
//         if(node==parent[node]){
//             return node;
//         }
//         return parent[node]=findUPar(parent[node]);  // Path compression
//     }

//     void unionBySize(int u, int v){
//         int ulp_u=findUPar(u);
//         int ulp_v=findUPar(v);
//         if(ulp_u==ulp_v){
//             return;
//         }
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }
//     }
// };
// class Solution {
//   public:
//     int MaxConnection(vector<vector<int>>& grid) {
//         // code here
//         int n=grid.size();
//         DisjointSet ds(n*n);
//         int delrow[]={-1,1,0,0};
//         int delcol[]={0,0,-1,1};
//         for(int row=0;row<n;row++){
//             for(int col=0;col<n;col++){
//                 if(grid[row][col]==1){
//                     for(int i=0;i<4;i++){
//                         int nrow=row+delrow[i];
//                         int ncol=col+delcol[i];
//                         if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==1){
//                             int nodeNo=row*n+col;
//                             int adjNodeNo=nrow*n+ncol;
//                             ds.unionBySize(nodeNo,adjNodeNo);
//                         }
//                     }   
//                 }
//             }
//         }
//         int maxSize=0;
//         for(int row=0;row<n;row++){
//             for(int col=0;col<n;col++){
//                 if(grid[row][col]==0){
//                     set<int>components;
//                     for(int i=0;i<4;i++){
//                         int nrow=row+delrow[i];
//                         int ncol=col+delcol[i];
//                         if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==1){
//                             int adjNodeNo=nrow*n+ncol;
//                             components.insert(ds.findUPar(adjNodeNo));
//                         }
//                     }       
//                     int sizeTotal=0;
//                     for(auto it:components){
//                         sizeTotal+=ds.size[it];
//                     }
//                     maxSize=max(maxSize,sizeTotal+1);
//                 }
//             }
//         }     
//         for(int cellNo=0;cellNo<n*n;cellNo++){
//                 maxSize=max(maxSize, ds.size[ds.findUPar(cellNo)]);         
//         }  
//         return maxSize;
//     }
// };


