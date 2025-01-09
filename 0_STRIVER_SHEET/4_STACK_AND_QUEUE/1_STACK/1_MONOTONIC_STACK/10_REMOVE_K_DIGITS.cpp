#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        int m=k;
        for(int i=0;i<n;i++){
            while(!st.empty() and m>0 and (st.top()-'0') > (num[i]-'0')){
                st.pop();
                m--;
            }
            st.push(num[i]);
        }
        // if k still lefts
        while(m>0){
            st.pop();
            m--;
        }
    
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        // if string contains zeroes at the end eg: 9 1 2 1 0 0 0 0 
        while(res.size()!=0 and res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;

    }
};
// TC:O(3N)+O(K)