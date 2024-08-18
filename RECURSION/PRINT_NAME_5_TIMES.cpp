#include <bits/stdc++.h>
using namespace std;
void printnamefivetimes(string name, int n)
{
    // base case
    if (n > 5)
    {
        return;
    }

    // recursive case
    cout << name << endl;
    printnamefivetimes(name, n + 1);
}
int main()
{
    string name = "yashika";
    int n = 1;

    printnamefivetimes(name, n);
}