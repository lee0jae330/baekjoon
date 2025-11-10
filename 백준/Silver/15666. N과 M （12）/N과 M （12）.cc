#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;
int arr[10];
int visited[10] = { 0, };
int N, M;

void dfs(int count, int num)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	int tmp = -1;
	for (int i = num; i < v.size(); i++)
	{
		if (tmp != v[i])
		{
			visited[i] = 1;
			tmp = v[i];
			arr[count] = v[i];
			dfs(count + 1, i);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	dfs(0,0);
	return 0;
}