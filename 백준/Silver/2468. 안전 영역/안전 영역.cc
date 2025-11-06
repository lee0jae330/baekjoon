#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string.h>

using namespace std;
int N;
int arr[101][101];
int visited[101][101];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

vector<int>v;

void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < N)
			{
				if (!visited[tx][ty] && arr[tx][ty] > 0)
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
}

int main(void)
{
	int max = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	v.push_back(1);
	int cnt = 0;
	for (int i = 0; i < max; i++)
	{
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				arr[j][k] -= 1;
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (!visited[j][k] && arr[j][k] > 0)
				{
					bfs(j, k);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[v.size() - 1]);
	return 0;
}