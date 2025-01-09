#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][(n-1)-i]=matrix[i][j];
            }
        }
        
        matrix=ans;
    }
    // TC:O(N^2)
    // SC:O(N^2)
};


// OPTIMAL
// 1. TRANSPOSE MATRIX --> ROW BECOMES COL AND COL BECOMES ROW
    //  during tanspose diagonal elements remains at same position
    // remaining elements will be swap
// 2. REVERSE EVERY ROW
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // TRANSPOSE MATRIX
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reverse every row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


