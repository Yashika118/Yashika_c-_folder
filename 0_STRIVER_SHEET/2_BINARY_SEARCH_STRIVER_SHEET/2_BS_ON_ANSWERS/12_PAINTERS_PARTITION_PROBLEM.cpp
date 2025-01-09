#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
bool isJobDone(vector<int> &boards,int k,int time){
    int cntPainters=1;
    int totTime=0;
    for(int i=0;i<boards.size();i++){
        if(totTime+boards[i]<=time){
            totTime+=boards[i];
        }
        else{
            cntPainters++;
            totTime=boards[i];
        }
    }
    if(cntPainters<=k){
        return true;
    }
    return false;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n=boards.size();
    int maxtime=INT_MIN; int maxTotTime=0;
    for(int i=0;i<n;i++){
        maxtime=max(maxtime,boards[i]);
        maxTotTime+=boards[i];
    }

    for(int i=maxtime;i<=maxTotTime;i++){
        if(isJobDone(boards,k,i)){
            return i;
        }
    }
    return -1;
}


// OPTIMAL SOL
#include<bits/stdc++.h>
bool isJobDone(vector<int> &boards,int k,int time){
    int cntPainters=1;
    int totTime=0;
    for(int i=0;i<boards.size();i++){
        if(totTime+boards[i]<=time){
            totTime+=boards[i];
        }
        else{
            cntPainters++;
            totTime=boards[i];
        }
    }
    if(cntPainters<=k){
        return true;
    }
    return false;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n=boards.size();
    int maxtime=INT_MIN; int maxTotTime=0;
    for(int i=0;i<n;i++){
        maxtime=max(maxtime,boards[i]);
        maxTotTime+=boards[i];
    }

    int low=maxtime;
    int high=maxTotTime;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(isJobDone(boards,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    
    return ans;
}