#include <bits/stdc++.h>
using namespace std;
void mergetwosortedarr(int arr[], int low, int high, int mid)
{
    int temp[1000];
    int k = low;
    // base case

    // recursive case
    int left = low;
    int right = high;
    while (left <= mid and right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k] = arr[left];
            left++;
            k++;
        }
        else
        {
            temp[k] = arr[right];
            right++;
            k++;
        }
    }

    while (left <= mid)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }

    while (right <= high)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}
void mergesort(int arr[], int n, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // recursive case
    int mid = (s + e) / 2;
    mergesort(arr, n, s, mid);
    mergesort(arr, n, mid + 1, e);
    mergetwosortedarr(arr, s, e, mid);
}
int main()
{
    int arr[] = {3, 2, 4, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    mergesort(arr, n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}