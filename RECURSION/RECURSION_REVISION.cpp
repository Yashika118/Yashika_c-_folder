// #include <iostream>
// #include <math.h>
// using namespace std;

// bool kyanumdaalsaktehai(int mat[9][9], int i, int j, int num, int n)
// {
//     // row m toh vo num nahi hai
//     for (int a = 0; a < n; a++)
//     {
//         if (mat[i][a] == num)
//         {
//             return false;
//         }
//     }
//     // col m toh vo num nahi hai
//     for (int b = 0; b < n; b++)
//     {
//         if (mat[b][j] == num)
//         {
//             return false;
//         }
//     }

//     // root(n)*root(n) matrix m toh vo num nahi hai
//     int p = sqrt(n);
//     int si = (i / p) * p;
//     int sj = (j / p) * p;
//     for (int c = si; c < (si + p); c++)
//     {
//         for (int d = sj; d < si + p; d++)
//         {
//             if (mat[c][d] == num)
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// bool sudokusolver(int mat[9][9], int i, int j, int n)
// {
//     // base case
//     if (i == n)
//     {
//         for (int k = 0; k < n; k++)
//         {
//             for (int l = 0; l < n; l++)
//             {
//                 cout << mat[k][l] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//         return true;
//     }

//     // recursive case
//     if (j == 9)
//     {
//         return sudokusolver(mat, i + 1, 0, n);
//     }
//     if (mat[i][j] != 0)
//     {
//         return sudokusolver(mat, i, j + 1, n);
//     }

//     for (int num = 1; num <= 9; num++)
//     {
//         if (kyanumdaalsaktehai(mat, i, j, num, n) == true)
//         {
//             mat[i][j] = num;

//             bool kyaaageseansmila = sudokusolver(mat, i, j + 1, n);
//             if (kyaaageseansmila == true)
//             {
//                 return true;
//             }

//             mat[i][j] = 0;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int mat[9][9] = {
//         {5, 3, 0, 0, 7, 0, 0, 0, 0},
//         {6, 0, 0, 1, 9, 5, 0, 0, 0},
//         {0, 9, 8, 0, 0, 0, 0, 6, 0},
//         {8, 0, 0, 0, 6, 0, 0, 0, 3},
//         {4, 0, 0, 8, 0, 3, 0, 0, 1},
//         {7, 0, 0, 0, 2, 0, 0, 0, 6},
//         {0, 6, 0, 0, 0, 0, 2, 8, 0},
//         {0, 0, 0, 4, 1, 9, 0, 0, 5},
//         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

//     sudokusolver(mat, 0, 0, 9);

//     return 0;
// }

// TOWER OF HANOI
// #include <iostream>
// using namespace std;
// int count = 0;
// void toh(int N, char src, char helper, char dest)
// {
//     // base case
//     if (N == 0)
//     {
//         return;
//     }

//     // recursive case
//     toh(N - 1, src, dest, helper);
//     cout << "Move " << N << "th disc from T" << src << " to T" << dest << endl;
//     count++;
//     toh(N - 1, helper, src, dest);
// }
// int main()
// {
//     int N;
//     cin >> N;

//     toh(N, '1', '3', '2');
//     cout << count << endl;
// }

// #include <iostream>
// using namespace std;
// int convertstringtoint(string s, int len)
// {
//     // base case
//     if (len == 0)
//     {
//         return 0;
//     }

//     // recursive case
//     char ch = s[len - 1];
//     int x = ch - '0';
//     int y = convertstringtoint(s, len - 1);
//     return (y * 10) + x;
// }
// int main()
// {
//     string s;
//     cin >> s;

//     int len = s.length();
//     cout << convertstringtoint(s, len);
// }

// #include <iostream>
// using namespace std;
// void pattern(int n, int row,int countstar)
// {
//     // base case
//     if (n == 0)
//     {
//         return;
//     }

// int row = 1;

// while (row <= n)
// {
//     int countstar = 1;
//     while (countstar <= row)
//     {
//         cout << '*' << " ";
//         countstar++;
//     }
//     cout << endl;
//     row++;
// }

// recursive case
// int countstar = 1;
// while (countstar <= row)
// {
//     cout << '*' << " ";
//     countstar++;
// }
// cout << endl;

//     if (countstar <= row)
//     {
//         cout << "*"<< " ";
//         pattern(n, row, countstar + 1);
//     }
//     cout << endl;
//     pattern(n - 1, row + 1,countstar);
// }
// int main()
// {
//     int n;
//     cin >> n;

//     pattern(n, 1,1);
// }

// codes of string
// #include <iostream>
// using namespace std;
// int numtostring(string s, int len)
// {
//     int num = s[len - 1];
//     int Num = 97;
//     char ch = Num;
//     int number = 1;
//     while (number <= 26)
//     {

//         if (number != num)
//         {
//             Num++;
//         }
//         if (num == number)
//         {
//             // cout << ch;
//             return Num;
//         }

//         number++;
//     }
//     // cout << ch;
//     // return Num;
// }

// void codesofthestring(string s, int len)
// {
//     // base case

//     // recursive case
//     numtostring(s, len);
//     codesofthestring(s, len - 1);

// }
// int main()
// {
//     string s;
//     cin >> s;
//     int len = s.length();

//     codesofthestring(s, len);
//     char character = numtostring(s, len);
//     cout << character;
// }

#include <iostream>
using namespace std;
numtochar(string s, int len)
{
    int num = s[len - 1];
    int Num = 97;
    char ch = Num;
    int number = 1;
    while (number <= 26)
    {

        if (number != num)
        {
            Num++;
        }
        if (num == number)
        {
            // cout << ch;
            return Num;
        }

        number++;
    }
    // cout << ch;
    // return Num;
}

string codesofthestring(string s, int len)
{
    // base case
    if (len == 0)
    {
        return " ";
    }
    // recursive case
    // zra chota kaam
    numtochar(s, len);
    string ans = codesofthestring(s, len - 2) + s[len - 1];
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    codesofthestring(s, len);
}