#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // vector<int>ans;
        int n=arr.size();
        int repeating=-1; int missing=-1;
        
        for(int i=1;i<=n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[j]==i){
                    count++;
                }
            }
            
            if(count==2){
                repeating=i;
            }
            
            else if(count==0){
                missing=i;
            }
            
            if(repeating != -1 and missing != -1) break;
        }
        
        // ans.push_back(repeating);
        // ans.push_back(missing);
        
        return {repeating,missing};
    }

    // TC: O(N^2)
    // SC: O(1)
};

// BETTER SOL
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int repeating=-1;
        int missing=-1;
        
        int freq[n+1]={0};
        
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(freq[i]==2){
                repeating=i;
            }
            else if(freq[i]==0){
                missing=i;
            }
            
            if(repeating!=-1 and missing!=-1){
                break;
            }
        }
        
        return {repeating,missing};
    }
    // TC: O(2N)
    // SC: O(N)
};


// OPTIMAL APPROACH 1
// SN = sum of first n natural no. = ( n * (n+1) ) / 2
// S2N = sum of square of first n natural no. = ( n * (n+1) * (2 *n+1) ) / 6

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        
        long long SN=( n * (n+1) ) / 2;
        long long S2N =( n * (n+1) * (2*n+1) ) / 6;
    
        long long S=0; 
        long long S2=0;
        
        for(int i=0;i<n;i++){
            S+=arr[i];
            S2+=(long long )arr[i]*(long long)arr[i];
        }
        
        long long val1=S-SN;          // X-Y
        long long val2=S2-S2N;        // X^2 - Y^2
        
        val2=val2 / val1;       // X+Y
        
        long long x = (val1 + val2) /2;
        long long y= x-val1;
        
        return {(int) x ,(int) y };
    }
    // TC: O(N)
    // SC:O(1) 
};

// OPTIMAL SOL 2
// USING BIT MANIPULATION
// USING XOR 
// I WILL DO THIS LATER