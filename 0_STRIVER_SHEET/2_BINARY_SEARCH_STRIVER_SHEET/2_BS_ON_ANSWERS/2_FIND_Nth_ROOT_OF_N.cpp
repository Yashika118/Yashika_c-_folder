#include<bits/stdc++.h>
using namespace std;
// class Solution{
// 	public:
// 	int func(int i,int n){
// 	    int a=i; 
// 	    for(int j=1;j<n;j++){
// 	        a=a*i;
// 	    }
// 	    return a;
// 	}
// 	int NthRoot(int n, int m)
// 	{
// 	    // Code here.
// 	    for(int i=1;i<=m;i++){
// 	       if(func(i,n)==m){
// 	           return i;
// 	       }
// 	       else if(func(i,n)>m){
// 	           break;
// 	       }
// 	    }
	    
// 	    return -1;
// 	}  
// };


class Solution{
	public:
	int func(int i,int n,int m){
	    long long a=i; 
	    for(int j=1;j<n;j++){
	        a=a*i;
	        if(a>m) return -1;
	    }
	    return a;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	   
	    int low=1; int high=m;
	    while(low<=high){
	        int mid=(low+high)/2;
	       
	        int temp=func(mid,n,m);

	        if(temp==m) return mid;
	        else if(temp == -1){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    
	    return -1;
	    
	}  
};