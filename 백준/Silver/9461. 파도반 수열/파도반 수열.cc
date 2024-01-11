#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long int arr[103] = { 0, };


int main(void)
{
	int T;
	scanf("%d", &T);
	arr[1] = 1, arr[2] = 1, arr[3] = 1;
	arr[4] = 2, arr[5] = 2,arr[6]=3;
	arr[7] = 4, arr[8] = 5;
	for (int i = 9; i < 103; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", arr[N]);
	}
	return 0;
}