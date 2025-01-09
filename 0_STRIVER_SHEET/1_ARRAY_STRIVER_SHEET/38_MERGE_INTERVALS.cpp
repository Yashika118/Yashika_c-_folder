#include<bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());  // n log n
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(!ans.empty() and end<=ans.back()[1]){
                continue;
            }

            for(int j=i+1;j<n;j++){
                if(intervals[j][0] <= end ){
                    end=max(end,intervals[j][1]);
                }
                else{
                    break;
                }
            }

            ans.push_back({start,end});

            // o(2n)
        }

        return ans;

    }
    // TC: O( n log n) + O(2n)
    // SC : o(n)

};

// Optimal solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                // then we form new interval
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }

           
        }

        return ans;

    }
    // TC: O(n log n) + O(n)
    // SC: O(n) 
};
