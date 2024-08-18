#include <iostream>
using namespace std;
void mergetwosortedarray(int arr[], int s, int e)
{
    int temp[1000];
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int k = s;

    while (j <= e & i <= mid)
    {

        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (j <= e)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    // for (int l = 0; l < k; l++)
    // {
    //     cout << temp[l] << " ";
    // }

    // copying back arr form temp to arr
    for (int l = 0; l < k; l++)
    {
        arr[l] = temp[l];
    }
}

void mergesort(int arr[], int s, int e)
{
    // base
    if (s >= e)
    {
        return;
    }

    // recursive case
    // 1step divide through mid
    int mid = (s + e) / 2;

    // 2step sort the array
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    // 3step merge two sorted array
    mergetwosortedarray(arr, s, e);
}
int main()
{
    int arr[] = {7, 2, 9, 2, 1, 4, 6, 0, 9, 11, 15, 10};
    int n = sizeof(arr) / sizeof(int);
    int s = 0;
    int e = n - 1;

    mergesort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
