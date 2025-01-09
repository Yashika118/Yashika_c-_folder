//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        q.push({0,{source.first,source.second}});
        dist[source.first][source.second]=0;
        
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            
                    if(row==destination.first and col==destination.second){
                        return dist[row][col];
                    }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        
        return -1;
    }
};


