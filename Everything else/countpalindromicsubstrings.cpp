// #include <iostream>
// using namespace std;

// int lengthofstring(char arr[1000])
// {

//     int i = 0;
//     int count = 0;
//     while (arr[i] != '\0')
//     {
//         count++;
//         i++;
//     }

//     return count;
// }

// int main()
// {

//     char arr[1000];
//     cin.getline(arr, 1000);

//     lengthofstring(arr);

//     for (int i = 0; i <= lengthofstring(arr) - 1; i++)
//     {

//         for (int j = 0; j <= i; j++)

//         {
//             cout << arr[j];

//         }

//         cout << endl;
//     }
// }

#include <iostream>
using namespace std;

int lengthofstring(char arr[1000])
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
// void printarr(char arr[1000], int i, int j)
// {
//     for (int k = i; k <= j; k++)
//     {
//         cout << arr[k];
//     }
// }

bool ispalindrome(char arr[1000], int i, int j)
{

    while (i < j)
    {

        if (arr[i] != arr[j])
        {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}

int main()
{

    int count = 0;
    char arr[1000];
    cin.getline(arr, 1000);

    int length = lengthofstring(arr);

    for (int i = 0; i <= length - 1; i++)
    {

        for (int j = i; j <= length - 1; j++)

        {
            // cout << endl;

            // printarr(arr, i, j);
            // cout << endl;
            if (ispalindrome(arr, i, j) == 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;
}