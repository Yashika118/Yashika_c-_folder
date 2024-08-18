#include <stdio.h>
int main()
{
    int prin, time;
    float rate;
    float si;
    prin = 10000;
    rate = 10.5;
    time = 3;
    si = prin * rate * time / 100;

    printf("SIMPLE INTEREST=%f", si);

    return 0;
}
