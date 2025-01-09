// Print all rows
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    int NCR(int n, int r){
        int res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int row=1;row<=numRows;row++){
            vector<int>v;
            for(int col=1;col<=row;col++){
                int val=NCR(row-1,col-1);
                v.push_back(val);
            }

            ans.push_back(v);
        }
        return ans;
    }
    // TC:O(N^3)
};


// BETTER SOL
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int row=1;row<=numRows;row++){
            vector<int>v;
            int val=1;
            v.push_back(val);

            for(int col=1;col<row;col++){
                val=val*(row-col);
                val=val/col;
                v.push_back(val);
            }

            ans.push_back(v);
        }
        return ans;
    }
    // TC: O( n^2 )
};
