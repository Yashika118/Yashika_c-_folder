// #include <iostream>
// using namespace std;

// // void printanarray(int arr[26], int n)
// // {

// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> arr[i];
// //     }
// // }

// void mappedstring(int arr[26], int n)
// {
//     int i;
//     int ascii = 65;
//     char ch = ascii;

//     for (int i = 0; i < n; i++)
//     {
//         int val = 1;

//         if (arr[i] == val)
//         {
//             cout << ch;

//             // i++;
//         }
//         //  val++;

//         else
//         {
//             while (val < 26 && val > 1)
//             {

//                 if (arr[i] == val)
//                 {
//                     ascii++;
//                     cout << ch;
//                 }

//                 val++;
//             }

//             val++;
//         }
//     }
// }
// int main()
// {

//     int n;
//     cin >> n;
//     // int arr[26] = {n};

//     // printanarray(arr, n);
//     mappedstring(arr, n);
// }

// #include <iostream>
// using namespace std;

// void mapstring(int n)
// {

//     int value = 1;
//     int ascii = 65;
//     char ch = ascii;

//     while (n % 10 != 0)
//     {

//         int num = n % 10;

//         if (num == value)
//         {

//             cout << ch;
//         }

//         else
//         {

//             value++;
//             while (value < 27 && value > 1)
//             {

//                 if (num == value)
//                 {
//                     ascii++;
//                     cout << ch;
//                 }
//                 else
//                 {

//                     ascii++;
//                 }

//                 value++;
//             }
//         }

//         num = n / 10;
//     }
// }
// int main()
// {

//     int n;
//     cin >> n;

//     mapstring(n);
// }

#include <iostream>
using namespace std;

int lenghtofstring(char arr[1000000])
{
    int i = 0;
    int count = 0;
    while (arr[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

void mapstring(char arr[1000000])
{

    for (int i = 0; i < lenghtofstring(arr); i++)
    {

        int value = 1;
        int ascii = 65;
        char ch = ascii;

        while (value <= 26 && value > 0)
        {

            if (arr[i] == value)
            {

                cout << ch;
            }

            // else if(arr[i]!=value){
            //     value++;
            //     ascii++;

            // }

            value++;
            ascii++;
        }
    }
}
int main()
{

    char arr[1000000];
    cin.getline(arr, 1000000);

    cout << lenghtofstring(arr);
    mapstring(arr);
}