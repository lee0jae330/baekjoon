#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int,pair<int,int>>>v;

int parent[10002];
bool check = true;
int result = 0;

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	check = false;

	if (x != y)
	{
		check = true;
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
	return;
}

int main(void)
{
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i <= V; i++)
		parent[i] = i;
	for (int i = 0; i < E; i++)
	{
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		v.push_back({ cost,{a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < E; i++)
	{
		merge(v[i].second.first, v[i].second.second);
		if (check)
			result += v[i].first;
	}
	printf("%d\n", result);
	return 0;
}