#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct serial
{
	char name[52];
	int num = 0;
}SR;
SR arr[1000];
int compare(const void* a, const void* b)
{
	SR* x, * y;
	x = (SR*)a;
	y = (SR*)b;
	if (strlen(x->name) == strlen(y->name))
	{
		if (x->num == y->num)
		{
			return strcmp(x->name, y->name);
		}
		else if (x->num < y->num)
			return -1;
		else
			return 1;
	}
	else if (strlen(x->name) < strlen(y->name))
		return -1;
	else
		return 1;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i].name);
		for (int j = 0; j < strlen(arr[i].name); j++)
		{
			if (arr[i].name[j] >= 48 && arr[i].name[j] <= 57)
				arr[i].num += arr[i].name[j] - '0';
		}
	}
	qsort(arr, N, sizeof(arr[0]), compare);
	for (int i = 0; i < N; i++)
		printf("%s\n", arr[i].name);
	return 0;
}