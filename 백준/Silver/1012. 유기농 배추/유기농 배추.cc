#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<string.h>

using namespace std;

int arr[51][51];
int visited[51][51];
int cnt;
int N, M, K;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x_tmp = x + xx[i];
		int y_tmp = y + yy[i];
		if (x_tmp >= 0 && y_tmp >= 0 && x_tmp < N && y_tmp < M)
		{
			if (!visited[x_tmp][y_tmp] && arr[x_tmp][y_tmp])
			{
				visited[x_tmp][y_tmp] = 1;
				dfs(x_tmp, y_tmp);
			}
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		scanf("%d %d %d", &N, &M, &K);
		for (int j = 0; j < K; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (!visited[j][k] && arr[j][k])
				{
					cnt++;
					dfs(j, k);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}