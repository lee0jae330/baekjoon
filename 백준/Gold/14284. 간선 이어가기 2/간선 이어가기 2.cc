#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 123456789
vector<pair<int, int>>v[5001];
int dist[5001];

void dijk(int x) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,x });
	dist[x] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		x = pq.top().second;
		pq.pop();
		if (dist[x] < d)
			continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first;
			int cost = d + v[x][i].second;
			if (cost < dist[next]) {
				dist[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	int s, t;
	cin >> s >> t;
	memset(dist, INF, sizeof(dist));

	dijk(s);
	cout << dist[t] << '\n';
	return 0;
}