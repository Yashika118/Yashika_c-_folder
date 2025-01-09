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
};

// BETTER APPROACH -BINARY SEARCH
class Solution {
public:
    bool findTarget(vector<int>arr,int n,int target){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
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
    // TC: O(n) + O(log 2 m)
};

// CONVERT 2D ARRAY IN 1D HYPOTHETICALLY
// (index)                   (coordinate)
//  5           ---->        (1,1)

//              (index/m)
//  index       -------->   row
//              (index%m)
//  index       -------->   col

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=(n*m)-1;

        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return false;
    }
    // TC:O(log base 2 (n*m))
};