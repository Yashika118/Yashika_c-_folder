//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 and col==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m ){
                    int neweffort=max(abs(heights[row][col]-heights[nrow][ncol]), diff);
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
            
            
        }
    }
};

//TC: E LOG(V)


