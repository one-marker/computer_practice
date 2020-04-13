#include <iostream>

void f(int n, unsigned int* a, unsigned int* b, unsigned int* c)
{
    unsigned int q = 0, p = 0, s = 1;

    for (size_t i = 0; i < n; i++)
    {
        p += a[i] * s;
        q += b[i] * s;
        s *= 10;

        c[i] = p * q;
    }
   
    printf("%x\n", c);
}


int main()
{
    unsigned int a[1] = { 13 };
    unsigned int b[1] = { 13 };
    unsigned int c[1] = { 2 };
    printf("%d\n", a[0]);
    printf("%d\n", b[0]);


    f(1, a, b, c);

    return 0;
}
