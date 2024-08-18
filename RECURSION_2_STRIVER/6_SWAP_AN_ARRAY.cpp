// #include<bits/stdc++.h>
// using namespace std;
// void func(int l,int r,int arr[]){
//     if(l>=r) return;
//     swap(arr[l],arr[r]);
//     func(l+1,r-1,arr);
// }
// int main(){
//     // int arr[]={1,2,3,4,5,6};
//     int arr[]={1,3,2,5,4};
//     int n=sizeof(arr)/sizeof(int);
//     func(0,n-1,arr);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }



#include<bits/stdc++.h>
using namespace std;
    int arr[]={1,2,3,4,2};
    int n=sizeof(arr)/sizeof(int);
void func(int i){
    if(i>n/2) return ;
    swap(arr[i],arr[n-i-1]);
    func(i+1);
}
int main(){
    func(0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}