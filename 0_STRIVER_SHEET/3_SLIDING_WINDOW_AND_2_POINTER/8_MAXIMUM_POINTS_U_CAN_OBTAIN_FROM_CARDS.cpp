#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0; int rightsum=0; int maxsum=0;
        for(int i=0;i<k;i++){
            leftsum+=cardPoints[i];
        }
        maxsum=leftsum;

        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--){
            leftsum=leftsum-cardPoints[i];
            rightsum+=cardPoints[rightIndex];
            maxsum=max(maxsum,leftsum+rightsum);
            rightIndex--;
        }
        return maxsum;
    }
    // TC:O(2*K)
    // SC:O(1)
};