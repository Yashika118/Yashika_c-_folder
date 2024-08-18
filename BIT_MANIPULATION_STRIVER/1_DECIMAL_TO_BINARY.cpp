#include<bits/stdc++.h>
using namespace std;
string decToBin(int n){
    string str="";
    while(n!=1){
        if(n%2==1){
            str+="1";
        }
        else{
            str+="0";
        }

        n=n/2;
    }

    str=str+"1";
    return str;
}
int main(){
    int n; cin>>n;
    string ans=decToBin(n);
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

// TC: LOG(base 2)n   -->beacuse we divided by 2 everytime
// SC: LOG(base 2)n