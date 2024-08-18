#include <iostream>
using namespace std;

int lengthofstring(char arr[100])
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

int compressedstring(char arr[100], int arr2[100])
{

    for (int i = 0; i < lengthofstring(arr) - 1; i++)
    {
    }
}
int main()
{

    int arr2[100] = {0};
    char arr[100];
    cin.getline(arr, 100);

    lengthofstring(arr);

    compressedstring(arr, arr2);
}