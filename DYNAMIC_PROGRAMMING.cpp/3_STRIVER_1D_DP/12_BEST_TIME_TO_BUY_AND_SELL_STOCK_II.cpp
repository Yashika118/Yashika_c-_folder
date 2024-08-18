#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int func(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit=0;
        if(buy){
            // buy
            int take= -prices[ind]+func(ind+1,0,prices,dp);
            int notTake=0+func(ind+1,1,prices,dp);
            profit=max(take,notTake);
        }
        else{
            // sell
            int sell=prices[ind]+func(ind+1,1,prices,dp);
            int notSell=0+func(ind+1,0,prices,dp);
            profit=max(sell,notSell);
        }

        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return func(0,1,prices,dp);

        // 1--> to buy
        // 0--> not buy

        // TC: O(2^N) -->RECURSION
        // SC: O(N)

        // TC: O(N*2) -->DP
        // SC: O(N*2) + O(N)
    }
};


// // TABULATION
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));

//         dp[n][0]=dp[n][1]=0;
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                 int profit=0;
//                 if(buy){
//                     // buy
//                     int take= -prices[ind]+dp[ind+1][0];
//                     int notTake=0+dp[ind+1][1];
//                     profit=max(take,notTake);
//                 }
//                 else{
//                     // sell
//                     int sell=prices[ind]+dp[ind+1][1];
//                     int notSell=0+dp[ind+1][0];
//                     profit=max(sell,notSell);
//                 }
//                 dp[ind][buy]=profit;
//             }
//         }

//         return dp[0][1];
//     }
// };


// // SPACE OPTIMISATION
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<int>ahead(2,0),curr(2,0);

//         ahead[0]=ahead[1]=0;
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                 int profit=0;
//                 if(buy){
//                     // buy
//                     int take= -prices[ind]+ahead[0];
//                     int notTake=0+ahead[1];
//                     profit=max(take,notTake);
//                 }
//                 else{
//                     // sell
//                     int sell=prices[ind]+ahead[1];
//                     int notSell=0+ahead[0];
//                     profit=max(sell,notSell);
//                 }
//                 curr[buy]=profit;
//             }
//             ahead=curr;
//         }

//         return ahead[1];
//     }
// };