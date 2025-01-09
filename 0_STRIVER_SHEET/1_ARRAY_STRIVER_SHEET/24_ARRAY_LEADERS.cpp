#include<bits/stdc++.h>
using namespace std;

// BETTER SOLUTION
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int>ans;
        int flag=0;
        for(int i=0;i<n-1;i++){
            flag=0;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    flag=1;
                    break;
                }
                
            }
            if(flag==0){
                ans.push_back(arr[i]);
            }
        }
        // LAST ELEMENT WILL ALWAYS BE THE LEADER
        ans.push_back(arr[n-1]);
        return ans;
    }
    // TC:O(N^2)
    // SC:O(N)
};

// OPTIMAL SOLUTION
class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int>ans;
        
        int maxi=INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,arr[i]);
            if(arr[i]>=maxi){
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

        // TC: O(N)+O(N)
        // SC: O(N)
    }
};