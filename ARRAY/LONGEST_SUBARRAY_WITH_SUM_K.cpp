// //STRIVER'S SHEET-CODING NINJA
// //BRUTE FORCE
// #include <bits/stdc++.h>
// using namespace std;
// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     // Write your code here
//     int maxlen = -1;
//     for (int i = 0; i < a.size(); i++)
//     {
//         long long sum = 0;
//         for (int j = i; j < a.size(); j++)
//         {
//             sum += a[j];
//             // int sum = 0;
//             // for (int m = i; m <= j; m++)  //--> time complexity = o(n^3);
//             // {
//             //     sum += a[m];
//             // }
//             if (sum == k)
//             {
//                 maxlen = max(maxlen, j - i + 1);
//             }
//         }
//     }

//     return maxlen;
//     // now it gives TC:o(n^2);
// }

// // BETTER APPROACH  TC:O(N^2)
// #include <bits/stdc++.h>
// using namespace std;
// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     // Write your code here
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         sum += a[i];
//         if (sum == k)
//         {
//             maxLen = max(maxLen, i + 1);
//         }
//         long long rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if (preSumMap.find(sum) == preSumMap.end())
//         {

//             preSumMap[sum] = i;
//         }
//     }
//     return maxLen;
// }

// // OPTIMAL SOLTION    -->TWO POINTER OR GREEDY APPROACH -->TC=O(2N)
// #include <bits/stdc++.h>
// using namespace std;
// int longestSubarrayWithSumK(vector<int> a, long long k)
// {
//     // Write your code here
//     int left = 0;
//     int right = 0;
//     long long sum = a[0];
//     int maxLen = 0;
//     int n = a.size();
//     while (right < n)
//     {
//         while (left <= right and sum > k)
//         {
//             sum -= a[left];
//             left++;
//         }
//         if (sum == k)
//         {
//             maxLen = max(maxLen, right - left + 1);
//         }
//         right++;
//         if (right < n)
//         {
//             sum += a[right];
//         }
//     }
//     return maxLen;
// }