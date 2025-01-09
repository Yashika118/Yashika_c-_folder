#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProduct=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int pro=1;
                for(int k=i;k<=j;k++){
                    pro=pro*nums[k];

                }
                    maxProduct=max(maxProduct, pro);
            }
        }

        return maxProduct;
    }
    // TC: O(N^3)
    // SC:O(1)
};

// BRUTE FORCE 2
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProduct=INT_MIN;

        for(int i=0;i<n;i++){
            int pro=1;
            for(int j=i;j<n;j++){
                    pro=pro*nums[j];
                    maxProduct=max(maxProduct, pro);
            }
        }

        return maxProduct;
    }
    // TC:O(N^2)
    // SC:O(1)
};


// OPTIMAL SOL
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prefix=1;
        int suffix=1;
        int maxProduct=INT_MIN;

        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;

            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];

            maxProduct=max(maxProduct,max(prefix,suffix));
        }

        return maxProduct;
    }
    // TC:O(N)
    // SC:O(1)
};