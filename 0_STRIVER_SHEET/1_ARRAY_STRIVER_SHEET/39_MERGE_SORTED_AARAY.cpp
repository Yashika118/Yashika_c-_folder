#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        long long arr3[n+m];
        int left=0;
        int right=0;
        int index=0;

        while(left<m and right<n){
            if(arr1[left]<=arr2[right]){
                arr3[index]=arr1[left];
                left++;
                index++;
            }
            else{
                arr3[index]=arr2[right];
                right++;
                index++;
            }
        }

        while(left<m){
            arr3[index]=arr1[left];
            left++;
            index++;
        }

        while(right<n){
            arr3[index]=arr2[right];
            right++;
            index++;
        }
        // o(n+m) including all while loops
        for(int i=0;i<(m+n);i++){
            if(i<m){
                arr1[i]=arr3[i];
            }
            else{
                arr2[i-n]=arr3[i];
            }
        }
        // o(n+m)
    }

    // TC: 2(O(N+M))
    // SC: O(N+M)
};


// BETTER SOL
class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int left=m-1;
        int right=0;
        while(left>=0 and right<n){
            if(arr1[left]>arr2[right]){
                swap(arr1[left],arr2[right]);
                left--;
                right++;
            }
            else{
                break;
            }
        }
        // for array syntax
        // sort(arr1,arr1+m);
        // sort(arr2,arr2+n);

        // for vector syntax
        sort(arr1.begin(),arr1.begin()+m);
        sort(arr2.begin(),arr2.begin()+n);

        for(int i=m;i<arr1.size();i++){
            arr1[i]=arr2[i-m];
        }
    }
    // TC: O(min(n,m)) + O( n log  n) + O( m log m)
    // SC: O(1)
};

// Optimal sol
// GAP METHOD
// SHELL SORT TECHNIQUE
class Solution {
private:
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1,int ind2){
        if(arr1[ind1]>arr2[ind2]){
            swap(arr1[ind1],arr2[ind2]);
        }
    }
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int len = m+n;
        int gap=(len/2)+(len%2);
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                // case 1 when left is on 1st arr and right is on 2nd arr
                if(left<m and right>=m){
                    swapIfGreater(arr1,arr2,left,right-m);
                }
                else if(left>=m){
                    // case 2 when left and right both are on 2nd arr
                    swapIfGreater(arr2,arr2,left-m,right-m);


                }
                else{
                    // when left and right both are on 1st arr
                    swapIfGreater(arr1,arr1,left,right);

                }
                left++; right++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }

        for(int i=m;i<n+m;i++){
            arr1[i]=arr2[(i-m)];
        }

    }
    // TC: O( LOG BASE 2 (n+m)) * O(n+m)
    // SC:O(1)
};