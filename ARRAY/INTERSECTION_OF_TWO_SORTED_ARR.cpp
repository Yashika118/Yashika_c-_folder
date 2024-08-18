// // BRUTE FORCE
// // TC: O(N1*N2);
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
//     // Write your code here.
//     vector<int> ans;
//     int n1 = n;
//     int n2 = m;
//     int visited[n2] = {0};

//     for (int i = 0; i < n1; i++)
//     {
//         for (int j = 0; j < n2; j++)
//         {
//             if (arr1[i] == arr2[j] and visited[j] == 0)
//             {
//                 ans.push_back(arr1[i]);
//                 visited[j] = 1;
//                 break;
//             }
//             if (arr2[j] > arr1[i])
//             {
//                 break;
//             }
//         }
//     }

//     return ans;
// }

// OPTIMAL SOL  -->TC:O(N1+N2)
#include <bits/stdc++.h>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < n and j < m)
    {

        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return ans;
}
