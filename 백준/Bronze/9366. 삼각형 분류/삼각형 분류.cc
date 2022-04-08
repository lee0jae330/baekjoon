#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int T;
	int a, b, c;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		int temp = (a > b) ? a : b;
		int A = (a < b) ? a : b;
		int C = (temp > c) ? temp : c;
		int B = (temp < c) ? temp : c;
		if (C >= A + B)
			printf("Case #%d: invalid!\n",i+1);
		else
		{
			if (A == B && A == C)
				printf("Case #%d: equilateral\n",i+1);
			else if (A != B && A != C && B != C)
				printf("Case #%d: scalene\n",i+1);
			else
				printf("Case #%d: isosceles\n",i+1);
		}
	}
	return 0;
}