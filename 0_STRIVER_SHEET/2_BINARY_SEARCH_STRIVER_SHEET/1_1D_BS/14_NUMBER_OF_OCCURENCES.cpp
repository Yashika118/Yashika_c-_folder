#include<bits/stdc++.h>
using namespace std;
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lb(int arr[],int n,int x){
	    int low=0;
	    int high=n-1;
	    int ans=-1;
	    
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==x){
	            ans=mid;
	            high=mid-1;
	        }
	        else if(arr[mid]>x){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return ans;
	    
	}
	int ub(int arr[],int n,int x){
	    int low=0;
	    int high=n-1;
	    int ans=-1;
	    
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==x){
	            ans=mid;
	            low=mid+1;
	        }
	        else if(arr[mid]>x){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return ans;
	    
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int first=lb(arr,n,x);
	    int last=ub(arr,n,x);
	   // cout<<first<<" "<<last<<endl;
	    
	    if(first==-1) return 0;
	    
	    return last-first+1;
	} 
};