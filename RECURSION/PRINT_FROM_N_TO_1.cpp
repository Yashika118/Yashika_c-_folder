#include <bits/stdc++.h>
using namespace std;
void printfromnto1(int n)
{
    // base case
    if (n <= 0)
    {
        return;
    }
    // recursive case
    cout << n << " ";
    printfromnto1(n - 1);
}
int main()
{
    int n;
    cin >> n;
    printfromnto1(n);
}