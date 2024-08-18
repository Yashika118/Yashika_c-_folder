#include <iostream>
using namespace std;

int minimumswapstosortanarray(int arr[1000], int n)
{

    int swaps = 0;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= n - 2; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
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

    minimumswapstosortanarray(arr, n);
}