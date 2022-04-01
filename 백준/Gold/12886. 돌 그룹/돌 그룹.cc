#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int gcd(int a, int b)
{
	int tmp;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0)
	{
		int n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int xx = a + b + c;
	int tmp = gcd(a, b);
	tmp = gcd(tmp, c);
	xx /= tmp;
	if (xx == 3 || xx == 6 || xx == 12 || xx == 24 || xx == 48 || xx == 96 || xx == 192 || xx == 384 || xx == 768)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}