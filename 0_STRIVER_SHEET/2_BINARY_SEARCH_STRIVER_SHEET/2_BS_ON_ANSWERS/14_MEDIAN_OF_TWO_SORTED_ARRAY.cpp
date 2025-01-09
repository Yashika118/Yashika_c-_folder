#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>v;
        int i=0,j=0;

        while(i<n1 and j<n2){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            v.push_back(nums2[j]);
            j++;
        }

        int n=n1+n2;
        if(n%2==1){
            return v[n/2];
        }else{
            return (double)((double) v[n/2] + (double) v[(n/2)- 1])/2;
        }
        
        return -1;

    }
};

// BETTER
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int i=0,j=0;
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int indele1=-1,indele2=-1;

        while(i<n1 and j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) indele1=nums1[i];
                if(cnt==ind2) indele2=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==ind1) indele1=nums2[j];
                if(cnt==ind2) indele2=nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
                if(cnt==ind1) indele1=nums1[i];
                if(cnt==ind2) indele2=nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
                if(cnt==ind1) indele1=nums2[j];
                if(cnt==ind2) indele2=nums2[j];
                cnt++;
                j++;
        }

        if(n%2==1){
            return indele2;
        }
            return (double) ((double)(indele1 +indele2))/2.0 ;
        

    }
};


// OPTIMAL APPROACH
// BINARY SEARCH

// arr1={1,3,4,7,10,12}
// arr2={2,3,6,15}

// FOR EVEN -->
// median=(n1+n2)/2
//  we want  1 2 3 3 4 | 6 7 10 12 15
// on left we want 5 ele and right we want 5 ele
// make combinations in such a way that on left has 5 and right has 5 elements

// if we take 4 ele from arr1 and 1 ele from arr2

//  1 3 4 7     |       10 12
//        2     |       3  6  15

// if we take 3 ele from arr1 and 2 ele from arr2

//  1 3 4   l1   |  r1   7 10 12     --> this is valid bcoz 4 < 6 and 3 < 7
//    2 3   l2   |  r2   6  15

// similarly we can try all the combinations

// ( max(l1,l2) + min(r1,21) ) / 2

// FOR ODD
// median=(n1+n2+1)/2
// max(l1,l2)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();
        if(n1>n2) return findMedianSortedArrays(b,a);
        int low=0; int high=n1;
        int left=(n1+n2+1)/2;
        int n=n1+n2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1 >= 0) l1=a[mid1-1];
            if(mid2-1 >= 0) l2=b[mid2-1];
            if(l1<=r2 and l2<=r1){
                if(n%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
};