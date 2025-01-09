#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            int maxFreq=0;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                maxFreq=max(maxFreq,mp[s[j]]);
                int changes=(j-i+1)-maxFreq;
                if(changes<=k){
                    maxlen=max(maxlen,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
    // TC:O(N^2)
    // SC:O(1)
};

// OPTIMAL SOL
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0,r=0;
        int maxlen=0;
        int maxFreq=0;
        int changes=0;
        map<int,int>mp;

        while(r<n){
            mp[s[r]]++;
            maxFreq=max(maxFreq,mp[s[r]]);
            changes=(r-l+1)-maxFreq;
            if(changes>k){
                mp[s[l]]--;
                maxFreq=0;
                l++;
            }
            if(changes<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;

    }
};