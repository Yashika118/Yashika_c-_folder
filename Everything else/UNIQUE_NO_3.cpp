#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 3, 3, 2, 4, 4, 4, 3, 2, 500};

    int ans = 0;

    for (int bit = 0; bit < 32; bit++)
    {
        int count_of_ones = 0;

        for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        {
            int no = arr[i];
            if ((no & (1 << bit)) > 0)
            {
                count_of_ones++;
                        }
        }
        if (count_of_ones % 3 != 0)
        {
            ans = ans | (1 << bit);
        }
    }
    cout << ans << endl;
}