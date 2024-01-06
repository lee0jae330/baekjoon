#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[12];

int main(void)
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;
	for (int i = 3; i < 12; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		printf("%d\n", arr[N - 1]);
	}

	return 0;
}