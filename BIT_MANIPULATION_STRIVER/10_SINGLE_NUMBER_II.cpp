#include<bits/stdc++.h>
using namespace std;

// 1ST APPROACH --> USING MAP  

//  // 2ND APPROACH
// INTERVIEWER WILL NOT HAPPY WITH THIS
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ans=0;
//         for(int bits=0;bits<=31;bits++){
//             int count=0;
//             for(int i=0;i<nums.size();i++){
//                 if( ( nums[i] & (1<<bits) ) >=1 ){
//                     count++;
//                 }
//             }
//             if(count%3!=0){
//                 ans=ans+(1<<bits);
//             }
//         }

//         return ans;
//     }
//     // TC:O(N*32)
//     // SC:O(1)
// };


// // 3RD APPROACH --> BETTER THAN ABOVE
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());      // nlogn
//         for(int i=1;i<nums.size();i=i+3){   // n/3
//             if(nums[i]!=nums[i-1]){
//                 return nums[i-1];
//             }
//         }

//         return nums[nums.size()-1];

//         // TC: nlogn + n/3
//         // SC: O(1)
//     }
// };


// 4TH APPROACH --> CONCEPT OF BUCKET
// MOST OPTIMAL SOLUTION
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0; int twos=0;
        for(int i=0;i<nums.size();i++){
            // nums[i] will go to ones , if it not in twos
            ones=(ones^nums[i]) & (~twos);
            // nums[i] will go to twos , if it not in ones
            twos=(twos^nums[i]) & (~ones);
        }
        return ones;

        // TC : O(N)
        // SC : O(1)
    }
};