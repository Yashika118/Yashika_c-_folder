// LS-59
// agr rec call m ek hi variable change hota h toh usse 1D dp kehte h
// agr rec call m 2  variables change hote h toh usse 2D dp kehte h
#include <bits/stdc++.h>
using namespace std;
int maxprofitaftersellingwinebottles(int *cost, int n, int left, int right, int day)
{
    // base case
    if (left > right)
    {
        return 0;
    }
    // recursive case
    int op1 = cost[left] * day + maxprofitaftersellingwinebottles(cost, n, left + 1, right, day + 1);
    int op2 = cost[right] * day + maxprofitaftersellingwinebottles(cost, n, left, right - 1, day + 1);

    return max(op1, op2);
}
// top down
int tdmaxprofitaftersellingwinebottles(int *cost, int n, int left, int right, int day, int **arr)
{
    // base case
    if (left > right)
    {
        return arr[left][right] = 0;
    }

    if (arr[left][right] != 0)
    {
        return arr[left][right];
    }
    // recursive case
    int op1 = cost[left] * day + tdmaxprofitaftersellingwinebottles(cost, n, left + 1, right, day + 1, arr);
    int op2 = cost[right] * day + tdmaxprofitaftersellingwinebottles(cost, n, left, right - 1, day + 1, arr);

    return arr[left][right] = max(op1, op2);
}

// bottom up
int bottomup(int *cost, int left, int right, int n)
{
    int arr[100][100] = {0};

    // diagonal
    for (int i = 0; i < n; i++)
    {
        arr[i][i] = n * cost[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {

            if (j > i)
            {
                int day = n - (j - i);
                int op1 = day * cost[i] + arr[i + 1][j];
                int op2 = day * cost[j] + arr[i][j - 1];
                arr[i][j] = max(op1, op2);
            }
        }
    }

    return arr[0][n - 1];
}
int main()
{
    int cost[] = {2, 3, 5, 1, 4};
    int n = sizeof(cost) / sizeof(int);

    // dynamically 2D array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // non dynamically array
    // int arr[100][100];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         arr[i][j]=0;
    //     }
    // }

    // cout << tdmaxprofitaftersellingwinebottles(cost, n, 0, n - 1, 1, arr) << endl;
    cout << bottomup(cost, 0, n - 1, n) << endl;
    cout << maxprofitaftersellingwinebottles(cost, n, 0, n - 1, 1) << endl;
}