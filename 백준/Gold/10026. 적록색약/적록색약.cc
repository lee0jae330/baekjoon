#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<string.h>

using namespace std;

char arr[101][101];
int visited[101][101];

int cnt = 0;
int sol = 0;
int N;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
void dfs(int x, int y)
{
	visited[x][y] = 1;
	char color = arr[x][y];
	for (int i = 0; i < 4; i++)
	{
		int x_tmp = x + xx[i];
		int y_tmp = y + yy[i];
		if (x_tmp >= 0 && x_tmp < N && y_tmp >= 0 && y_tmp < N)
		{
			if (!visited[x_tmp][y_tmp] && color == arr[x_tmp][y_tmp])
			{
				visited[x_tmp][y_tmp] = 1;
				dfs(x_tmp, y_tmp);
			}
		}
	}
}

void dfs2(int x, int y)
{
	visited[x][y] = 1;
	char color = arr[x][y];
	for (int i = 0; i < 4; i++)
	{
		int x_tmp = x + xx[i];
		int y_tmp = y + yy[i];
		if (x_tmp >= 0 && x_tmp < N && y_tmp >= 0 && y_tmp < N)
		{
			if (!visited[x_tmp][y_tmp])
			{
				if (color == 'R'||color=='G')
				{
					if (arr[x_tmp][y_tmp] == 'R' || arr[x_tmp][y_tmp] == 'G')
					{
						visited[x_tmp][y_tmp] = 1;
						dfs2(x_tmp, y_tmp);
					}
				}
				else if(color=='B')
				{
					if (color == arr[x_tmp][y_tmp])
					{
						visited[x_tmp][y_tmp] = 1;
						dfs2(x_tmp, y_tmp);
					}
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%c", &arr[i][j]);
		getchar();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				cnt++;
				dfs(i, j);
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				sol++;
				dfs2(i, j);
			}
		}
	}
	printf("%d %d\n", cnt,sol);
	return 0;
}