#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxHeight=0;
        int leftmax[n],rightmax[n];
        int tot=0;
        for(int i=0;i<n;i++){
            leftmax[i]=maxHeight;
            maxHeight=max(maxHeight,height[i]);
        }
        maxHeight=0;
        for(int i=n-1;i>=0;i--){
            rightmax[i]=maxHeight;
            maxHeight=max(maxHeight,height[i]);
        }

        for(int i=0;i<n;i++){
            int mini=min(leftmax[i],rightmax[i]);
            if(mini > height[i]){
                tot+=(mini-height[i]);
            }
        }
        return tot;
    }
};
// TC:O(3N)
// SC:O(2N)