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
        // if (num == 1)
        // {
        //     cout << arr[i];
        // }
        if (num > 1)
        {
            cout << arr[i] << num;
        }
        else
        {
            cout << arr[i];
        }
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
