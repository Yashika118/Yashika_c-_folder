#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string s) {
        int n=s.length();
        stack<string>st;
        for(int i=n-1;i>=0;i--){
            string ch=string(1,s[i]);
            if((ch>="A" and ch<="Z") || (ch>="a" and ch<="z") || (ch>="0" and ch<="9") ){
                st.push(ch);
            }
            else if(ch=="^" || ch=="*" || ch=="/" || ch=="+" || ch=="-"){
                string a=st.top(); st.pop();
                string b=st.top(); st.pop();
                string str=a+b+ch;
                st.push(str);
            }
        }
        return st.top();
    }
};