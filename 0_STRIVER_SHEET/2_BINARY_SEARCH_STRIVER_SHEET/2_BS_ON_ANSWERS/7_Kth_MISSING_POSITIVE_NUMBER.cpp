// BRUTE FORCE
// if arr is empty then kth missing number will be kth number
// but if there is 2 number inserted in arr that are less than k than kth missing number is shifted right two times
//  therefore we increase ans till number is less than and equal to k
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=k;
        for(int i=0;i<n;i++){
            if(arr[i]<=ans){
                ans++;
            }
            else{
                break;
            }
            // cout<<"i : "<<i<<" ans : "<<ans<<endl;
        }

        return ans;
    }
    // TC : O(N)
    // SC : O(1)  
};


// BINARY SEARCH
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0; int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1); //1
            if(missing <k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        // cout<<"high : "<<high<<" low : "<<low<<endl;
        // now we have two nearest indexes(high , low) in between our ans can lie
        
        // int more=k-high; int ans=arr[high];
        // for(int i=0;i<more;i++){
        //     ans=ans+1;
        // }

        // int miss=arr[high]-(high+1);
        // int more=k-miss;
        // arr[high]+more;
        // arr[high]+k-miss
        // arr[high]+k-(arr[high]-(high+1))
        // k+high+1

        return k+high+1;
    }
};