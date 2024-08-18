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

void toggling(char arr[1000])
{

    for (int i = 0; i < lengthofstring(arr); i++)
    {

        if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = arr[i] + 32;
            cout << arr[i];
        }

        else if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = arr[i] - 32;
            cout << arr[i];
        }

        else
        {
            cout << arr[i];
        }
    }
}
int main()
{

    char arr[1000];
    cin.getline(arr, 1000);

    lengthofstring(arr);
    toggling(arr);
}