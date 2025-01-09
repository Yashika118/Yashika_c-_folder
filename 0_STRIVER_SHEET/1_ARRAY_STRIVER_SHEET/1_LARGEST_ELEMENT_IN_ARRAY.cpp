#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE  -->
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());  // QUICK SORT
        return arr[n-1];
    }
    // TC: N LOG N
};


// OPTIMAL SOLUTION --> O(N)
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(ans<arr[i]){
                ans=arr[i];
            }
        }
        return ans;
    }
};