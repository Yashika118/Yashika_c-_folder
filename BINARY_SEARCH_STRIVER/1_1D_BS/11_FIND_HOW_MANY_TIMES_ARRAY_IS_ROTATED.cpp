// FIND KTH ROTATION
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int low=0; int high=n-1;
        int ans=INT_MAX;
        int index=-1;

        while(low<=high){
            int mid=(low+high)/2;
            // if arr is already sorted
           if(arr[low]<=arr[high]){
                if(arr[low]<ans){
                    ans=arr[low];
                    index=low;
                }
                break;
           }
            // if left half is sorted then pick the first element of left half
            // because it might be minimum
            if(arr[low]<=arr[mid]){
                 if(arr[low]<ans){
                    ans=arr[low];
                    index=low;
                }
                low=mid+1;
            }
            else{
                if(arr[mid]<ans){
                    ans=arr[mid];
                    index=mid;
                }
                high=mid-1;
                
            }
        }

        return index;
    }
};