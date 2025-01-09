#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
    // TC:O(n*m)
};

// BETTER APPROACH- BINARY SEARCH
class Solution {
public:
    bool findTarget(vector<int>arr,int n,int x){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x){
                return true;
            }
            else if(arr[mid]>x) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target and matrix[i][m-1]>=target){
                if(findTarget(matrix[i],m,target)) return true;
            }
        }
        return false;
    }
    // TC: O(n)+O(log 2 m)
};

// OPTIMAL APPROACH
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;          // or n-1
        int col=m-1;        // or 0
        while(row<n and col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }

        return false;
    }
    // TC:O(n+m)
};