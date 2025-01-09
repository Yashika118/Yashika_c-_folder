#include<bits/stdc++.h>
using namespace std;


// BRUTE FORCE 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        set<vector<int>>s;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    vector<int>v;
                    if(nums[i]+nums[j]+nums[k]==0){
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;

    }
    // TC: TLE  : O(n^3 * log(no.of uniques) )
    // SC: 2*O(log(no . of triplets))
};


// BETTER SOLUTION
// a[i] + a[j] + a[k] = 0
// a[k] = - ( a[i] + a[j] )
// use hashset --> same as unordered set , TC : O(1) for searching
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();

        set<vector<int>>s;
        for(int i=0;i<n;i++){
            set<int>hashset;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i] + nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int>temp={nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hashset.insert(nums[j]);
                
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;

    }
    // TC: O(N^2 * log(size of set) )
    // SC : O(N) + O(no. of triplets)
};

// OPTIMAL SOL : TWO POINTER APPROACH
// previously we have i j k
// we keep i fixed and j and k act as pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if (sum>0){
                    k--;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k and nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
        // TC: O(n log n) + O(n * n)
        // O(no. of triplets)
    }
};