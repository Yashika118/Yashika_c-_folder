#include <iostream>
using namespace std;
void mergetwosortedarray(int arr1[], int arr2[], int n1, int n2)
{
    int temp[1000];
    int i = 0, j = 0, k = 0;

    while (i <= n1 - 1 & j <= n2 - 1)
    {

        if (arr1[i] < arr2[j])
        {
            temp[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (j <= n2 - 1)
    {
        temp[k] = arr2[j];
        k++;
        j++;
    }

    while (i <= n1 - 1)
    {
        temp[k] = arr1[i];
        k++;
        i++;
    }

    for (int l = 0; l < k; l++)
    {
        cout << temp[l] << " ";
    }
}
int main()
{
    int arr1[] = {0, 1, 3};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);

    mergetwosortedarray(arr1, arr2, n1, n2);
}