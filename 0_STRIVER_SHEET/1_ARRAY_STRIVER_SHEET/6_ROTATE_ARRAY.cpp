#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(); 
        k=k%n; // 1 2 3 0 1 2 3 0
        int val=n-k;
        if(k==0){
            nums=nums;
        }
        else{
            vector<int>temp;
            int cnt=k; int ind=-1;
            for(int i=val;i<n;i++){
                temp.push_back(nums[i]);
            }
            for(int i=0;i<val;i++){
                temp.push_back(nums[i]);
            }
            nums=temp;
        }

    }
};