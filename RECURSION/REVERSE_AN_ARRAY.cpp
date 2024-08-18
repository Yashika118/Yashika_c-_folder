#include <bits/stdc++.h>
using namespace std;
// void reverseanarr(int arr[], int n, int i, int j)
// {
//     // base case
//     if (i >= j)
//     {
//         return;
//     }
//     // recursive case
//     swap(arr[i], arr[j]);
//     reverseanarr(arr, n, i + 1, j - 1);
// }
void reverseanarr(int arr[], int n, int i)
{
    // base case
    if (i >= n - i - 1)
    {
        return;
    }
    // recursive case
    swap(arr[i], arr[n - i - 1]);
    reverseanarr(arr, n, i + 1);
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    // reverseanarr(arr, n, 0, n - 1);
    reverseanarr(arr, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}