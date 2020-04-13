#include <iostream>

using namespace std;
void sum(int n, unsigned int* a, unsigned int* b, unsigned int* c)
{
	long long d = 0;
	long long s;
	for (int i = 0; i < n; i++)
	{
		s = (long long)a[i] + (long long)b[i] + d;
		c[i] = s;
		d = s >> 32;
	}
}


int main()
{

  	unsigned int a[2] = { 0x04030201,0x04030201 };
	unsigned int b[2] = { 0x04030201,0x04030201 };
	unsigned int c[2] = { 0x04030201,0x04030201 };
	printf("%d\n", a);
	printf("%ds\n", b);

	sum(2, a, b, c);
	printf("%d\n", c);



	return 0;
}
