#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        int maxlen=0;
        int len=0;
        
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==0){
                    len=j-i+1;
                    maxlen=max(maxlen,len);
                }
            }
        }
        
        return maxlen;
    }
    // TC:O(N^2)
};

// BETTER SOLUTION
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        int maxlen=0;
        map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxlen=i+1;
            }
            else{
                int rem=sum-0;
            
                if(mp.find(rem)!=mp.end()){
                    int len=i-mp[sum];
                    maxlen=max(maxlen,len);
                }
                else{
                    mp[sum]=i;
                }
            }
        }
        return maxlen;
    }
};