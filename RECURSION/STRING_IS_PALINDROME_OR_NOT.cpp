#include <bits/stdc++.h>
using namespace std;
bool palindromeornot(string s, int len, int i)
{
    // base case
    if (i >= s.length() / 2)
    {
        return true;
    }
    // recursive case
    if (s[i] != s[len - i - 1])
    {
        return false;
    }
    return palindromeornot(s, len, i + 1);
}
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    if (palindromeornot(s, len, 0))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}