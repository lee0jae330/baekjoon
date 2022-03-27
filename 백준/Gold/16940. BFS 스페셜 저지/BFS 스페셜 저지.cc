#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int>v[100001];
int arr[100001];
int visited[100001];

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());
	if (arr[0] != 1)
	{
		printf("0\n");
		return 0;
	}
	int num = 1;
	int idx = 1;
	int chk = 0;

	while (1)
	{ 
		int pre = arr[chk];
		visited[pre] = 1;
		int cnt = v[pre].size();
		for (int i = 0; i < v[pre].size(); i++)
		{
			if (visited[v[pre][i]])
				cnt--;
		}
		for (int i = 0; i < cnt; i++)
		{
			if (!binary_search(v[pre].begin(), v[pre].end(), arr[idx + i]))
			{
				printf("0\n");
				return 0;
			}
			else
			{
				visited[idx + i];
				num++;
			}
			if (num == N)
			{
				printf("1\n");
				return 0;
			}
		}
		idx += cnt;
		chk++;
	}
	return 0;
}