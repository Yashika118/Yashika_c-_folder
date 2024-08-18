// CODING NINJA (ROTATE ARRAY)
// BRUTE FORCE
// OPTIMAL SOL
#include <bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    // vector<int>:: iterator it=arr.begin();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());

    return arr;
}
