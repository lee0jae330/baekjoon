#include<bits/stdc++.h>

using namespace std;

int N, M, start, dest;

const int INF = 1e9;

vector<pair<int,int>>v[1001];
int dist[1001];

void dijkstra(int s) {
	priority_queue<pair<int,int>>pq;
	pq.push({0,s});
	while (!pq.empty()) {
		int d = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if(dist[cur] < d)
			continue;

		for (auto adj : v[cur]) {
			int next = adj.first;
			int cost = d + adj.second;
			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({-cost, next});
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({b,cost});
	}
	cin >> start >> dest;
	dijkstra(start);

	cout << dist[dest]<<'\n';
	return 0;
}