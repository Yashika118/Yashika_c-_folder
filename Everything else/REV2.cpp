// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     int ans = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         ans = ans * i;
//     }

//     return ans;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     cout << factorial(n) << endl;
// }

// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     int ans = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         ans = ans * i;
//     }
//     return ans;
// }

// int findncr(int n, int r)
// {
//     int ncr;
//     ncr = factorial(n) / ((factorial(r)) * factorial(n - r));

//     return ncr;
// }

// int main()
// {
//     int n;
//     int r;
//     cin >> n;
//     cin >> r;

//     cout << findncr(n, r) << endl;
// }

// CALL BY VALUE
// #include <iostream>
// using namespace std;

// int update(int a)
// {
//     a = a + 20;
//     return a;
// }
// int main()
// {
//     int a;
//     cin >> a;

//     cout << update(a);
// }
