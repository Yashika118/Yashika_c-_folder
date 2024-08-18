// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int row = 1;

//     while (row <= n)
//     {
//         int count = 1;
//         while (count <= row)
//         {
//             cout << "* ";
//             count++;
//         }
//         cout << endl;
//         row++;
//     }
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     int n;
//     cin >> n;
//     int row = 1;

//     while (row <= n)
//     {
//         int space = 1;
//         while (space <= n - row)
//         {
//             cout << "  ";
//             space++;
//         }

//         int incou = 1;
//         int inc = row;
//         while (incou <= row)
//         {
//             cout << inc << " ";
//             inc++;
//             incou++;
//         }
//         // cout << endl;

//         int decou = 1;
//         int dec = 2 * row - 2;
//         while (decou <= (row - 1))
//         {
//             cout << dec << " ";
//             dec--;
//             decou++;
//         }
//         cout << endl;

//         row++;
//     }
// }

// #include <iostream>
// #include <limits.h>
// using namespace std;
// int main()
// {
//     int n;
//     int largest = INT_MIN;
//     int count = 1;
//     cin >> n;

//     while (count <= n)
//     {
//         int num;
//         cin >> num;
//         if (num > largest)
//         {
//             largest = num;
//         }
//         count++;
//     }

//     cout << largest;
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[100];
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[100] = {3, 4, 5, 2, 1};
//     for (int i = 0; i <= 4; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[100];
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     // reverse an array
//     for (int j = n - 1; j >= 0; j--)
//     {
//         cout << arr[j] << " ";
//     }
//     cout << endl;
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[] = {12, 10, 42, 31, 11};
//     int n = sizeof(arr) / sizeof(int);
//     int key;
//     cin >> key;

//     for (int i = 0; i < n; i++)
//     {
//         if (key == arr[i])
//         {
//             cout << i << endl;
//             return 0;
//         }
//     }

//     cout << "key is not present";
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr[] = {20, 12, 32, 15, 9};
//     int n = sizeof(arr) / sizeof(int);
//     int lar = arr[0];

//     for (int i = 0; i <= n - 1; i++)
//     {
//         if (lar < arr[i])
//         {
//             lar = arr[i];
//         }
//     }
//     cout << lar << endl;
// }

// BUBBLE SORT
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
//     for (int j = 0; j < n; j++)
//     {
//         cout << arr[j] << " ";
//     }
//     cout << endl;
// }

// inverse of an array
// #include <iostream>
// using namespace std;
// int main()
// {

//     int arr1[] = {0, 2, 4, 1, 3};
//     int n = sizeof(arr1) / sizeof(int);
//     int arr2[n];

//     for (int i = 0; i < n; i++)
//     {
//         int x = arr1[i];
//         arr2[x] = i;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr2[i] << " ";
//     }
// }
