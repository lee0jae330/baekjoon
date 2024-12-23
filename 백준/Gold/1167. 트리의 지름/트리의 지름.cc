#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<memory.h>

using namespace std;

vector<pair<int, int>>v[100002];
int visited[100002];
int maxdist, maxnode;

void dfs(int x,int d)
{
	if (visited[x])
		return;
	if (maxdist < d)
	{
		maxnode = x;
		maxdist = d;
	}
	visited[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i].first;
		int nextdist = v[x][i].second;
		dfs(next, nextdist + d);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		while (1)
		{
			int b, c;
			scanf("%d", &b);
			if (b == -1)
				break;
			scanf("%d", &c);
			v[a].push_back({ b,c });
		}
		
	}
	dfs(1, 0);
	maxdist = 0;
	memset(visited, 0, sizeof(visited));
	dfs(maxnode, 0);
	printf("%d\n", maxdist);
	return 0;
}