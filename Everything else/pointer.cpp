#include <iostream>
using namespace std;
// int main()
// {

//     int x = 20;
//     float y = 55.3;

//     cout << "address of x  " << &x << endl;
//     cout << sizeof(&x) << endl;
//     cout << "address of y  " << &y << endl;
//     cout << sizeof(&y) << endl;
// }

// STORING OF VARIABLE IN POINTER;

// int main()
// {

//     int x = 20;
//     char ch = 'Y';

//     int *xptr = &x;
//     cout << xptr << endl;
//     cout << "value of char is  " << ch << endl;
//     cout << sizeof(&ch) << endl;
//     cout << "address of ch  " << (int *)&ch << endl;
// }

int main()
{
    int x = 15;
    float f = 67.8;
    double d = 456.321;

    int *xptr = &x;
    float *fptr = &f;
    double *dptr = &d;

    cout << "address of x is  " << xptr << endl;
    cout << "address of x is  " << xptr + 1 << endl;
    cout << "address of x is  " << xptr + 2 << endl;
    cout << "address of x is  " << xptr + 3 << endl;
    cout << "address of f is  " << fptr << endl;
    cout << "address of d is  " << dptr << endl;
    cout << "derefer x " << *xptr << endl;
    cout << "derefer f " << *fptr << endl;
    cout << "derefer d " << *dptr << endl;
}
