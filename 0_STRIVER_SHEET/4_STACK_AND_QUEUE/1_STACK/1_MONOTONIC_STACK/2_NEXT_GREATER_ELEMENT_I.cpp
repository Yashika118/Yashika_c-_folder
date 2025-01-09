#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans(n1,0);
        // int i=0;
        for(int i=0;i<n1;i++){
            stack<int>st;
            for(int j=n2-1;j>=0;j--){
                // if(i<n1){

                    while(!st.empty() and st.top()<=nums1[i]){
                    st.pop();
                    }
                    if(st.empty()){
                        if(nums1[i]==nums2[j]) ans[i]=-1;
                    }
                    else{
                        if(nums1[i]==nums2[j]){
                            ans[i]=st.top();
                            break;
                            // i++;
                        }
                    } 
                    st.push(nums2[j]);
                // }
            }
        }
        return ans;
    }
};
