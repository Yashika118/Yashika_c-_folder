#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};


// BRUTE FORCE 2
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
    // TC: O(N^4)
    // SC: O(no. of quads) * 2
};

// BETTER SOLUTION
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long >hashset;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-(sum);
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int) fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
    // TC: O(N^3 * log(size of set))
    // SC: O(N)+ O(quads)*2
};


// OPTIMAL APPROACH
// previously we have i j k l
// we keep i and j fixed and j and k act as pointers
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];

                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l and nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<l and nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};