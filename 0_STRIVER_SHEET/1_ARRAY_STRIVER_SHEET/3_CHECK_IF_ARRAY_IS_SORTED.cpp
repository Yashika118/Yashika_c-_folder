#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        vector<int>v=arr;
        sort(v.begin(),v.end());
        for(int i=0;i<arr.size();i++){
            if(v[i]==arr[i]) continue;
            else{
                return false;
            }
        }
        
        return true;
    }

    // TC: O(N *LOG N) + O(N)
};


// OPTIMAL SOLUTION
class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<=arr[i+1]) continue;
            else{
                return false;
            }
        }
        return true;
    }
    // TC:O(N)
};