#include<bits/stdc++.h>
using namespace std;
int func(int day,int last,int n,vector<vector<int>>points,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int p=points[day][i]+func(day-1,i,n,points,dp);
            maxi=max(maxi,p);
        }
    }

    return dp[day][last]=maxi;

}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return func(n-1,3,n,points,dp);
//  TC:O(N*4)*3
//  SC:O(N)+O(N*4);

}


// TABULATION
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>>dp(n,vector<int>(4,-1));
//     dp[0][0]=max(points[0][1],points[0][2]);
//     dp[0][1]=max(points[0][0],points[0][2]);
//     dp[0][2]=max(points[0][0],points[0][1]);
//     dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

//     for(int day=1;day<n;day++){
//         for(int last=0;last<4;last++){
//             dp[day][last]=0;
//             int maxi=0;
//             for(int task=0;task<3;task++){
//                 if(task!=last){
//                     int p=points[day][task]+dp[day-1][task];
//                     maxi=max(maxi,p);
//                 }
//             }
//             dp[day][last]=maxi;
//         }
//     }
//     return dp[n-1][3];
//  // TC:O(N*4*3)
//  // SC:O(N*4)
// }



// SPACE OPTIMISATION
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<int>prev(4,0);
//     prev[0]=max(points[0][1],points[0][2]);
//     prev[1]=max(points[0][0],points[0][2]);
//     prev[2]=max(points[0][0],points[0][1]);
//     prev[3]=max(points[0][1],max(points[0][1],points[0][2]));

//     for(int day=1;day<n;day++){
//         vector<int>temp(4,0);
//         for(int last=0;last<4;last++){
//             temp[last]=0;
//             for(int task=0;task<3;task++){
//                 if(task!=last){
//                     temp[last]=max(temp[last],points[day][task]+prev[task]);
//                 }
//             }
            
//         }
//         prev=temp;
//     }
//     return prev[3];
//  // TC:O(N*4*3)
//  // sc: o(4)
// }
