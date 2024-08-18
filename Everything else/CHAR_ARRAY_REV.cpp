#include <iostream>
using namespace std;

int lengthofchararray(char arr[])
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
int main()
{
    char arr[6] = "hello";
    cout << lengthofchararray(arr);
}