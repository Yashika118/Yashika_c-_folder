// EXACTLY SAME AS AGRESSIVE COWS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canWeDistribute(vector<int>& position,int m,int dist){
        int n=position.size();
        int cntBalls=1;
        int lastPlaced=position[0];

        for(int i=1;i<n;i++){
            if(position[i]-lastPlaced >= dist){
                lastPlaced=position[i];
                cntBalls++;
            }
        }
        if(cntBalls>=m){
            return true;
        }
        return false;
        
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int maxDist=position[n-1]-position[0];
        int low=1;
        int high=maxDist;
        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(canWeDistribute(position,m,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};