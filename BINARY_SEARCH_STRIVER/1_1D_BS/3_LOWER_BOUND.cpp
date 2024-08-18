//  LOWER BOUND --> SMALLEST INDEX SUCH THAT ARR[INDEX] >= X
#include<bits/stdc++.h>
using namespace std;
int  func(int arr[],int n,int x){
    int low=0 ; int high=n-1;
    int ans=n;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=x){
            // it can be answer
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
    // TC: O(log(base 2)n)
}
int main(){
    int arr[]={1,2,3,3,5,8,8,10,10,11};
    int n=sizeof(arr)/sizeof(int);
    int x; cin>>x;

    cout<<func(arr,n,x)<<endl;

    // int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();  --> use this instead of writing whole code
}