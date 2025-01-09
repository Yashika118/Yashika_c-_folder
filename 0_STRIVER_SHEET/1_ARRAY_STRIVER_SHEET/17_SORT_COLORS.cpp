#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
    // TC: O(N LOG N)
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<=2;i++){
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    // nums[k]=nums[j];
                    // nums[j]=nums[k];
                    swap(nums[k],nums[j]);
                    k++;
                }
            }
        }
    }
    // TC:O(3N)
};


// BETTER SOL
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }
        int j=0;
        for(int i=0;i<cnt0;i++){
            nums[j]=0;
            j++;
        }
        for(int i=0;i<cnt1;i++){
            nums[j]=1;
            j++;
        }
        for(int i=0;i<cnt2;i++){
            nums[j]=2;
            j++;
        }

        // TC: O(2N)
    }
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;

        for(int i=0;i<n;i++){   //o(N)
            mp[nums[i]]++;      //O(LOG 3)
        }
        int i=0;
        for(auto it:mp){        
            int b=it.second;
            int a=it.first;
            while(b--){
                nums[i]=a;
                i++;
            }
        }
        // TC: O( N + LOG 3 ) 
    }
};


// OPTIMAL SOL

// DUTCH NATIONAL FLAG ALGORITHM
// [ 0 .....low-1]  --> 0   extreme left
// [low.....mid-1]  --> 1
// [mid.....n-1]    --> 2   extreme right

//  index    0 .......low-1 low.......mid-1 mid......high high+1......n-1
//           0 0 0 0 0 0     1 1 1 1 1 1     0 2 1 2 1 0    2 2 2 2 2 2
//           <--       sorted        -->     <-unsorted->   <--sorted-->

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0; int mid=0; int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
    // TC: O(N)
    // SC: O(1)
};