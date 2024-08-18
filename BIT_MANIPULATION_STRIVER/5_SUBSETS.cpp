#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        int noOfSubset=1<<n;  //---->(2^n);
        for(int numb=0;numb<noOfSubset;numb++){    // TC: 2^n
            vector<int>v;
            for(int j=0;j<n;j++){                  // TC: n 
                if(numb & (1<<j)){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);

        }
        return ans;
    }

    // TC = O( 2^n * n);
    // SC ~ O(2^n * n) --->nearly
};