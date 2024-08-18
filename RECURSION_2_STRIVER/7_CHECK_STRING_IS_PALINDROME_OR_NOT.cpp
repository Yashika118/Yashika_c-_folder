#include<bits/stdc++.h>
using namespace std;
bool check(int i,string&s){
    if(i >= (s.size())/2) return true;
    if(s[i]!=s[(s.size())-i-1]) return false;
    check(i+1,s);
}
int main(){
    string s="madam";
    cout<<check(0,s);
}