// (min dist between cows ) is max
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
bool canWePlace(vector<int> &stalls,int dist,int cows){
    int n=stalls.size();
    int cntCows=1;
    int last=stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i]-last >= dist){
            cntCows++;
            last=stalls[i];
        }
    }
    if(cntCows>=cows){
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int maxDistance=stalls[n-1]-stalls[0];

    for(int i=1;i<=maxDistance;i++){
        if(canWePlace(stalls,i,k)){
            continue;
        }
        else{
            return i-1;
        }
    }

    return 0;
    // TC: O(maxDistance) * O(n)
    // SC: O(1)
}


// OPTIMAL SOL
bool canWePlace(vector<int> &stalls,int cows,int dist){
    int n=stalls.size();
    int last=stalls[0];
    int cntCows=1;

    for(int i=1;i<n;i++){
        if(stalls[i]-last >= dist){
            cntCows++;
            last=stalls[i];
        }
    }
    if(cntCows>=cows){
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int maxDistance=stalls[n-1]-stalls[0];
    
    int low=0;
    int high=maxDistance;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;

        if(canWePlace(stalls,k,mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
}