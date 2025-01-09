#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int count=0;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int x_or=0;
            for(int k=i;k<=j;k++){
                x_or=x_or ^ a[k];
                
            }
                if(x_or == b){
                    count++;
                }
        }
    }
    return count;
}


// BETTER SOLUTION
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int count=0;
    
    for(int i=0;i<n;i++){
        int x_or=0;
        for(int j=i;j<n;j++){
            x_or=x_or ^ a[j];
            if(x_or == b){
                count++;
            }
        }
    }
    return count;
}

// OPTIMAL SOLUTION
//              xor
//       <------------------>
//        x         k
//       <-->  <------------>
// Arr = { 4   2   2   6   4}

//  x ^ k = xor
//  (x ^ k) ^ k = xor ^ k
//  x = xor ^ k  --> formula
#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int xr=0;
    map<int,int>mpp;
    mpp[xr]++;  // {0,1}
    int count=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];
        int x=xr^b;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;

}



