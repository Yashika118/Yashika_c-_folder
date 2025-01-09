#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
  public:
    void leftRotate(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        vector<int>temp;
        d=d%n;
        for(int i=0;i<d;i++){  // O(d)
            temp.push_back(arr[i]);
        }
        
        for(int i=d;i<n;i++){  // O(n-d)
            arr[i-d]=arr[i];
        }
        
        // int j=0;
        // for(int i=n-d;i<n;i++){
        //     arr[i]=temp[j];
        //     j++;
        // }
        

        for(int i=n-d;i<n;i++){  //O(d)
            arr[i]=temp[i-(n-d)];
        }
        
        // TC: O(d)+O(n-d)+O(d)= O(n+d)
        // SC: O(d)
    }
};

// OPTIMAL SOLUTION

// THIS SYNTAX IS FOR ARRAY
// reverse(arr, arr+d)  --> 0 to d-1 th index    TC:O(d)
// reverse(arr+d, arr+n)--> d to n-1 th index    TC:O(n-d)
// reverse(arr, arr+n)  --> 0 to n-1 th index    TC:O(n)
// TC:  O(2n)   SC:O(1)


class Solution {
  public:
    void leftRotate(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        // THIS SYNTAX IS FOR VECTOR
        reverse( arr.begin() , arr.begin()+d );
        reverse( arr.begin()+d , arr.begin()+n );
        reverse( arr.begin() , arr.begin()+n );
    }
};