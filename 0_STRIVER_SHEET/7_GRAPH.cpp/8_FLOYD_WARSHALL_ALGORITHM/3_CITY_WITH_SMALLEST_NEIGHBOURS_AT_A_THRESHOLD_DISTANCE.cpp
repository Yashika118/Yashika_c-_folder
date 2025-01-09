//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>>matrix(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            matrix[it[0]][it[1]]=it[2];
            matrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX){
                        continue;
                    }
                    
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        
        int cntcity=n;
        int citynum=-1;
        
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(matrix[city][adjcity]<=distanceThreshold){
                    cnt++;
                }
            }
            
            if(cnt<=cntcity){
                cntcity=cnt;
                citynum=city;
            }
        }
        return citynum;
    }
};

// ALSO DO IT WITH DIJKSTRA ALGO