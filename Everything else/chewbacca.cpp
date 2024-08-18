#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 1;
    while (n)
    {
        int dig = n % 10;
        if (dig > 4)
        {
            dig = 9 - dig;
        }
        ans = ans * 10 + dig;
        n /= 10;
    }
    cout << ans;
}