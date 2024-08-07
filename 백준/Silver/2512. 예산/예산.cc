#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int arr[10001];

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
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int M;
	scanf("%d", &M);
	qsort(arr, N, sizeof(int), compare);
	int max = arr[N - 1];
	int low = 1;
	int result;
	while (low <= max)
	{
		int mid = (low + max) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (mid < arr[i])
				sum += mid;
			else
				sum += arr[i];
		}
		if (sum <= M)
		{
			result = mid;
			low = mid + 1;
		}
		else
			max = mid - 1;
	}
	printf("%d\n", result);
	return 0;
}