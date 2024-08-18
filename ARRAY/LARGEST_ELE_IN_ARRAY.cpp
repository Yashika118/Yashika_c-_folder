// BRUTE FORCE APPROACH
// using sorting (bubble sort or any other)

// OPTIMAL APPROACH  (TC-->O(N))
#include <bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &arr, int n)
{
    // Write your code here.
    int lar = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > lar)
        {
            lar = arr[i];
        }
    }
    return lar;
}
