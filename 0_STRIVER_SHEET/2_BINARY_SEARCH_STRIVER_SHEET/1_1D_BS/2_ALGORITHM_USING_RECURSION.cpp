#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int low,int high,int target,vector<int>& nums){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]){
            return func(mid+1,high,target,nums);
        }
        else{
            return func(low,mid-1,target,nums);
        }
    }
    int search(vector<int>& nums, int target) {
        return func(0,nums.size()-1,target,nums);
    }

    // TC: O(log (base 2) n)
    // IF ARR IS IN BETWEEN 0 ----> INT_MAX
    // THEN IF OUR SEARCHING ELEMENT IS ON INT_MAX th INDEX THEN
    // MID=(LOW + HIGH)/2 =(INT_MAX + INT_MAX)/2  ---> gives overflow
    // WE CAN AVOID IT BY USING LONG LONG INSTEAD OF INT  OR
    // WE CAN WRITE MID AS MID= ( LOW + ( (HIGH-LOW) ) / 2 ) )
};