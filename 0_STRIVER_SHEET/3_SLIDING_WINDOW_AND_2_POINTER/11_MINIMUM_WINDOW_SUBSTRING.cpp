#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        int minlen=INT_MAX; int startInd=-1;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            int cnt=0;
            for(int j=0;j<m;j++){
                mp[t[j]]++;
            }
            for(int j=0;j<n;j++){
                if(mp[s[j]]>0){
                    cnt+=1;
                }
                mp[s[j]]--;
                
                if(cnt==m){
                    if(j-i+1<minlen){
                        minlen=j-i+1;
                        startInd=i;
                        break;
                    } 
                }
            }
        }
        return s.substr(startInd,minlen);
        // TC:O(N^2)
        // SC:O(256)
    }
    // kuch error h iss solution m
};


// OPTIMAL SOLUTION
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        map<char,int>mp;
        int cnt=0;
        int minlen=INT_MAX;
        int startInd=-1;
        int l=0,r=0;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        while(r<n){
            if(mp[s[r]]>0) cnt+=1;
            mp[s[r]]--;
            while(cnt==m){
                if(r-l+1 < minlen){
                    minlen=r-l+1;
                    startInd=l; 
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt-=1;
                }
                l++;
            }
            r++;
        }

        return startInd==-1 ? "" : s.substr(startInd,minlen);
    }
    // TC:O(2N)+O(M)
    // SC:O(256)
};