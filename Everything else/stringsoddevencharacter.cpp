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

void highorlowasciicode(char arr[1000])
{

    for (int i = 0; i <= lengthofstring(arr) - 1; i++)
    {

        if (i % 2 == 0)
        {
            int ch = arr[i];
            int ch1 = ch + 1;
            char replace = ch1;

            cout << replace;
        }

        if (i % 2 != 0)
        {
            int ch = arr[i];
            int ch1 = ch - 1;
            char replace = ch1;

            cout << replace;
        }
    }
}
int main()
{

    char arr[1000];
    cin.getline(arr, 1000);

    lengthofstring(arr);

    highorlowasciicode(arr);
}