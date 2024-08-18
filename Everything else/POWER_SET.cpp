#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 0;
    int arr[3] = {1, 2, 3};

    for (int Set = 0; Set < pow(2, 3); Set++)
    {
        int XOR = 0;
        for (int bit = 0; bit < 32; bit++)
        {
            if ((Set & (1 << bit)) > 0)
            {
                cout << arr[bit] << " ";
                XOR = arr[bit] ^ XOR;
            }
        }
        // cout << endl;
        cout << "XOR = " << XOR << endl;
        ans = max(ans, XOR); //-->to find max xor in power set
    }
    cout << ans << endl;
}