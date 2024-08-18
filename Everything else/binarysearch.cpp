#include <iostream>
#include <algorithm>
using namespace std;

void tosortanarray(int arr[1000], int n)
{

    sort(arr, arr + n);

    return;
}

int binarysearch(int arr[1000], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid;

    mid = (left + right) / 2;

    while (left <= right)
    {
        if (arr[mid] > target)
        {

            right = mid - 1;
        }

        else if (arr[mid] == target)
        {
            return mid;
        }

        else
        {

            left = mid + 1;
        }

        mid = (left + right) / 2;
    }

    return -1;
}

int main()
{

    int n;
    cin >> n;

    int arr[1000];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    tosortanarray(arr, n);

    cout << binarysearch(arr, n, target);
}