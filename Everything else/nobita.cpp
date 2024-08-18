#include <iostream>
using namespace std;

int candytaken(int x, int n)
{
    int m = 0;
    while (1)
    {
        if (x % n == 0)
        {
            return m;
        }
        else
        {
            m++;
            x++;
        }
    }
}

int candyreturn(int x, int n)
{
    int m = 0;
    while (1)
    {
        if (x % n == 0)
        {
            return m;
        }
        else
        {
            m++;
            x--;
        }
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int n;
        cin >> n;

        int a = candytaken(x, n);
        int b = candyreturn(x, n);
        if (a > b)
        {
            cout << "candyreturn " << b << endl;
        }
        else
        {
            cout << "candytaken" << a << endl;
        }
    }
}