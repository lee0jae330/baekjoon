#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct judges
{
	int age;
	char name[102];
	int number;
}Online;
int compare(const void* a, const void* b)
{
	Online* x, * y;
	x = (Online*)a;
	y = (Online*)b;
	if (x->age == y->age)
	{
		if (x->number > y->number)
			return 1;
		else
			return -1;
	}
	else if (x->age > y->age)
		return 1;
	else
		return -1;
}
int main(void)
{
	int N;
	Online arr[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{	scanf("%d %s", &arr[i].age, arr[i].name);
	arr[i].number = i+1;
	}
	qsort(arr, N, sizeof(arr[0]), compare);
	for (int i = 0; i < N; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
	return 0;
}