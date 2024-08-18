// #include <bits/stdc++.h>
// using namespace std;
// // PARAMETERISED WAY
// void sumoffirstnnums(int i, int sum)
// {
//     // base case
//     if (i == 0)
//     {
//         cout << sum << endl;
//         return;
//     }
//     // recursive case
//     sumoffirstnnums(i - 1, sum + i);
// }
// int main()
// {
//     int i;
//     cin >> i;
//     sumoffirstnnums(i, 0);
// }

// WITHOUT PARAMETER
#include <bits/stdc++.h>
using namespace std;
int sumoffirstnnums(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    // recursive case
    return n + sumoffirstnnums(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << sumoffirstnnums(n) << endl;
}