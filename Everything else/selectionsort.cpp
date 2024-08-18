#include <iostream>
#include <limits.h>
using namespace std;
int smolindx(int arr[1000], int n, int i)
{
    int num = INT_MAX;
    int index;
    for (int j = i; j <= n - 1; j++)
    {
        if (arr[j] < num)
        {
            num = arr[j];
            index = j;
        }
    }
    return index;
}
void selectionsort(int arr[1000], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestindex = smolindx(arr, n, i);
        swap(arr[i], arr[smallestindex]);
    }
}
int main()
{

    int arr[] = {2, 5, 3, 6, 1};
    int n = sizeof(arr) / sizeof(int);

    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}