#include <iostream>
using namespace std;

int lengthofstring(char arr[1000])
{
    int count = 0;
    int i = 0;

    while (arr[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

bool isstringpalindromic(char arr[1000])
{

    lengthofstring(arr);

    // for(int i=0;i<=lengthofstring(arr);i++){
    //     for(int j=lengthofstring(arr);j>=0;j--)

    int i = 0;
    int j = lengthofstring(arr) - 1;

    while (i < j)
    {

        if (arr[i] != arr[j])
        {

            return 0;
            break;
        }

        i++;
        j--;
    }

    return 1;
}

int main()
{

    char arr[1000];
    cin.getline(arr, 1000);

    // isstringpalindromic(arr);

    if (isstringpalindromic(arr) == 1)
    {
        cout << "true" << endl;
    }

    if (isstringpalindromic(arr) == 0)
    {
        cout << "false" << endl;
    }
}