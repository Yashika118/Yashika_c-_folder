#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
int canWeAllocate(vector<int>& arr,int n,int m,int pages){
    int stud=1;
    int pagesStudent=0;
    for(int i=0;i<n;i++){
        if(pagesStudent+arr[i]<= pages){
            pagesStudent+=arr[i];
        }
        else{
            stud++;
            pagesStudent=arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    int ans=-1;
    if(m>n) return ans;

    int maxPage=INT_MIN; int sum=0;
    for(int i=0;i<n;i++){
        maxPage=max(maxPage,arr[i]);
        sum+=arr[i];
    }
    int low=maxPage;
    int high=sum;
    

   for(int i=low;i<=high;i++){
       int cntStud=canWeAllocate(arr,n,m,i);
       if(cntStud==m) return i;
   }

    return ans;
}



// // BINARY SEARCH
// bool canWeAllocate(vector<int>& arr,int n,int m,int pages){
//     int cntStudents=1;
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum>pages){
//             cntStudents++;
//             sum=0;
//             i=i-1;
//         }
//     }
//     if(cntStudents<=m){
//         return true;
//     }
//     return false;
// }
// int findPages(vector<int>& arr, int n, int m) {
//     // Write your code here.
//     int ans=-1;
//     if(m>n) return ans;

//     int maxPage=INT_MIN; int sum=0;
//     for(int i=0;i<n;i++){
//         maxPage=max(maxPage,arr[i]);
//         sum+=arr[i];
//     }
//     int low=maxPage;
//     int high=sum;
    

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(canWeAllocate(arr,n,m,mid)){
//             ans=mid;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }

//     return ans;
// }