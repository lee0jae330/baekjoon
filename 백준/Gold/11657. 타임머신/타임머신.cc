#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

#define INF 1e9+1

long long dist[501];
vector<pair<pair<int, int>, int>>v;
bool isCycle;

void Bellman_Ford(int x, int N) { //return true -> 음수 사이클o , return false -> 음수 사이클x
	dist[x] = 0;
	for (int i = 0; i < N - 1; i++) {

		for (int j = 0; j < v.size(); j++) {
			int from = v[j].first.first;
			int to = v[j].first.second;
			int cost = v[j].second;

			if (dist[from] == INF)
				continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}

	}

	for (int i = 0; i < v.size(); i++) { //음수 사이클 찾기
		int from = v[i].first.first;
		int to = v[i].first.second;
		int cost = v[i].second;

		if (dist[from] == INF)
			continue;
		if (dist[to] > dist[from] + cost) {
			isCycle = true;
			cout <<-1<<'\n';
			return;
		}
	}
	isCycle = false;
}


int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	fill(dist, dist + 501, INF);

	Bellman_Ford(1, N);
	if (!isCycle) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}

	return 0;
}