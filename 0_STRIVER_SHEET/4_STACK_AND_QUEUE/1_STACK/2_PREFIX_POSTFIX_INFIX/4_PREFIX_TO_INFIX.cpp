#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
     int n=s.length();
     stack<string>st;
     for(int i=n-1;i>=0;i--){
         string str=string(1,s[i]);
         if((str>="A" and str<="Z") || (str>="a" and str<="z") || (str>="0" and str<="9")){
             st.push(str);
         }
         else if(str=="^" || str=="*" || str=="/" || str=="+" || str=="-"){
             string a=st.top(); st.pop();
             string b=st.top(); st.pop();
             string new_str="("+a+str+b+")";
             st.push(new_str);
         }
     }
     return st.top();
        
    }
};