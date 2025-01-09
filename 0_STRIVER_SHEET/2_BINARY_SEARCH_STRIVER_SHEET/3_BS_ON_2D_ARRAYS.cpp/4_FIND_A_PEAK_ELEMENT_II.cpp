#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=-1,down=-1,left=-1,right=-1;
                if(i-1>=0) up=mat[i-1][j];
                if(i+1<n) down=mat[i+1][j];
                if(j-1>=0) left=mat[i][j-1]; 
                if(j+1<m) right=mat[i][j+1];
                if(mat[i][j]>up and mat[i][j]>down and mat[i][j]>left and mat[i][j]>right){
                    return{i,j};
                }
                
            }
        }

        return {-1,-1};
    }
    // TC:O(n*m*4)
};

// by finding largest element in matrix
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int max_ele=INT_MIN;
        int row=-1;
        int col=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]>max_ele){
                    max_ele=mat[i][j];
                    row=i;
                    col=j;
                }
            }
        }

        return {row,col};
    }
    // TC:O(n*m)
};


// OPTIMAL SOL-BINARY SEARCH
class Solution {
public:
    int indexOfMaxEle(vector<vector<int>>& mat,int n,int m,int col){
        int maxVal=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxVal){
                maxVal=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=indexOfMaxEle(mat,n,m,mid);
            int left=mid-1 >=0 ? mat[row][mid-1] : -1;
            int right=mid+1 < m ? mat[row][mid+1] : -1;
            if(mat[row][mid] >left and mat[row][mid]>right  ){
                return {row,mid};
            }
            else if(mat[row][mid] <left ) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
    // TC: O(log 2 m * n)
};