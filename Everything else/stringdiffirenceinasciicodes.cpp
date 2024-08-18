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

void difference(char arr[1000])
{

    int diff;
    int differ;
    for (int i = 0; i < lengthofstring(arr) - 1; i++)
    {
        int val1 = arr[i + 1];
        int val2 = arr[i];

        diff = val1 - val2;
        differ = diff;

        // cout << arr[i] << " " << differ << " " << arr[i + 1];
        cout << arr[i] << differ;
    }

    cout << arr[lengthofstring(arr) - 1];
    // return differ;
}
int main()
{

    char arr[1000];
    cin.getline(arr, 1000);

    lengthofstring(arr);

    difference(arr);
}