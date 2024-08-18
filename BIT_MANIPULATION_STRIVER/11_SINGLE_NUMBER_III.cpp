// let an arr[]={2,4,2,14,8,7,7,8}
// 1. we do xor for all the numers in arr --> (2^2)^(8^8)^(7^7)^(14^4) = 0 ^ (14^4) =1 0 1 0
//      it means:
//      bit: 3 2 1 0
//      14 = 1 1 1 0
//       4 = 0 1 0 0
//       ^ = 1 0 1 0    --> 1st and 3rd bit are different
//  it means only one diff bit is sufficient to identify that both are diff numbers

//  2. now we put numbers from array with 1st bit =1 in one bucket and and 1st bit =0 in second bucket;
//  3. xor all the number in both buckets separately 
//  4. each bucket gives single number that repeat once

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xo_r=0;
        for(int i=0;i<nums.size();i++){   //O(N)
            xo_r=xo_r^nums[i];
        }
        long long right_most_1=(xo_r & (xo_r-1)) ^ xo_r;  // O(1)
        int bucket1=0; int bucket2=0;

        for(int i=0;i<nums.size();i++){    //O(N)
            if((nums[i] & right_most_1)){
                bucket1=bucket1 ^ nums[i];
            }
            else{
                bucket2=bucket2 ^ nums[i];
            }
        }

        return {bucket1,bucket2};
        // TC: O(2N)
        // SC: (1)
    }
};