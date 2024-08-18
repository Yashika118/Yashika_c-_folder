#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[1000];
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    int value;
    cin >> value;
    int position;
    cin >> position;
    int k = n;
    int ub = n;
    while (k >= position)
    {
        arr[k + 1] = arr[k];
        k--;
    }
    ub = ub + 1;
    arr[position] = value;

    for (int i = 0; i < ub; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}