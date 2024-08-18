// FLOOR --> LARGEST NUMBER IN ARRAY < = X 
// CEIL --> SMALLEST NUMBER IN ARRAY > = X 

#include<bits/stdc++.h>
using namespace std;
int floor(int arr[],int n,int x){
    int low=0; int high=n-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<= x){
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
}
int main(){
    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(int);
    int x; cin>>x;

    cout<<floor(arr,n,x)<<endl;
}