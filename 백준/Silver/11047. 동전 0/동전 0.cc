#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	int arr[10] = { 0, };
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int count = 0;
	int tmp = -1;
	for (int i = N-1; i >=0; i--)
	{
		if (K >= arr[i])
		{
			K -= arr[i];
			count++;
			i = N;
		}
		if (K == 0)
		{
			break;
		}
	}
	printf("%d\n", count);
	return 0;

}