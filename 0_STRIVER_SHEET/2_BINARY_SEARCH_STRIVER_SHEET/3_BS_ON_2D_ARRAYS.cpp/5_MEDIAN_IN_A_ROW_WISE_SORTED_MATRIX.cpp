#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        vector<int>v;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v[(R*C)/2];
    }
    // TC:(n*m) + (n*m*log(n*m))
};

// OPTIMAL SOL
class Solution{   
public:
    int upperBound(vector<int>&arr,int x,int n){
        int low=0, high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>x){
                ans=mid;
                // look for small index on left
                high=mid-1;
            }
            else{
                // look for right
                low=mid+1;
            }
        }
        return ans;
    }
    int countSmallEqual(vector<vector<int>> &matrix,int n,int m,int x){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upperBound(matrix[i],x,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        int low=INT_MAX; int high=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][m-1 ]);
        }
        
        int req=(n*m)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smallEqual=countSmallEqual(matrix,n,m,mid);
            if(smallEqual<=req) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
