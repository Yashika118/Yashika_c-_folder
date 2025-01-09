#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=INT_MIN;
        int profit;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                profit=prices[j]-prices[i];
                maxProfit=max(maxProfit,profit);
            }
            
        }
        return maxProfit;
    }
    // TC: O(N^2)  --> GIVES TLE
};

// BETTER SOL
// IF YOU ARE SELLING ON iTH DAY
// YOU BUY ON THE MINIMUM PRICE FROM (1ST --> i-1) th day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int profit=0;

        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
    // TC:O(N)
    // SC:O(1)
};