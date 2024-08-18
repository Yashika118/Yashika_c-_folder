// spoj ka ques h -->website
#include <bits/stdc++.h>
using namespace std;
int minstepsto1(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }

    // recursive case
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    op1 = minstepsto1(n - 1);

    if (n % 2 == 0)
    {
        op2 = minstepsto1(n / 2);
    }

    if (n % 3 == 0)
    {
        op3 = minstepsto1(n / 3);
    }

    return min(op1, min(op2, op3)) + 1;
}

int topdownminstepsto1(int n, int *arr)
{
    // base case
    if (n == 1)
    {
        return arr[n] = 0;
    }

    // calculate krne se pehle check kroge ki already calculate h ya nhi
    if (arr[n] != -1)
    {
        return arr[n];
    }
    // recursive case
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    op1 = topdownminstepsto1(n - 1, arr);

    if (n % 2 == 0)
    {
        op2 = topdownminstepsto1(n / 2, arr);
    }

    if (n % 3 == 0)
    {
        op3 = topdownminstepsto1(n / 3, arr);
    }

    return arr[n] = min(op1, min(op2, op3)) + 1;
}

int bottomupminstepsto1(int n)
{
    int *arr = new int[n + 1];
    arr[0] = -1;
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {

        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        op1 = arr[i - 1];
        if (i % 2 == 0)
        {
            op2 = arr[i / 2];
        }
        if (i % 3 == 0)
        {
            op3 = arr[i / 3];
        }

        arr[i] = min(op1, min(op2, op3)) + 1;
    }
    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return arr[n];
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    cout << topdownminstepsto1(n, arr) << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << bottomupminstepsto1(n) << endl;

    cout << minstepsto1(n) << endl;

    return 0;
}