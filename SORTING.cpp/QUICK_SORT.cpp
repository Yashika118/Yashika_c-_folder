// DIVIDE AND CONQUER ALGORITHM
#include <bits/stdc++.h>
using namespace std;
int func(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot and i <= high - 1)
        {
            i++;
        }

        while (arr[j] >= pivot and j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int parindex = func(arr, low, high);
        quicksort(arr, low, parindex - 1);
        quicksort(arr, parindex + 1, high);
    }
}
int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}