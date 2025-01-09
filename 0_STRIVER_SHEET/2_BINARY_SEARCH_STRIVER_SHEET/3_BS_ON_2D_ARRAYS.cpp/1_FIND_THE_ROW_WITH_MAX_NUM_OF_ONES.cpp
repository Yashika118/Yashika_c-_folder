#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int ind=-1;
        int maxCount=0;
        
        for(int i=0;i<n;i++){
            int cntRow=0;
            for(int j=0;j<m;j++){
                cntRow+=arr[i][j];
            }
            if(maxCount<cntRow){
                maxCount=cntRow;
                ind=i;
            }
        }
        
        return ind;
    }
    // TC:O(n*m)
    // SC:O(1)
};


// BINARY SEARCH
class Solution {
  public:
    int lowerBound(vector<int>arr,int n,int x){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int cnt_max=0;
        int ind=-1;
        for(int i=0;i<n;i++){
            int cnt_ones=m-lowerBound(arr[i],m,1);
            if(cnt_ones>cnt_max){
                cnt_max=cnt_ones;
                ind=i;
            }
        }
        
        return ind;
    }
    // TC: O(n* log 2 m)
};