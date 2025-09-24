#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

queue<int>q;
int visited[100002] = {0, };
int path[100002] = { 0, };
void bfs(int v, int target)
{
	visited[v] = 1;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		int tmp1, tmp2, tmp3;
		tmp1 = v - 1, tmp2 = v + 1, tmp3 = 2 * v;
		if (tmp1 >= 0&&visited[tmp1] == 0)
		{
			visited[tmp1] = 1;
			path[tmp1] = v;
			if (tmp1 == target)
				return;
			q.push(tmp1);
		}
		if (tmp2 <= 100000&&visited[tmp2] == 0)
		{
			visited[tmp2] = 1;
			path[tmp2] = v;
			if (tmp2 == target)
				return;
			q.push(tmp2);
		}
		if (tmp3 <= 100000&&visited[tmp3] == 0)
		{
			visited[tmp3] = 1;
			path[tmp3] = v;
			if (tmp3 == target)
				return;
			q.push(tmp3);
		}
	}
}

int main(void)
{
	int N, K, count = 0;
	scanf("%d %d", &N, &K);
	bfs(N, K);
	int tmp = K;
	while (tmp != N)
	{
		count++;
		tmp = path[tmp];
	}
	printf("%d\n", count);
	return 0;
}