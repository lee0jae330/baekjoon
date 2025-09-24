#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
unsigned long long powpow(unsigned long long a, unsigned long long b, unsigned long long c)
{
	if (b == 0)
		return 1;
	unsigned long long n = powpow(a, b / 2, c);
	unsigned long long tmp = n * n %c;
	if (b % 2 == 0)
		return tmp;
	else
		return a * tmp % c;
}
int main(void)
{
	unsigned long long x, y, z;
	scanf("%llu %llu %llu", &x, &y, &z);
	printf("%llu\n", powpow(x, y,z));
	return 0;
}