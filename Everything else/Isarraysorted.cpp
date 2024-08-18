#include <iostream>
using namespace std;

bool isarraysortedornot(int arr[10], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }

    return 1;
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

    isarraysortedornot(arr, n);

    if (isarraysortedornot(arr, n) == 0)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}