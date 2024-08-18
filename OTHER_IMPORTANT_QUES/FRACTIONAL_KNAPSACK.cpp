// LS-60
// // FRACTIONAL KNAPSACK
// // value[]={60,100,120};   weight[]={10,20,30};
// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     // Function to get the maximum total value in the knapsack.
//     static bool cmp(Item a, Item b)
//     {
//         return (a.value * 1.0) / a.weight > (b.value * 1.0) / b.weight;
//     }
//     double fractionalKnapsack(int W, Item arr[], int n)
//     {
//         // Your code here
//         double ans = 0;
//         sort(arr, arr + n, cmp);
//         for (int i = 0; i < n; i++)
//         {
//             if (W >= arr[i].weight)
//             {
//                 ans += arr[i].value;
//                 W -= arr[i].weight;
//             }
//             else
//             {
//                 ans += W * ((arr[i].value * 1.0) / arr[i].weight);
//                 break;
//             }
//         }

//         return ans;
//     }
// };