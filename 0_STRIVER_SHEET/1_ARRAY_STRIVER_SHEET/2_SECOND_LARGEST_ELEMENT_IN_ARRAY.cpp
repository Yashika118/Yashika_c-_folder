#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());  //N(LOG N)
        
        for(int i=n-2;i>=0;i--){        // O(N)
            if(arr[i]==arr[i+1]){
                continue;
            }
            else{
                return arr[i];
            }
        }
        return -1;
    }

    // TC: N(LOG N)+O(N)

};

// BETTER SOLUTION
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int f_lar=INT_MIN; int s_lar=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>f_lar){
                f_lar=arr[i];
            }
        }
        // cout<<f_lar<<endl;
        for(int i=0;i<arr.size();i++){
            if( (arr[i]!=f_lar) and (arr[i]>s_lar) ){
                s_lar=arr[i];
            }
        }
        
        return s_lar;
    }
    // TC: 2*O(N)
};


// OPTIMAL SOLUTION
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        // a --> first largest
        // b --> second largest
        int a=-1; int b=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>a){
                b=a;
                a=arr[i];
            }
            else if((arr[i]>b) and (arr[i]<a)){
                b=arr[i];
            }
        }
        
        return b;
    }
    // TC:O(N)
};