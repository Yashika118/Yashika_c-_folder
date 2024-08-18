#include <bits/stdc++.h>
using namespace std;
void printlinearly(int i, int n)
{
    // base case
    if (i > n)
    {
        return;
    }
    // recursive case
    cout << i << " ";
    printlinearly(i + 1, n);
}
int main()
{
    int n;
    cin >> n;
    int i = 1;
    printlinearly(i, n);
}