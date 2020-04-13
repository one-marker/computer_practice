#include <iostream>

void sdvig(unsigned int* a, unsigned int k, int n)
{
    unsigned int t = 0;
    for (size_t i = 0; i < n; i++)
    {

        int d = a[i];
        a[i] = a[i] << k + t;
        t = d >> (32-k);
    }
 
    printf("%x\n", a);

}


int main()
{
    unsigned int k = 2, a[2] = { 0x04030201, 0x08070605 };
    
    printf("%x\n", a[0]);
    printf("%x\n", a[1]);
    sdvig(a, k, 2);

    return 0;
}

