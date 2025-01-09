#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n=arr.size();
        int maxFruit=0;
        for(int i=0;i<n;i++){
            set<int>s;
            for(int j=i;j<n;j++){
                s.insert(arr[j]);
                if(s.size()<=2){
                    int len=j-i+1;
                    maxFruit=max(maxFruit,len);
                }
                else{
                    break;
                }
            }
        }
        return maxFruit;
    }
    // TC:O(N) * O(log 3) ~ O(N)*O(size of set) ~ O(N)*O(N) = O(N^2)
    // SC:O(3)
};


class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n=arr.size();
        int maxFruit=0;
        int l=0,r=0;
        map<int,int>mp;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0) mp.erase(mp[arr[l]]);
                    l++;
                }
            }
            if(mp.size()<=2){
                int len=r-l+1;
                maxFruit=max(maxFruit,len);
            }
            r++;
        }
        return maxFruit;
        // TC:O(N+N) -->RUNTIME ERROR
        // SC:O(3)
    }
};


// BETTER SOL
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n=arr.size();
        int maxFruit=0;
        int l=0,r=0;
        map<int,int>mp;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size()>2){
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0) mp.erase(mp[arr[l]]);
                    l++;
                
            }
            if(mp.size()<=2){
                int len=r-l+1;
                maxFruit=max(maxFruit,len);
            }
            r++;
        }
        return maxFruit;
        // TC:O(N)
        // SC:O(1)
    }// not working
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