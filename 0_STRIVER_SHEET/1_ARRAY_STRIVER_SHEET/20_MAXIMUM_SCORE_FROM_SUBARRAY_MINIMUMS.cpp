#include<bits/stdc++.h>
using namespace std;
// SUBARRAY MEANS --> CONTIGOUS PART OF ARR
// SUBSEQUENCE MEANS--> CONTIGOUS / NON-CONTIGOUS PART OF ARR

// BRUTE FORCE
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int n=arr.size();
        vector<int>v;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            v.push_back(arr[i]);
            for(int j=i+1;j<n;j++){
                int sum=0;
                v.push_back(arr[j]);
                sort(v.begin(),v.end());
                sum=sum+v[0]+v[1];
                maxi=max(maxi,sum);
            }
            v.clear();
        }
        
        return maxi;
    }
    // TC: 
};

// OPTIMAL SOLUTION
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int n=arr.size();
        int maxi=INT_MIN;
        int sum=0;
        
        for(int i=0;i<n-1;i++){
            sum=arr[i]+arr[i+1];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    // TC:O(N);
    // SC:O(1);
};






