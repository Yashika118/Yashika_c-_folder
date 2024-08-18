#include<bits/stdc++.h>
using namespace std;
// int binToDec(string str){
//     int len=str.length();
//     int ans=0;
//     int p=0; int num=0;
//     for(int i=len-1;i>=0;i--){
//         int a=str[i]-'0'; // 0=48 1=49 2=50 3=51 (ascii)
//         int num=a*(pow(2,p));
//         // cout<<num<<endl;
//         ans=ans+num;
//         p++;
//     }
//     return ans;
// }
int binToDec(string str){  //1101
    int len=str.length();
    int p2=1; int num=0;  // p2=2^0=1
    for(int i=len-1;i>=0;i--){
        if(str[i]=='1'){
            num=num+p2;
        }
        p2*2;  // 2^1 , 2^2 ,2^3 ...
    }
    return num;
}
int main(){
    string str;
    cin>>str;
    cout<<binToDec(str);
}
//TC: O(len)
//SC: O(1)