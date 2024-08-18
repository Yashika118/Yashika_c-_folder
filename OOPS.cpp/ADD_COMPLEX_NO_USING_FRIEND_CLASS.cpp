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
    friend class F;
};
class F
{
public:
    complex add(complex &a, complex &b)
    {
        complex temp;
        temp.imag = a.imag + b.imag;
        temp.real = a.real, b.real;
        return temp;
    }
};

int main()
{
    complex a(30, 50), b(50, 29);
    complex c;
    F fri;

    c = fri.add(a, b);

    c.disp();
}