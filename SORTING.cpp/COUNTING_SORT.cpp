#include <bits/stdc++.h>
using namespace std;
void count_sort(int arr[], int n)
{
    // find max in arr
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    // count frequency of each element of arr
    int count_arr[k + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count_arr[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(int);
    count_sort(arr, n);
}