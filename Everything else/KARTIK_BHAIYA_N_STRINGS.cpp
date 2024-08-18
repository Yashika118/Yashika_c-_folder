#include <bits/stdc++.h>
using namespace std;
int func(string s, char ch, int k)
{
    int ans = 0;
    int i = 0;
    int j = 0;
    while (j < s.size())
    {
        s[j] != ch ? k -= 1 : k = k;
        while (k < 0)
        {
            s[j] != ch ? k -= 1 : k = k;
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    cout << max(func(s, 'b', k), func(s, 'a', k)) << endl;
}