#include <iostream>
#include <string.h>
using namespace std;

// string cin.getline(int arr,int 1000){

int lenghtofarr(char array[8])
{

    int i = 0;
    int count = 0;

    while (array[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

int main()
{
    char array[8] = "Yashika";
    cout << array << endl;

    cout << "lenght of Yashika  " << lenghtofarr(array) << endl;

    char arr[1000] = "Delhi Technological University";

    cin.getline(arr, 1000);

    cout << arr << endl;

    // cout << "lenght of input string  " << lenghtofarr(arr) << endl;
}