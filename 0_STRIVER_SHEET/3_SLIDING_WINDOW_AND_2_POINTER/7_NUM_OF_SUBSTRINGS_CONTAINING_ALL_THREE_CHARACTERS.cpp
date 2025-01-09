#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int count=0;
        map<int,int>mp;
        // 0 --> a
        // 1 --> b
        // 2 --> c
        for(int i=0;i<n;i++){
            mp[0]=0;
            mp[1]=0;
            mp[2]=0;
            for(int j=i;j<n;j++){
                mp[s[j]-'a']=1;
                if(mp[0]+mp[1]+mp[2] == 3){
                    count++;
                }
            }
        }
        return count;
    }
    // TC:O(N^2)
    // SC:O(3)
};

// BETTER SOL
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int count=0;
        map<int,int>mp;
        // 0 --> a
        // 1 --> b
        // 2 --> c
        for(int i=0;i<n;i++){
            mp[0]=0;
            mp[1]=0;
            mp[2]=0;
            for(int j=i;j<n;j++){
                mp[s[j]-'a']=1;
                if(mp[0]+mp[1]+mp[2] == 3){
                    count=count+(n-j);
                    break;
                }
            }
        }
        return count;
    }
};

// OPTIMAL SOL
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        map<int,int>lastSeen;
        lastSeen[0]=-1;
        lastSeen[1]=-1;
        lastSeen[2]=-1;
        int count=0;

        for(int i=0;i<n;i++){
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 and lastSeen[1]!=-1 and lastSeen[2]!=-1){
                count+=(1+min(min(lastSeen[0],lastSeen[1]),lastSeen[2]));
            }
        }
        return count;
    }
    // TC:O(N)
    // SC:O(1)
};
