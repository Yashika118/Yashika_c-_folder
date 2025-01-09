#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;

    // TC:O(N)
    // SC:O(1)
}
