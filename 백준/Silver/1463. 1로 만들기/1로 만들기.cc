#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define min(a,b) (a<b)?a:b
#define INF (1<<31)-2
#define SIZE 1000002

int arr[SIZE];


int main(void)
{
	int N;
	scanf("%d", &N);
	arr[1] = 0;
	for (int i = 0; i < SIZE; i++)
		arr[i] = INF;
	arr[1] = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i * 2 <= N)
			arr[i * 2] = min(arr[i * 2], arr[i] + 1);
		if (i * 3 <= N)
			arr[i * 3] = min(arr[i * 3], arr[i] + 1);
		if (i + 1 <= N)
			arr[i + 1] = min(arr[i + 1], arr[i] + 1);
	}
	printf("%d\n", arr[N]);
	return 0;
}