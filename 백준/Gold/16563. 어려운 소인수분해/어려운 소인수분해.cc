#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 5000001
int prime[SIZE] = { 0, };
int arr[1000001] = { 0, };
int main(void)
{
	prime[0] = -1, prime[1] = -1;
	for (int i = 2; i < SIZE; i++)
		prime[i] = i;
	for (int i = 2; i*i < SIZE ; i++)
	{
		if (prime[i] == i)
		{
			for (int j = i * i; j < SIZE; j+=i)
			{
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		while (arr[i]>1)
		{
			printf("%d ", prime[arr[i]]);
			arr[i] /= prime[arr[i]];
		}
		printf("\n");
	}
	return 0;
}