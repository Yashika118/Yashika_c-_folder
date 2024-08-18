#include<bits/stdc++.h>
using namespace std;
void mergeTwoSortedArr(int arr[],int low,int high,int mid){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid and right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}
void mergeSort(int low,int high,int arr[]){
    if(low==high) return;
    int mid=(low+high)/2;
    mergeSort(low,mid,arr);
    mergeSort(mid+1,high,arr);
    mergeTwoSortedArr(arr,low,high,mid);

}
int main(){
    int n=5;
    int arr[]={4,5,3,2,6};
    mergeSort(0,n-1,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// TC: O(n*log(base 2)n)  BEACUSE EVERY STEP ARR DIVIDES BY 2