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

// int compressastring(char arr[1000])
// {
//     // int value;
//     int num = 0;
//     int i = 0;
//     while (i <= lengthofstring(arr) - 1)
//     {
//         char temp = arr[i];
//         int j;

//         for (j = i; j <= lengthofstring(arr) - 1; j++)
//         {
//             if (arr[j] == temp)
//             {
//                 num++;
//             }
//         }
//         cout << arr[i] << num;
//         i = j;
//         // i = j - 1;
//     }

//     return num;
// }

// int main()
// {

//     char arr[1000];
//     cin.getline(arr, 1000);

//     lengthofstring(arr);

//     compressastring(arr);
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

int compressastring(char arr[1000])
{
    // int value;
    int num = 0;
    int i = 0;
    while (i <= lengthofstring(arr) - 1)
    {
        char temp = arr[i];
        int j;

        num = 0; // added num=0
        for (j = i; j <= lengthofstring(arr) - 1; j++)
        {
            if (arr[j] == temp)
            {
                num++;
            }
            if (arr[j] != temp)
            { // added break statement
                break;
            }
        }
        cout << arr[i] << num;
        i = j;
        // i = j - 1;
    }

    return num;
}

int main()
{

    char arr[1000];
    cin.getline(arr, 1000);

    lengthofstring(arr);

    compressastring(arr);
}

//                              ANOTHER WAY TO SOLVE THIS

// #include <iostream>
// #include<cstring>
// using namespace std;
// int main()
// {
//     string s1;
//     getline(cin,s1);
//     int count=1;
//     int n=s1.length();
//     for(int i=0;i<n;i++){
//     if(s1[i]==s1[i+1]){
//           count++;
//         }
//     else{
//         cout<<s1[i]<<count;
//         count=1;
//     }
//     }

//     return 0;
// }
