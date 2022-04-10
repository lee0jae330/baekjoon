#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	unsigned long long N;
	scanf("%llu", &N);
	if (N % 5 == 0 || N % 5 == 2)
		printf("CY\n");
	else
		printf("SK\n");
	return 0;
}