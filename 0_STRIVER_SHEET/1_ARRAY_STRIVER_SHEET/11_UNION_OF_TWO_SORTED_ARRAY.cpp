#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n1, int n2)
    {
        set<int>st;
        vector<int>ans;
        
        for(int i=0;i<n1;i++){   //O(n1 * log n)   n is the size of set
            st.insert(arr1[i]);
        }
        for(int i=0;i<n2;i++){   //O(n2 * log n)   n is the size of set
            st.insert(arr2[i]);
        }
        
        for(auto it:st){        // O(n1+n2)  if both arr have diff elements
            ans.push_back(it);
        }
        
        return ans;

        // TC:O(n1 * log n)+O(n2 * log n)+O(n1+n2)
        // SC:O(n1+n2) + O(n1+n2)

    }
};




// OPTIMAL SOL
class Solution{
    public:
    vector<int> findUnion(int a[], int b[], int n1, int n2)
    {
        int i=0;
        int j=0;
        vector<int>unionArr;
        
        while(i<n1 and j<n2){
            if(a[i]<=b[j]){
                if(unionArr.size()==0 || unionArr.back()!=a[i]){
                    unionArr.push_back(a[i]);
                }
                i++;
            }
            else{
                if(unionArr.size()==0 || unionArr.back()!=b[j]){
                    unionArr.push_back(b[j]);
                }
                j++;
            }
        }
        
        while(j<n2){
            if(unionArr.size()==0 || unionArr.back()!=b[j]){
                    unionArr.push_back(b[j]);
            }
            j++;
        }
        
        while(i<n1){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                    unionArr.push_back(a[i]);
            }
            i++;
        }
        
        
        
        return unionArr;

        // TC:O(n1+n2)
        // SC:O(n1+n2)
    }
};