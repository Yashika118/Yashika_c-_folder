#include <iostream>
using namespace std;

void reverseanarray(int arr[1000000], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return;
}
int main()
{
    int n;
    cin >> n;

    int arr[1000000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseanarray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}