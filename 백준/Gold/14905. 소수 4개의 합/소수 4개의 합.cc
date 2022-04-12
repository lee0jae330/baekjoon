#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 10000001
int arr[SIZE] = { 0, };
int main(void)
{
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i < SIZE / i; i++)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i * i; j < SIZE; j += i)
		{
			if (j % i == 0)
				arr[j] = 1;
		}
	}
	int N,a,b,c,d;
	while (scanf("%d", &N) != EOF)
	{
		if (N < 8)
			printf("Impossible.\n");
		else if (N == 8)
			printf("2 2 2 2\n");
		else
		{
			if (N % 2 == 0) 
			{
				a = 2, b = 2;
				N -= 4;
				for (int i = 2; i < SIZE; i++)
				{
					if (arr[i] == 0)
					{
						c = i;
						d = N - c;
						if (arr[d] == 0)
						{
							printf("%d %d %d %d\n", a, b, c, d);
							break;
						}
					}
				}
			}
			else
			{
				if (N == 9)
				{
					printf("2 2 2 3\n");
				}
				else
				{
					a = 2, b = 3;
					N -= 5;
					for (int i = 1; i < SIZE; i++)
					{
						if (arr[i] == 0)
						{
							c = i;
							d = N - c;
							if (arr[d] == 0)
							{
								printf("%d %d %d %d\n", a, b, c, d);
								break;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}