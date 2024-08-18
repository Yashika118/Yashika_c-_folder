// subsequences : a contigous/non-contigous sequences, which follows the order
#include<bits/stdc++.h>
using namespace std;
void subSeq(int ind,vector<int>&v,int arr[],int n){
    if(ind>=n){
        for(auto it:v){
            cout<<it<<" ";
        }
        if(v.size()==0){
            cout<<"{}"<<" ";
        }
        cout<<endl;
        return;
    } 
    v.push_back(arr[ind]);
    subSeq(ind+1,v,arr,n);
    v.pop_back();
    subSeq(ind+1,v,arr,n);
}
int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int>v;
    subSeq(0,v,arr,n);
}

// TC: 2^n * n
// SC:O(n);