//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        int n=s.length();
        stack<string>st;
        
        // for(int i=0;i<n;i++){
        //     char ch=s[i];
        //     if((ch>='A' and ch<='Z') || (ch>='a' and ch<='z') || (ch>='0' and ch<='9') ){
        //         st.push(string(1,ch));
        //     }
        //     else if(ch=='^' || ch=='*' || ch=='/' || ch=='+' || ch=='-'){
        //         string b=st.top();
        //         st.pop();
        //         string a=st.top();
        //         st.pop();
        //         string str="("+a+ch+b+")";
        //         st.push(str);
        //     }
        //     // cout<<st.top()<<endl;
        // }
        
        for(int i=0;i<n;i++){
            string ch=string(1,s[i]);
            if((ch>="A" and ch<="Z") || (ch>="a" and ch<="z") || (ch>="0" and ch<="9") ){
                st.push(ch);
            }
            else if(ch=="^" || ch=="*" || ch=="/" || ch=="+" || ch=="-"){
                string b=st.top();
                st.pop();
                string a=st.top();
                st.pop();
                string str="("+a+ch+b+")";
                st.push(str);
            }
        }
        
        return st.top();
    }
};

// TC:O(N)+O(N)
// SC:O(1)