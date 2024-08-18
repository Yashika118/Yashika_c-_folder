#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 2, 4, 3, 3, 9};
    int XOR = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        XOR = XOR ^ arr[i];
    }
    // step:2 konsi bit pr different the
    int pos = -1;
    for (int bit = 0; bit < 32; bit++)
    {
        if ((XOR & (1 << bit)) > 0)
        {
            pos = bit;
            break;
        }
    }
    // step 3: segregate krna hai
    int a = 0;
    int b = 0;
    // a mein vo sare element jinki us bit pe 0 hai
    // b mein vo sare element jinki us bit pe 1 hai
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        if ((arr[i] & (1 << pos)) > 0)
        {
            b = b ^ arr[i];
        }
        else
        {
            a = a ^ arr[i];
        }
    }
    cout << a << " " << b << endl;
}