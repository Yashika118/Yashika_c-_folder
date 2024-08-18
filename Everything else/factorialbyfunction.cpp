#include <iostream>
using namespace std;

int factorial(int n)
{
    int ans = 1;

    for (int i = n; i > 0; i--)
    {
        ans = ans * i;
    }

    return ans;
}

int ncr(int n, int r)
{

    int ncr = factorial(n) / (factorial(r) * factorial(n - r));

    return ncr;
}

int main()
{

    int n;
    int r;
    cin >> n;
    cin >> r;

    cout << factorial(n) << endl;

    cout << ncr(n, r) << endl;
}