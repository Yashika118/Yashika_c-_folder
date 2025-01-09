#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE USING HASHMAP
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            // for(auto it:mp){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            for(int j=i;j<n;j++){
                if(mp[s[j]]==1) break;
                int len=j-i+1;
                // cout<<i<<" "<<j<<endl;
                maxlen=max(len,maxlen);
                mp[s[j]]=1;
            }
        }
        return maxlen;
    }
    // TC:O(N*N)
    // SC:O(256)
};


// OPTIMAL SOL
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        map<int,int>mp;
        int l=0,r=0;
        int maxlen=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            mp[s[r]]=r;
            r++;
        }

        return maxlen;
        // TC:O(n)
        
    }
};