// IMPORTANT
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE  --> +ve and -ve
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int max_len=0;
        
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                int sum=0;
                for(int m=i;m<=j;m++){
                    sum+=A[m];
                }
                if(sum==K){
                    max_len=max(max_len,j-i+1);
                }
            }
        }
        return max_len;
    } 
    // TC:O(N^3)

};


class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int max_len=0;
        
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum+=A[j];
                if(sum==K){
                    max_len=max(max_len,j-i+1);
                    // break;
                }
            }
        }
        return max_len;
    } 
    // TC:O(N^2)
};



// BETTER SOLUTION
// work for +ve integers
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<long long,int> preSumMap;
        // map means ordered map takes log n time 
        // unordered map take O(1) in average case and O(N) in worst case
        long long sum=0;
        int maxlen=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==K){
                maxlen=max(maxlen,i+1);
            }
            long long rem=sum-K;
            if(preSumMap.find(rem)!= preSumMap.end()){  // does exist
                int len=i-preSumMap[rem];
                maxlen=max(maxlen,len);
            }

            // preSumMap[sum]=i;           //---> this condition is for +ve integer
            
            if(preSumMap.find(rem)==preSumMap.end()){  // this condiion is for +ve 
                preSumMap[sum]=i;
            }

            // if(preSumMap.find(sum)==preSumMap.end()){  // this condiion is for +ve and -ve integers 
            //     preSumMap[sum]=i;
            // }
        }
        
        return maxlen;
    } 
    // TC: O(N LOG N)
    // SC: O(N)
};


// OPTIMAL SOLUTION 
// work on only positive integers
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int N, int K) 
    { 
        // Complete the function
        int left=0; int right=0;
        long long sum=a[0];
        int maxlen=0;
        
        while(right<N){
            while(left <=right and sum>K){
                sum-=a[left];
                left++;
            }
            if(sum==K){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
            if(right<N){
                sum+=a[right];
            }
        }
        return maxlen;
        // TC:O(2N)
        // SC:O(1)
    } 

};
