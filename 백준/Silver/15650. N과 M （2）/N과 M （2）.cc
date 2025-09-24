#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[9];
int visited[9] = { 0, };
int N, M;

void dfs(int num, int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
		{
				printf("%d ", arr[i]);
		}
		printf("\n");
	}
	for (int i = num; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			arr[count] = i;
			dfs(i+1, count + 1);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	dfs(1, 0);
	return 0;
}