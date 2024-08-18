// #include<bits/stdc++.h>
// using namespace std;
// void func(int ind,vector<int>&v,int sum,int arr[],int n,int k){
//     if(ind==n){
//         if(sum==k){
//             for(auto it:v){
//                 cout<<it<<" ";
//             }
//                 cout<<endl;
//         }
//         return;
//     }

//     v.push_back(arr[ind]);
//     sum=sum+arr[ind];
//     func(ind+1,v,sum,arr,n,k);

//     sum=sum-arr[ind];
//     v.pop_back();
//     func(ind+1,v,sum,arr,n,k);
// }
// int main(){
//     int n=3; int k=2;
//     int arr[]={1,2,1};
//     vector<int>v;
//     func(0,v,0,arr,n,k);
// }


// // Technique to return only one answer
// // if we have to print only one subsequence whose sum is k then
// #include<bits/stdc++.h>
// using namespace std;
// bool func(int ind,vector<int>&v,int sum,int arr[],int n,int k){
//     if(ind==n){
//         if(sum==k){
//             for(auto it:v){
//                 cout<<it<<" ";
//             }
//                 cout<<endl;
//                 return true;
//         }
//         return false;
//     }

//     v.push_back(arr[ind]);
//     sum=sum+arr[ind];
//     if(func(ind+1,v,sum,arr,n,k)==true) return true;

//     sum=sum-arr[ind];
//     v.pop_back();
//     if(func(ind+1,v,sum,arr,n,k)) return true;
//     return false;
// }
// int main(){
//     int n=3; int k=2;
//     int arr[]={1,2,1};
//     vector<int>v;
//     func(0,v,0,arr,n,k);
// }



// count subsequences whose sum is k
#include<bits/stdc++.h>
using namespace std;
int func(int ind,vector<int>&v,int sum,int arr[],int n,int k){
    if(sum>k) return 0;
    if(ind==n){
        if(sum==k){
            for(auto it:v){
                cout<<it<<" ";
            }
                cout<<endl;
                return 1;
        }
        return 0;
    }

    v.push_back(arr[ind]);
    sum=sum+arr[ind];
    int left=func(ind+1,v,sum,arr,n,k);

    sum=sum-arr[ind];
    v.pop_back();
    int right=func(ind+1,v,sum,arr,n,k);
    return left+right;
}
int main(){
    int n=3; int k=2;
    int arr[]={1,2,1};
    vector<int>v;
    cout<<func(0,v,0,arr,n,k)<<endl;
}