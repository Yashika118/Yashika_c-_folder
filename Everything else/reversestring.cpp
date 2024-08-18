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

void reversestring(char arr[1000])
{

    for (int i = lengthofstring(arr) - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
}

int main()
{

    char arr[1000];
    cin.getline(arr, 1000);

    lengthofstring(arr);

    reversestring(arr);
}