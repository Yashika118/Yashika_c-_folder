#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 4 ^ 1 ^ 2 ^ 1 ^ 2
        // 4 ^ 1 ^ 1 ^ 2 ^ 2
        // 4 ^ 0 ^ 0
        // 4

        int n=nums.size();
        int x_or=0;
        for(int i=0;i<n;i++){
            x_or=x_or^nums[i];
        }
        return x_or;
    }
};