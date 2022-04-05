#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int visited[501];
vector<int>v[501];

void bfs(int x) {
	visited[x]=1;
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		x=q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if(visited[v[x][i]])
				continue;
			visited[v[x][i]]=visited[x]+1;
			q.push(v[x][i]);
		}
	}
}

vector<pair<int,int>>sol;

bool comp(pair<int, int>p1, pair<int, int>p2) {
	if(p1.first==p2.first)
		return p1.second<p2.second;
	return p1.first<p2.first;
}

int main(void) {
	fastio();
	int N,M;
	cin >> N >>M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >>a >>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited,0,sizeof(visited));
		bfs(i);
		int sum=0;
		for (int j = 1; j <= N; j++) {
			sum+=visited[j]-1;
		}
		sol.push_back({sum,i});
	}
	sort(sol.begin(),sol.end(),comp);
	cout << sol[0].second<<'\n';
	return 0;
}