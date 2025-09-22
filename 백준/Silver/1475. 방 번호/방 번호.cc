#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int arr[10] = { 0, };
	int N,a;
	scanf("%d", &N);
	while (1)
	{
		if (N >= 10)
		{
			a = N % 10;
			arr[a]++;
		}
		else
		{
			a = N;
			arr[a]++;
			break;
		}
		N /= 10;
	}
	int new_arr[9];
	for (int i = 0; i < 9; i++)
	{
		if (i == 6)
		{
			int tmp = arr[6] + arr[9];
			if (tmp % 2 == 1)
				tmp += 1;
			new_arr[i] = (tmp / 2);
		}
		else
			new_arr[i] = arr[i];
	}
	int max = new_arr[0];
	for (int i = 1; i < 9; i++)
	{
		if (max < new_arr[i])
			max = new_arr[i];
	}
	printf("%d\n", max);
	return 0;
}