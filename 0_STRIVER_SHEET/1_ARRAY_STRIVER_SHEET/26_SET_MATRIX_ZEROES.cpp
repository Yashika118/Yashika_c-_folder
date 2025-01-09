#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE

        //  STRIVER
class Solution {
public:
    void markRow(int row,vector<vector<int>>& matrix,int m){
        for(int j=0;j<m;j++){
            if(matrix[row][j]!=0){
                matrix[row][j]=-1;
            }
        }
    }
    void markCol(int col,vector<vector<int>>& matrix,int n){
        for(int i=0;i<n;i++){
            if(matrix[i][col]!=0){
                matrix[i][col]=-1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markRow(i,matrix,m);
                    markCol(j,matrix,n);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
        
        return;
        // TC: O(N * M * (N + M)) + O(N * M) 
    }
};


        // MY SOL
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>ans=matrix;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<m;k++){
                        ans[i][k]=0;
                    }
                    for(int l=0;l<n;l++){
                        ans[l][j]=0;
                    }
                }
            }
        }

        matrix=ans;
        return;
        // TC: O( n * m * (m+n))
        // SC: O(n * m)
    }
};



// BETTER SOLUTION
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1 or col[j]==1){
                    matrix[i][j]=0;
                }
            }
            
        }
        return;
        // TC: O( 2(n * m ) ) 
        // SC: O(n) +O(m)
    }
};


// OPTIMAL
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // int col[m]={0};  -> matrix[0][...]
        // int row[n]={0};  -> matrix[...][0]
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    // mark the ith row
                    matrix[i][0]=0;
                    // mark the jth col 
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }

                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    // check for col & row
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }

        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
       
        return;
        // TC:O(2*(N*M))
        // SC:O(1)
    }
};