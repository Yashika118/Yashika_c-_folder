#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=INT_MAX){
                for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    nums[j]=INT_MAX;
                }
                else{
                    break;
                }
                }
            }
        }
        // cout<<"yes"<<endl;
        for(int i=0;i<n;i++){
            if(nums[i]==INT_MAX){
                for(int j=i+1;j<n;j++){
                    if(nums[j]==INT_MAX) continue;
                    else{
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }

        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=INT_MAX){
                k++;
            }else{
                break;
            }
        }
        return k;
    }
    // TC: 2* O(N^2) + O(N)
};


// OPTIMAL SOLUTION
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
        // TC:O(N)
    }
};