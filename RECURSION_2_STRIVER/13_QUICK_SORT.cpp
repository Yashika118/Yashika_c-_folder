// SLIGHTLY BETTER THAN MERGE SORT IN TERMS OF SC: O(1)
// 1 PICK A PIVOT AND PLACE IT IN ITS CORRECT PLACE IN ITS SORTED ARR
// 2 SMALLER ON THE LEFT LARGER ON THE RIGHT
#include<bits/stdc++.h>
using namespace std;
int func(int arr[],int n,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){

        while(arr[i]<=pivot and i<=high){
            i++;
        }
        while(arr[j]>pivot and j>=low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}
void quickSort(int arr[],int n,int low,int high){
    if(low<high){
        int ind=func(arr,n,low,high);
        quickSort(arr,n,low,ind-1);
        quickSort(arr,n,ind+1,high);
    }
}
int main(){
    int n=8;
    // int arr[]={4,6,2,5,7,9,1,3};
    int arr[]={8,7,6,5,4,3,2,1};
    int low=0;
    int high=n-1;
    quickSort(arr,n,low,high);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}