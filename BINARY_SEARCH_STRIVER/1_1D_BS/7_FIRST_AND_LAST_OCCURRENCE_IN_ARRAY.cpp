// // USING LOOP
// #include<bits/stdc++.h>
// using namespace std;
// void findOccurr(int arr[],int n,int x,int &first,int &last){
//     for(int i=0;i<n;i++){
//         if(arr[i]==x){
//             if(first==-1){
//                 first=i;
//             }
            
//             last=i;
//         }
//     }
//     // TC: O(N);
// }
// int main(){
//     int arr[]={2,4,6,8,8,8,11,13,15,15,15};
//     int n=sizeof(arr)/sizeof(int);
//     int x; cin>>x;
//     int first=-1; int last=-1;
//     findOccurr(arr,n,x,first,last);
//     cout<<"first_occurr : "<<first<<endl;
//     cout<<"last_occurr : "<<last<<endl;
    
// }



// BETTER APPROACH -->
#include<bits/stdc++.h>
using namespace std;
int lowerBound(int arr[],int n,int x){
    int low=0; int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upperBound(int arr[],int n,int x){
    int low=0; int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[]={2,4,6,8,8,8,11,13};
    int n=sizeof(arr)/sizeof(int);
    int x; cin>>x;
    int lb=lowerBound(arr,n,x);
    int ub=upperBound(arr,n,x);

    if(lb==n || arr[lb]!=x){
        cout<<"lb : -1"<<endl;
        cout<<"ub : -1"<<endl;
    }
    else{
        cout<<"lb : "<< lb <<endl;
        cout<<"ub : "<< ub-1 <<endl;
    }

    // TC: 2* O(log(base 2)n)
}



// // INTERVIWER CAN ASK FOR DO THIS QUES BY SIMPLE BINARY SEARCH
// #include<bits/stdc++.h>
// using namespace std;
// int bsToFindLowerBound(int arr[],int n,int x){
//     int low=0; int high=n-1;
//     int first=-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid]==x){
//             first=mid;
//             high=mid-1;
//         }
//         else if(arr[mid]<x){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }

//     return first;
// }
// int bsToFindUpperBound(int arr[],int n,int x){
//     int low=0; int high=n-1;
//     int last=-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[mid]==x){
//             last=mid;
//             low=mid+1;
//         }
//         else if(arr[mid]<x){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }

//     return last;
// }
// int main(){
//     int arr[]={2,4,6,8,8,8,11,13,14,14};
//     int n=sizeof(arr)/sizeof(int);
//     int x ; cin>>x;

//     int first=bsToFindLowerBound(arr,n,x);
//     int last=bsToFindUpperBound(arr,n,x);

//     if(first == -1){
//         cout<<"first : -1"<<endl;
//         cout<<"last : -1"<<endl;
//     }
//     else{
//         cout<<"first : "<<first<<endl;
//         cout<<"last : "<<last<<endl;
//     }
// }