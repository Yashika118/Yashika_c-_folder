#include <bits/stdc++.h>
using namespace std;

bool mycomp(int a, int b)
{ // --> this is a comparator not a func but work as a func
    return a > b;

    // return a<b;  //--> for increasing order
}
int main()
{
    int arr[] = {3, 6, 5, 7, 4};
    int n = sizeof(arr) / sizeof(int);
    // sort(arr, arr + n); // sort krta h increasing m

    sort(arr, arr + n, mycomp); // decreasing

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}