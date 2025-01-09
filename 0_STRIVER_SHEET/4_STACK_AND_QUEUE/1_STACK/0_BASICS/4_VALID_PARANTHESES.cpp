#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    char ch=st.top();
                    st.pop();
                    if( (s[i]==')' and ch=='(') || (s[i]=='}' and ch=='{') || (s[i]==']' and ch=='[') ){
                        
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        if(st.size()==0) return true;
        return false;
    }
};