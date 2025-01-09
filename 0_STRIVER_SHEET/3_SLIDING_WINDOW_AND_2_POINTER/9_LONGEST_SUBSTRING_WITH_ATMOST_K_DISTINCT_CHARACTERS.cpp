#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE

// int func(string s, int k){
//     int n=s.length();
//     int maxlen=0;
//     map<char,int>mp;
//     for(int i=0;i<n;i++){
//         mp.clear();
//         for(int j=i;j<n;j++){
//             mp[s[j]]++;
//             if(mp.size()<=k){
//                 maxlen=max(maxlen,j-i+1);
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return maxlen;
//     // TC:O(N^2)*log(26)
//     // SC:O(26)
// }


// BETTER SOL

int func(string s, int k){
    int n=s.length();
    int maxlen=0;
    map<char,int>mp;
    int l=0,r=0;
    while(r<n){
        mp[s[r]]++;
        while(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(mp[s[l]]);
            }
            l++;
        }
        if(mp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    // TC:O(N)+O(N)+O(256)
    // SC:O(256)
}

// OPTIMAL SOL
int func(string s, int k){
    int n=s.length();
    int maxlen=0;
    map<char,int>mp;
    int l=0,r=0;
    while(r<n){
        mp[s[r]]++;
        if(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(mp[s[l]]);
            }
            l++;
        }
        if(mp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
    // TC:O(N)+O(256)
    // SC:O(256)
}