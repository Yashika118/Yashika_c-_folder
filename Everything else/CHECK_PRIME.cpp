#include <iostream>
using namespace std;
int main()
{

    int N;
    cin >> N;

    if (N > 2 and N <= 1000000000)
    {
        if (N % N == 0 and N % 1 == 0)
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not Prime" << endl;
        }
    }

    return 0;
}