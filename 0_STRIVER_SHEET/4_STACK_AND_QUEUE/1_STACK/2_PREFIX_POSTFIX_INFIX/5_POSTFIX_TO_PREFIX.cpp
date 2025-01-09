#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        int n=s.length();
        stack<string>st;
        for(int i=0;i<n;i++){
            string ch=string(1,s[i]);
            if((ch>="A" and ch<="Z") || (ch>="a" and ch<="z") || (ch>="0" and ch<="9") ){
                st.push(ch);
            }
            else if(ch=="^" || ch=="*" || ch=="/" || ch=="+" || ch=="-"){
                string a=st.top(); st.pop();
                string b=st.top(); st.pop();
                string str=ch+b+a;
                st.push(str);
            }
        }
        return st.top();
    }
};