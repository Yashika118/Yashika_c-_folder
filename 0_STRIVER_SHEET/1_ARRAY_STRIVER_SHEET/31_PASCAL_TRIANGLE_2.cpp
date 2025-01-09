// PRINT Nth row in PASCAL TRIANGLE

#include<bits/stdc++.h>
using namespace std;

// // BRUTE FORCE
// int NCR(int n,int r){
//     int res=1;
//     for(int i=0;i<r;i++){
//         res=res*(n-i);
//         res=res/(i+1);
//     }
//     return res;
// }
// void printNthrow(int n,vector<int>&ans){
//     int row=n;
//     int col=n;
//     for(int i=1;i<=col;i++){
//         int val=NCR(row-1,i-1);
//         ans.push_back(val);
//     }

// }
// // TC: O(n * r)


// OPTIMAL SOLTUION
void printNthrow(int n,vector<int>&ans){
    int val=1;
    ans.push_back(val);

    for(int i=1;i<n;i++){
        val=val*(n-i);
        val=val/i;
        ans.push_back(val);
    }
}
// TC: O(n)

int main(){
    int n=6;
    vector<int>ans;
    printNthrow(n,ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }
}
