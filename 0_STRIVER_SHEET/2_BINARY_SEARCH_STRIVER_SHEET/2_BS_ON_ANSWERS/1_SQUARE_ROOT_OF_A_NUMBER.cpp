#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        int ans=1;
        for(int i=1;i<=n;i++){
            if((i*i) <= n){
                ans=i;
            }else{
                break;
            }
        }
        
        return ans;
    }
    // TC:O(N) -->INTERVIEWER WILL NOT HAPPY WITH THIS
};



// USING BINARY SEARCH
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        int low=1; int high=n;
        int ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            
            if( (mid*mid)==n) return mid;
            else if((mid*mid) >n){
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        
        return ans;
    }
};

// binary search on ans apply when we know the range of array