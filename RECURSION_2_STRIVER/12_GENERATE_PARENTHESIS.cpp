#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findValidParen(int ind,string str,int n,vector<string>&vec,int l,int r){           
        // cout<<str<<endl;
        //ind=2 ((
        if(ind==2*n){
            vec.push_back(str);
            return;
        }

        if(l<n){
            str=str+"("; //((( 
            findValidParen(ind+1,str,n,vec,l+1,r);
            str.pop_back();
        }

        if(r<l){
            str=str+")"; //((()
            findValidParen(ind+1,str,n,vec,l,r+1);
        }

    }
    vector<string> generateParenthesis(int n) {
        string str="";
        vector<string>vec;
        findValidParen(0,str,n,vec,0,0);

        return vec;
    }
};