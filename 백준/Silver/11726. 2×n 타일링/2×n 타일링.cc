#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long int arr[1001][2];

int main(void)
{
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i < 1001; i++)
	{
		arr[i][0] = (arr[i - 1][0] + arr[i - 1][1])%10007;
		arr[i][1] = (arr[i - 2][0] + arr[i - 2][1])%10007;
	}
	int N;
	scanf("%d", &N);
	int result = (arr[N - 1][0] % 10007) + (arr[N - 1][1] % 10007);
	printf("%d\n", result%10007);
	return 0;
}