#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no;
    cin >> no;

    // int tot_set_bit = 0;
    // for (int bit = 0; bit < 32; bit++)
    // { // 32 bits =INT_MAX

    //     int curr_no = no & (1 << bit);

    //     if (curr_no > 0)
    //     {
    //         tot_set_bit = tot_set_bit + 1;
    //     }
    // }

    // if (tot_set_bit == 1)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }

    // -->ONE LINE CODE
    if ((no & (no - 1)) == 0)
    {
        cout << "YES : no. is of power of 2" << endl;
    }
    else
    {
        cout << "NO : no. is not of power of 2" << endl;
    }
}