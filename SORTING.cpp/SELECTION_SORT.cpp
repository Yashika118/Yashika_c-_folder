#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {4, 3, 1, 6, 2};
    int n = sizeof(arr) / sizeof(int);

    for (int pos = 0; pos < n - 1; pos++)
    {
        int min = pos;

        for (int j = pos + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[pos], arr[min]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}