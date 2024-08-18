#include <iostream>
#include <limits.h>
using namespace std;

int lengthofstring(char str[100])
{

    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

int largestnuminarr(int arr[26])
{

    int max = INT_MIN;
    int indx = 0;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            indx = i;
        }
    }

    return indx;
}

int main()
{

    char str[1000];
    cin.getline(str, 1000);

    lengthofstring(str);

    // int x;
    // cin >> x;

    int arr[26] = {0};
    int index;

    for (int i = 0; i < lengthofstring(str); i++)
    {
        int ascii = str[i];
        index = ascii - 97;

        // str[index]++;
        arr[index]++;
        // cout << arr[index] << endl;

        // cout << str[index] << endl;
    }

    // for (int k = 0; k < 26; k++)
    // {
    //     cout << arr[k] << " ";
    // }

    // cout << endl;

    largestnuminarr(arr);

    char alpha = largestnuminarr(arr) + 97;
    cout << alpha << endl;
}