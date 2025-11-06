#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

char arr[30][30];
int visited[30][30];
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
queue<pair<int, int>>q;
vector<int>v;
int N;

void dfs(int x, int y)
{
	int cnt = 0;
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx, ty;
			tx = x + xx[i];
			ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < N && ty < N)
			{
				if (arr[tx][ty]=='1'&&!visited[tx][ty] )
				{
					cnt++;
					visited[tx][ty] = 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	cnt++;
	v.push_back(cnt);
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
			if (!visited[i][j] && arr[i][j] == '1')
			{
				dfs(i, j);
			}
		}
	}
	printf("%d\n", v.size());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d\n", v[i]);
	}
	return 0;
}