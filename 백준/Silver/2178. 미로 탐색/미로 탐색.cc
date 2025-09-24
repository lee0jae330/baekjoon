#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

char arr[101][101];
int visited[101][101];
int dist[101][101];
queue<pair<int, int>>q;
int x = 0, y = 0;
int N, M;

void bfs()
{
	q.push({ 0,0 });
	visited[0][0] = 1;
	dist[0][0] = 1;
	while (!q.empty())
	{
		int x_tmp = q.front().first;
		int y_tmp = q.front().second;
		q.pop();
		if (x_tmp + 1 < N && !visited[x_tmp + 1][y_tmp] && arr[x_tmp+1][y_tmp] == '1')
		{
			q.push({ x_tmp + 1,y_tmp });
			visited[x_tmp + 1][y_tmp] = 1;
			dist[x_tmp + 1][y_tmp] = dist[x_tmp][y_tmp] + 1;
		}
		if (x_tmp - 1 >= 0 && !visited[x_tmp - 1][y_tmp] && arr[x_tmp - 1][y_tmp] == '1')
		{
			q.push({ x_tmp - 1,y_tmp });
			visited[x_tmp - 1][y_tmp] = 1;
			dist[x_tmp - 1][y_tmp] = dist[x_tmp][y_tmp] + 1;
		}
		if (y_tmp + 1 < M && !visited[x_tmp][y_tmp + 1] && arr[x_tmp][y_tmp + 1] == '1')
		{
			q.push({ x_tmp,y_tmp+1 });
			visited[x_tmp][y_tmp+1] = 1;
			dist[x_tmp][y_tmp+1] = dist[x_tmp][y_tmp] + 1;
		}
		if (y_tmp - 1 >= 0 && !visited[x_tmp][y_tmp - 1] && arr[x_tmp][y_tmp - 1] == '1')
		{
			q.push({ x_tmp,y_tmp - 1 });
			visited[x_tmp][y_tmp - 1] = 1;
			dist[x_tmp][y_tmp - 1] = dist[x_tmp][y_tmp]+ 1;
		}
	}

}

int main(void)
{
	scanf("%d %d", &N, &M);
	getchar();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%c", &arr[i][j]);
		getchar();
	}
	bfs();
	printf("%d\n", dist[N-1][M-1]);
	return 0;
}