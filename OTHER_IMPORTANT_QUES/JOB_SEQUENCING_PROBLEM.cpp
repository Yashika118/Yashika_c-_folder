// LS-60
// #include<bits/stdc++.h>
// using namespace std;
// class Solution
// {
//     public:
//     //Function to find the maximum profit and the number of jobs done.
//     static bool cmp(Job a,Job b){
//         return a.profit >b.profit;
//     }
//     vector<int> JobScheduling(Job arr[], int n)
//     {
//         // your code here
//         set<int>days;
//         for(int i=1;i<=100;i++){
//             days.insert(i);
//         }
//         sort(arr,arr+n,cmp);

//         int ans=0;
//         int cnt=0;

//         for(int i=0;i<n;i++){
//             auto ded=arr[i].dead;
//             auto it=days.upper_bound(ded);
//             if(it!=days.begin()){
//                 --it;
//                 ans+=arr[i].profit;
//                 cnt++;
//                 days.erase(it);
//             }
//         }
//         return {cnt,ans};
//     }
// };