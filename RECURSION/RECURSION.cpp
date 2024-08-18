// #include <iostream>
// using namespace std;

// int fact(int n)
// {
//     // step 1 base case
//     if (n == 0)
//     {
//         return 1;
//     }

//     // step 2 recursive case
//     int chotaans = fact(n - 1);

//     // final ans using step 1 and 2
//     int finalans = n * chotaans;
//     return finalans;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << fact(n);
// }

// #include <iostream>
// using namespace std;

// int fiboofpos(int pos)
// {
//     // base case
//     if (pos == 1)
//     {
//         return 1;
//     }
//     if (pos == 0)
//     {
//         return 0;
//     }

//     // recursive case
//     int finalans = fiboofpos(pos - 1) + fiboofpos(pos - 2);
//     return finalans;
// }
// int main()
// {
//     int pos;
//     cin >> pos;
//     cout << fiboofpos(pos);
// }

// // MULTIPLICATION OF TWO NUMBERS
// #include <iostream>
// using namespace std;
// int multoftwonumbers(int a, int b)
// {
//     // base case
//     if (b == 0)
//     {
//         return 0;
//     }

//     // recursive case
//     int finalans = a + multoftwonumbers(a, b - 1);
//     return finalans;
// }
// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     cout << multoftwonumbers(a, b);
// }

// // IS ARRAY SORTED OR NOT
// // 1st APPROACH
// #include <iostream>
// using namespace std;

// bool isarraysortedornot(int arr[], int n)
// {
//     // base case
//     if (n == 1)
//     {
//         return true;
//     }
//     // recursive case
//     if (arr[0] <= arr[1] & isarraysortedornot(arr + 1, n - 1))
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     int arr[] = {1, 3, 6, 11, 12};
//     int n = sizeof(arr) / sizeof(int);

//     if (isarraysortedornot(arr, n) == true)
//     {
//         cout << "array is sorted";
//     }
//     else
//     {
//         cout << "array is not sorted";
//     }
// }

// 2nd APPROACH
// #include <iostream>
// using namespace std;
// bool isarraysortedornot(int arr[], int n)
// {
//     // base case
//     if (n == 1)
//     {
//         return true;
//     }

//     // recursive case
//     if (isarraysortedornot(arr, n - 1) & arr[n - 2] <= arr[n - 1])
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     int arr[] = {5, 3, 9, 12, 15};
//     int n = sizeof(arr) / sizeof(int);

//     if (isarraysortedornot(arr, n) == true)
//     {
//         cout << "array is sorted";
//     }
//     else
//     {
//         cout << "array is not sorted";
//     }
// }

// 3rd APPROACH
// #include <iostream>
// using namespace std;
// bool isarraysortedornot(int arr[], int n, int i)
// {
//     // base case
//     if (i == n - 1)
//     {
//         return true;
//     }

//     // recursive case
//     if (arr[i] <= arr[i + 1] & isarraysortedornot(arr, n, i + 1))
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     int arr[] = {5, 3, 9, 12, 15};
//     int n = sizeof(arr) / sizeof(int);
//     int i = 0;
//     if (isarraysortedornot(arr, n, i) == true)
//     {
//         cout << "array is sorted";
//     }
//     else
//     {
//         cout << "array is not sorted";
//     }
// }

// SUM OF ELEMENTS OF ARRAY
// #include <iostream>
// using namespace std;
// int sumofelements(int arr[], int n)
// {
//     // base case
//     if (n == 1)
//     {
//         return arr[0];
//     }

//     // recursive case
//     return sumofelements(arr, n - 1) + arr[n - 1];
// }
// int main()
// {
//     int arr[] = {2, 4, 2, 6};
//     int n = sizeof(arr) / sizeof(int);

//     cout << sumofelements(arr, n);
// }

// DECREASING ORDER PRINT FROM N-->1
// #include <iostream>
// using namespace std;
// void decorder(int n)
// {
//     // base case
//     if (n == 0)
//     {
//         return;
//     }

//     // recursive case
//     cout << n << " ";
//     decorder(n - 1);
// }
// int main()
// {
//     int n;
//     cin >> n;

//     decorder(n);
// }

// INCREASING ORDER PRINT FROM 1-->N
// #include <iostream>
// using namespace std;
// void incorder(int n)
// {
//     // base case
//     if (n == 0)
//     {
//         return;
//     }

//     // recursive case
//     incorder(n - 1);
//     cout << n << " ";
// }
// int main()
// {
//     int n;
//     cin >> n;

//     incorder(n);

//     return 0;
// }

// CALCULATE X^n USING RECURSION
// #include <iostream>
// using namespace std;
// int xpowern(int x, int n)
// {
//     // base case
//     if (n == 0)
//     {
//         return 1;
//     }
//     // recursive case
//     return x * xpowern(x, n - 1);`
// }
// int main()
// {
//     int x, n;
//     cin >> x >> n;

//     cout << xpowern(x, n);
// }

// array check 7
// #include <iostream>
// using namespace std;

// int lastindexof7(int arr[], int n, int i)
// {
//     // base case
//     if (n == 0)
//     {
//         return -1;
//     }

//     // recursive case
//     if (arr[i] == 7)
//     {
//         return i;
//     }
//     lastindexof7(arr, n - 1, i - 1);
// }
// int main()
// {
//     int arr[] = {3, 7, 1, 7, 6};
//     int n = sizeof(arr) / sizeof(int);
//     int i = n - 1;

//     int ans = lastindexof7(arr, n, i);

//     if (lastindexof7(arr, n, i) != -1)
//     {
//         cout << "7 is present at index " << ans << endl;
//     }
//     else
//     {
//         cout << "7 is not present";
//     }

//     return 0;
// }

// print all indices of 7
// #include <iostream>
// using namespace std;

// void allindicesof7(int arr[], int n, int i)
// {
//     // base case
//     if (i == n)
//     {
//         return;
//     }

//     // recursive case
//     if (arr[i] == 7)
//     {
//         cout << i << " ";
//     }

//     allindicesof7(arr, n, i + 1);
// }
// int main()
// {
//     int arr[] = {3, 7, 1, 7, 6};
//     int n = sizeof(arr) / sizeof(int);
//     int i = 0;

//     allindicesof7(arr, n, i);
// }

// string to integer
// #include <iostream>
// using namespace std;

// int stringtoint(string s, int len)
// {
//     // base case
//     if (len == 0)
//     {
//         return 0;
//     }

//     // recursive case
//     char ch = s[len - 1]; //-->'1'
//     int x = ch - '0';
//     int y = stringtoint(s, len - 1);
//     return y * 10 + x;
// }
// int main()
// {
//     string s; // -->"231"
//     cin >> s;

//     int len = s.length();
//     cout << stringtoint(s, len);
// } ---> we can also do it by using substring

// TOWER OF HANOI
// #include <iostream>
// using namespace std;

// void toh(int n, char src, char helper, char dest)
// {
//     // base case
//     if (n == 0)
//     {
//         return;
//     }

//     // recursive case
//     toh(n - 1, src, dest, helper);
//     cout << "move disk no " << n << " from " << src << " to " << dest << endl;

//     toh(n - 1, helper, src, dest);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int count = 0;

//     toh(n, 'A', 'B', 'C');

// }

// BUBBLESORT USING RECURSION
// BUBBLE SORT ALGORITHM WITHOUT RECURSION
// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[] = {5, 4, 3, 2, 1};
//     int n = sizeof(arr) / sizeof(int);

//     for (int i = 0; i <= n - 2; i++)
//     {
//         for (int j = 0; j <= n - 2 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }

//     for (int i = 0; i <= n - 1; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// BUBBLE SORT USING RECURSION
// #include <iostream>
// using namespace std;
// void bubblesortrec(int arr[], int n, int i)
// {
//     // base case
//     if (i == n - 1)
//     {
//         return;
//     }

//     // recursive case
//     for (int j = 0; j <= n - 2 - i; j++)
//     {
//         if (arr[j] > arr[j + 1])
//         {
//             swap(arr[j], arr[j + 1]);
//         }
//     }
//     bubblesortrec(arr, n, i + 1);
// }
// int main()
// {
//     int arr[] = {5, 4, 3, 2, 1};
//     int n = sizeof(arr) / sizeof(int);

//     bubblesortrec(arr, n, 0);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// BUBBLESORT USING RECURSION WITHOUT USING ANY LOOP
// #include <iostream>
// using namespace std;
// void bubblesortrec(int arr[], int n, int i, int j)
// {
//     // base case
//     if (i == n - 1)
//     {
//         return;
//     }

//     if (j == n - 1 - i)
//     {
//         bubblesortrec(arr, n, i + 1, 0);
//     }
//     else
//     {
//         if (arr[j] > arr[j + 1])
//         {
//             swap(arr[j], arr[j + 1]);
//         }

//         bubblesortrec(arr, n, i, j + 1);
//     }
// }

// int main()
// {
//     int arr[] = {5, 4, 3, 2, 1};
//     int n = sizeof(arr) / sizeof(int);

//     bubblesortrec(arr, n, 0, 0);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// MOVE ALL x AT END
// #include <iostream>
// using namespace std;

// string moveallxatend(string s)
// {
//     // base case
//     if (s.length() == 0)
//     {
//         return "";
//     }

//     // recursive case
//     string chotaans = moveallxatend(s.substr(1));
//     char ch = s[0];
//     if (ch == 'x')
//     {
//         return chotaans + ch;
//     }
//     else
//     {
//         return ch + chotaans;
//     }
// }
// int main()
// {
//     string s = "abxcxxd";
//     int len = s.length();

//     cout << moveallxatend(s);

//     return 0;
// }

//  REPLACE ALL PI
// #include <iostream>
// using namespace std;

// string removeallpi(string s)
// {
//     // base case
//     if (s.length() == 0)
//     {
//         return "";
//     }
//     if (s.length() == 1)
//     {
//         return s;
//     }

//     // recursive case
//     string chotistring = s.substr(0, 2);
//     if (chotistring == "pi")
//     {
//         return "3.14" + removeallpi(s.substr(2));
//     }
//     else
//     {
//         return s[0] + removeallpi(s.substr(1));
//     }
// }
// int main()
// {

//     string s = "apiixpiip";

//     cout << removeallpi(s);

//     return 0;
// }

// PRINT SUBSEQUENCES OF A STRING
// #include <iostream>
// using namespace std;
// void subsequences(char inarr[], int i, char outarr[], int j)
// {
//     // base case
//     if (inarr[i] == '\0')
//     {
//         outarr[j] = '\0';
//         cout << outarr << endl;
//         return;
//     }

//     // recursive case
//     // without a
//     subsequences(inarr, i + 1, outarr, j);

//     // with a
//     outarr[j] = inarr[i];
//     subsequences(inarr, i + 1, outarr, j + 1);
// }
// int main()
// {
//     char inarr[1000];
//     cin >> inarr;
//     char outarr[1000];

//     subsequences(inarr, 0, outarr, 0);
// }

// PERMUTATION OF STRING
// #include <iostream>
// using namespace std;
// void permutation(char inpu[], int i)
// {
//     // base case
//     if (inpu[i] == '\0')
//     {
//         cout << inpu << endl;
//         return;
//     }

//     // recursive case
//     for (int j = 0; inpu[j] != '\0'; j++)
//     {
//         swap(inpu[i], inpu[j]);
//         permutation(inpu, i + 1);
//         swap(inpu[i], inpu[j]);
//     }
// }
// int main()
// {
//     char inpu[1000];
//     cin >> inpu;
//     permutation(inpu, 0);

//     return 0;
// }

// RATE IN A MAZE (print single path)
// #include <iostream>
// using namespace std;
// int sol[100][100] = {0}; // global variable

// bool ratinamaze(char maze[50][50], int r, int c, int i, int j)
// {
//     // base case
//     if (i == r - 1 and j == c - 1)
//     {
//         sol[i][j] = 1;
//         for (int a = 0; a < r; a++)
//         {
//             for (int k = 0; k < c; k++)
//             {
//                 cout << sol[a][k] << " ";
//             }
//             cout << endl;
//         }

//         return true;
//     }

//     // recursive case
//     sol[i][j] = 1;
//     // forward move
//     if (j <= c - 2 and maze[i][j + 1] != 'X')
//     {
//         // aage ja sakti hu
//         bool kyaaageseansmila = ratinamaze(maze, r, c, i, j + 1);
//         if (kyaaageseansmila == true)
//         {
//             return true;
//         }
//     }

//     // downward
//     if (i <= r - 2 and maze[i + 1][j] != 'X')
//     {
//         // niche ja skti hu
//         bool kyanicheseansmila = ratinamaze(maze, r, c, i + 1, j);
//         if (kyanicheseansmila == true)
//         {
//             return true;
//         }
//     }

//     sol[i][j] = 0;
//     return false;
// }
// int main()
// {

//     char maze[50][50] = {
//         "0000",
//         "0X00",
//         "00XX",
//         "0000"};

//     int r = 4, c = 4;

//     ratinamaze(maze, r, c, 0, 0);
// }

// RAT IN A MAZE (PRINT ALL PATHS)
// #include <iostream>
// using namespace std;
// int sol[100][100] = {0}; // global variable

// bool ratinamaze(char maze[50][50], int r, int c, int i, int j)
// {
//     // base case
//     if (i == r - 1 and j == c - 1)
//     {
//         sol[i][j] = 1;
//         for (int a = 0; a < r; a++)
//         {
//             for (int k = 0; k < c; k++)
//             {
//                 cout << sol[a][k] << " ";
//             }
//             cout << endl;
//         }

//         cout << endl;
//         sol[i][j] = 0;

//         return false;
//     }

//     // recursive case
//     sol[i][j] = 1;
//     // forward move
//     if (j <= c - 2 and maze[i][j + 1] != 'X')
//     {
//         // aage ja sakti hu
//         bool kyaaageseansmila = ratinamaze(maze, r, c, i, j + 1);
//         if (kyaaageseansmila == true)
//         {
//             return true;
//         }
//     }

//     // downward
//     if (i <= r - 2 and maze[i + 1][j] != 'X')
//     {
//         // niche ja skti hu
//         bool kyanicheseansmila = ratinamaze(maze, r, c, i + 1, j);
//         if (kyanicheseansmila == true)
//         {
//             return true;
//         }
//     }

//     sol[i][j] = 0;
//     return false;
// }
// int main()
// {

//     char maze[50][50] = {
//         "0000",
//         "0X00",
//         "00XX",
//         "0000"};

//     int r = 4, c = 4;

//     ratinamaze(maze, r, c, 0, 0);
// }

// N STAIR CASE with max no. of steps,k=3
// #include <iostream>
// using namespace std;
// int nstaircase(int n)
// {
//     // base case
//     // if (n == 2)
//     // {
//     //     return 2;
//     // }
//     // if (n == 1)
//     // {
//     //     return 1;
//     // }
//     // if (n == 0)
//     // {
//     //     return 1;
//     // }

//     if (n == 0)
//     {
//         return 1;
//     }
//     if (n < 0)
//     {
//         return 0;
//     }
//     // recursive case
//     return nstaircase(n - 1) + nstaircase(n - 2) + nstaircase(n - 3);
// }
// int main()
// {

//     int n;
//     cin >> n;
//     cout << nstaircase(n) << endl;
// }

// N STAIR CASE WITH ANY VALUE OF K
// #include <iostream>
// using namespace std;
// int nstaircase(int n, int k)
// {
//     // base case
//     // if (n == 2)
//     // {
//     //     return 2;
//     // }
//     // if (n == 1)
//     // {
//     //     return 1;
//     // }
//     // if (n == 0)
//     // {
//     //     return 1;
//     // }

//     if (n == 0)
//     {
//         return 1;
//     }
//     if (n < 0)
//     {
//         return 0;
//     }
//     // recursive case
//     // return nstaircase(n - 1) + nstaircase(n - 2) + nstaircase(n - 3);

//     int sum = 0;
//     for (int i = 1; i <= k; i++)
//     {
//         sum = sum + nstaircase(n - i, k);
//     }
//     return sum;
// }
// int main()
// {
//     int k;
//     cin >> k;
//     int n;
//     cin >> n;
//     cout << nstaircase(n, k) << endl;
// }

//  N QUEENS
// #include <iostream>
// using namespace std;
// int c = 0;
// bool kyaqueendalsakteh(int board[50][50], int i, int j, int n)
// {
//     for (int l = 0; l < i; l++)
//     {
//         if (board[l][j] == 1)
//         {
//             return false;
//         }
//     }

//     for (int k = 0; k < j; k++)
//     {
//         if (board[i][k] == 1)
//         {
//             return false;
//         }
//     }

//     int u = i;
//     int v = j;

//     i--;
//     j++;
//     while (i >= 0 and j < n)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//         i--;
//         j++;
//     }

//     u--;
//     v--;

//     while (u >= 0 and v >= 0)
//     {
//         if (board[u][v] == 1)
//         {
//             return false;
//         }

//         u--;
//         v--;
//     }

//     return true;
// }

// bool nqueens(int board[50][50], int n, int i)
// {
//     // base case
//     if (i == n)
//     {
//         c++;
//         for (int p = 0; p < n; p++)
//         {
//             for (int a = 0; a < n; a++)
//             {
//                 if (board[p][a] == 1)
//                 {
//                     cout << 'Q';
//                 }
//                 else
//                 {
//                     cout << "_";
//                 }
//             }
//             cout << endl;
//         }
//         // return true;
//         cout << endl;
//         return false;
//     }

//     // recursive case
//     for (int j = 0; j < n; j++)
//     {
//         if (kyaqueendalsakteh(board, i, j, n) == true)
//         {
//             board[i][j] = 1;
//             bool bakikaansmila = nqueens(board, n, i + 1);
//             if (bakikaansmila == true)
//             {
//                 return true;
//             }

//             board[i][j] = 0;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int board[50][50] = {0};
//     int n;
//     cin >> n;

//     nqueens(board, n, 0);
//     cout << c << endl;
// }

// // SUDUKO SOLVER
// #include <bits/stdc++.h>
// using namespace std;
// bool kyawonumberdalsaktehai(int mat[9][9], int num, int i, int j, int n)
// {
//     // row num tou nahi hai
//     for (int k = 0; k < n; k++)
//     {
//         if (mat[i][k] == num)
//         {
//             return false;
//         }
//     }
//     // col mai wo num tou nahi hai
//     for (int l = 0; l < n; l++)
//     {
//         if (mat[l][j] == num)
//         {
//             return false;
//         }
//     }
//     // root(n)*root(n) mai wo num tou nahi hai

//     int p = sqrt(n);      // 3
//     int si = (i / p) * p; // 3
//     int sj = (j / p) * p; // 6

//     for (int a = si; a < si + p; a++)
//     { // 4
//         for (int b = sj; b < sj + p; b++)
//         { // 8
//             if (mat[a][b] == num)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// bool sudukosolver(int mat[9][9], int i, int j, int n)
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
//         // return true;
//         return false;
//     }
//     // recursive case
//     if (j == n)
//     {
//         return sudukosolver(mat, i + 1, 0, n);
//     }
//     if (mat[i][j] != 0)
//     {
//         // else{
//         return sudukosolver(mat, i, j + 1, n);
//     }

//     for (int num = 1; num <= 9; num++)
//     { // 10
//         if (kyawonumberdalsaktehai(mat, num, i, j, n) == true)
//         {
//             mat[i][j] = num;
//             bool kyaaageansmila = sudukosolver(mat, i, j + 1, n); // false
//             if (kyaaageansmila == true)
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
//     int mat[9][9] =
//         {{0, 3, 0, 0, 7, 0, 0, 0, 0},
//          {6, 0, 0, 1, 9, 5, 0, 0, 0},
//          {0, 9, 8, 0, 0, 0, 0, 6, 0},
//          {8, 0, 0, 0, 6, 0, 0, 0, 3},
//          {4, 0, 0, 8, 0, 3, 0, 0, 1},
//          {7, 0, 0, 0, 2, 0, 0, 0, 6},
//          {0, 6, 0, 0, 0, 0, 2, 8, 0},
//          {0, 0, 0, 4, 1, 9, 0, 0, 5},
//          {0, 0, 0, 0, 8, 0, 0, 7, 9}};

//     sudukosolver(mat, 0, 0, 9);

//     return 0;
// }
// ELEPHANT IN CHESS TOATAL NO. OF WAYS IT CAN REACH TO NTH CELL
// #include <iostream>
// using namespace std;

// int noofways(int n, int m)
// {
//     // base case
//     if (n == 0)
//     {
//         return 1;
//     }

//     if (m == 0)
//     {
//         return 1;
//     }

//     // recursive case
//     return noofways(n - 1, m) + noofways(n, m - 1);
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     cout << noofways(n, m) << endl;

//     return 0;
// }
