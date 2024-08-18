// #include <iostream>
// using namespace std;
// int main()
// {

//     // int arr[4][3] = {
//     //     {3, 4, 5},
//     //     {6, 7, 8},
//     //     {9, 10, 11},
//     //     {12, 13, 14}};

//     // input of 2D array
//     int arr[100][100];
//     int i, j;
//     cin >> i >> j;

//     for (int i = 0; i <= 3; i++)
//     {
//         for (int j = 0; j <= 2; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     // Print a 2D array
//     for (int i = 0; i <= 3; i++)
//     {
//         for (int j = 0; j <= 2; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//     }
// }

// FIND A KEY IN A MATRIX
// #include <iostream>
// using namespace std;

// bool tofindkey(int arr[100][100], int key, int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (arr[i][j] == key)
//             {
//                 return true;
//                         }
//         }
//     }
//     return false;
// }

// void printanarray(int arr[100][100], int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
// }
// int main()
// {

//     int arr[100][100];
//     int row, col;
//     cin >> row >> col;

//     printanarray(arr, row, col);

//     int key;
//     cin >> key;

//     if (tofindkey(arr, key, row, col) == true)
//     {
//         cout << "key is present";
//     }
//     else
//     {
//         cout << "key is not present";
//     }
// }

//  SPIRAL WAVE PRINT

// #include <iostream>
// using namespace std;
// int main()
// {

//     int i, j;
//     int arr[100][100];
//     int row, col;
//     cin >> row >> col;
//     int right = 0;
//     int left = row;

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     i = 0;
//     while (i < row)
//     {

//         if (i % 2 == 0)
//         {
//             right = 0;
//             while (right < col)
//             {
//                 cout << arr[i][right];

//                 right++;
//             }
//         }

//         if (i % 2 != 0)
//         {
//             left = col - 1;
//             while (left >= 0)
//             {
//                 cout << arr[i][left];
//                 left--;
//             }
//         }

//         i++;
//     }
// }

// TOP TO BOTTOM WAVE PRINT
// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[100][100];
//     int row, col;
//     cin >> row >> col;
//     int i, j;

//     for (i = 0; i < row; i++)
//     {
//         for (j = 0; j < col; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     j = 0;
//     while (j < col)
//     {

//         if (j % 2 == 0)
//         {
//             int bottom = 0;
//             while (bottom < row)
//             {

//                 cout << arr[bottom][j];
//                 bottom++;
//             }
//         }

//         if (j % 2 != 0)
//         {
//             int top = row - 1;
//             while (top >= 0)
//             {
//                 cout << arr[top][j];
//                 top--;
//             }
//         }

//         j++;
//     }
// }

// // DIAGONAL WAVE PRINT
// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[100][100];
//     int row, col;
//     cin >> row >> col;
//     int i, j;

//     for (i = 0; i < row; i++)
//     {
//         for (j = 0; j < col; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }

//     i = 0;
//     while (i < row)
//     {
//         int ii = i;
//         j = 0;
//         while (ii >= 0)
//         {
//             cout << arr[ii][j];

//             ii--;
//             j++;
//         }

//         i++;
//     }

//     j = 1;
//     while (j <= col - 1)
//     {
//         int ii = row - 1;
//         int jj = j;

//         while (jj < col & ii >= 0)
//         {
//             cout << arr[ii][jj];

//             ii--;
//             jj++;
//         }

//         j++;
//     }
// }
