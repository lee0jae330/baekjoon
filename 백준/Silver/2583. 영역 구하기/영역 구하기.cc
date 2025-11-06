#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int M, N, K;
int arr[102][102];
int visited[102][102];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
vector<int>v;
queue<pair<int, int>>q;

void bfs(int x, int y)
{
	visited[x][y] = 1;
	q.push({ x,y });
	int size = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		size++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < M&&ty < N)
			{
				if (!visited[tx][ty] && !arr[tx][ty])
				{
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	v.push_back(size);
}

int main(void)
{
	scanf("%d %d %d", &M, &N, &K);
	int x1, x2, y1, y2;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && !arr[i][j])
				bfs(i, j);
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}