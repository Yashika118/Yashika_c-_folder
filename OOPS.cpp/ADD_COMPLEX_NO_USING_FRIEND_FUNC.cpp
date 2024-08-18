#include <iostream>
using namespace std;
class complex
{
    float real;
    float imag;

public:
    complex()
    {
        real = 0;
        imag = 0;
    }
    complex(float a, float b)
    {
        real = a;
        imag = b;
    }
    void disp()
    {
        cout << real << " +" << imag << "j" << endl;
    }
    friend complex add(complex one, complex two);
};
complex add(complex one, complex two)
{
    complex temp;
    temp.real = one.real + two.real;
    temp.imag = one.imag + two.imag;
    return temp;
}

int main()
{
    complex a(30, 50), b(50, 29);
    complex c = add(a, b);
    c.disp();
}