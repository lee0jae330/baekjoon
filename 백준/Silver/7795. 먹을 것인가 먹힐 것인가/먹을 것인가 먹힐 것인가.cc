#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SIZE 20001

int A[SIZE];
int B[SIZE];

int compare(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	return 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int a, b,sum=0;
		scanf("%d %d", &a, &b);
		for (int j = 0; j < a; j++)
			scanf("%d", &A[j]);
		for (int j = 0; j < b; j++)
			scanf("%d", &B[j]);
		qsort(B, b, sizeof(int), compare);
		qsort(A, a, sizeof(int), compare);
		for (int j = 0; j < a; j++)
		{
			for (int k = 0; k < b; k++)
			{
				if (A[j] > B[k])
					sum++;
				else
					break;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}