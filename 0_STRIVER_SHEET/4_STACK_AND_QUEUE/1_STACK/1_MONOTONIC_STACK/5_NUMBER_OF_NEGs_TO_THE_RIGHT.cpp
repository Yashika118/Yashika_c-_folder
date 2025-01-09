#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int>ans;
       for(int i=0;i<queries;i++){
        //   stack<int>st;
           int ind=indices[i];
           int cnt=0;
           for(int j=n-1;j>ind;j--){
               
               if(arr[j]>arr[ind]){
                //   st.push(arr[j]);
                   cnt++;
               }
               
           }
                    ans.push_back(cnt);
                  
       }
       return ans;
    }

};