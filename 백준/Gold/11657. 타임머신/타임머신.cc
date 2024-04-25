#include<bits/stdc++.h>

using namespace std;

vector<tuple<int,int,int>>v;
bool isCycle= false;
const int INF = 1e9+1;
long long dist[501];
int N,M;

void bellmanFord(int start) {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[start] =0;
	for (int i = 0; i < N - 1; i++) {
		for (auto adj : v) {
			auto[from, to, cost] = adj;
			if (dist[from] == INF) {
				//방문 x 노드면 간선을 이어갈 수 없음
				continue;
			}
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}
	for (auto adj : v) {
		auto [from, to, cost] = adj;
		if (dist[from] == INF) {
			//방문 x 노드면 간선을 이어갈 수 없음
			continue;
		}
		if (dist[to] > dist[from] + cost) {
			isCycle = true;
			dist[to] = dist[from] + cost;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({a,b,cost});
	}
	
	bellmanFord(1);

	if (isCycle) {
		cout << -1 <<'\n';
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) {
				cout << -1 <<'\n';
			}
			else {
				cout << dist[i] <<'\n';
			}
		}
	}
	return 0;
}