//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>multisteps(100000,1e9);
        multisteps[start]=0;
        if(start == end) return 0;
        
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto it:arr){
                int num=(it*node)%100000;
                if(steps+1<multisteps[num]){
                    multisteps[num]=steps+1;
                    if(num==end) return multisteps[num];
                    q.push({steps+1,num});
                }
            }
        }
        
        return -1;
    }
};


