#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==0){
                for(int j=i+1;j<n;j++){
                    if(nums[j]==0) continue;
                    else{
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        } 
    }
    // TC:O(N^2)
};


// BETTER SOLUTION
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){  // O(n)
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }

        int x=temp.size();
        for(int i=0;i<temp.size();i++){  //O(x)
            nums[i]=temp[i];
        }

        for(int i=x;i<n;i++){  //O(n-x)
            nums[i]=0;
        }

        // TC: O(2n)
        // SC: O(x) --> O(n)
    }
};


// OPTIMAL SOL
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){  //O(n)
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        for(;j<n;j++){ //O(n-j)
            nums[j]=0;
        }
    }
};