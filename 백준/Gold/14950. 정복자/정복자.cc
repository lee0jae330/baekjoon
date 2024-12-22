#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

int N, M, t;

int arr[10001];

int cnt = 0;
int sol = 0;

vector<pair<int, int>>v[10001];

void mst(int x) {
	arr[x] = 1;
	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < v[x].size(); i++) {
		auto [next, cost] = v[x][i];
		pq.push({ -cost, next });
	}

	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();

		if (arr[cur]) {
			continue;
		}

		arr[cur] = 1;
		sol += -cost + (t * cnt);
		cnt++;
		for (int i = 0; i < v[cur].size(); i++) {
			auto [next, c] = v[cur][i];
			if (!arr[next]) {
				pq.push({ -c,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> t;
	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y,cost });
		v[y].push_back({ x,cost });
	}
	mst(1);
	cout << sol << '\n';
	return 0;
}