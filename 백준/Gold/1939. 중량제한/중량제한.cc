#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

struct compare {
	bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
		auto& [a1, a2, a3] = a;
		auto& [b1, b2, b3] = b;
		if (a3 == b3) {
			if (a1 == b1) {
				return a2 > b2;
			}
			return a1 > b1;
		}
		return a3 > b3;
	}
};

const int SIZE = 1e5 + 1;
int parent[SIZE];
int ranking[SIZE];
vector<pair<int, int>>v[SIZE];
int visited[SIZE];

void init() {
	for (int i = 0; i < SIZE; i++) {
		parent[i] = i;
		ranking[i] = 0;
	}
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	if (ranking[x] < ranking[y]) {
		swap(x, y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
	return true;
}

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x] = 1e9 + 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int tx = v[x][i].first;
			if (visited[tx]) {
				continue;
			}
			visited[tx] = min(visited[x], v[x][i].second);
			q.push(tx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int N, M;
	cin >> N >> M;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare>pq;

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		pq.push({ x,y,-z });
	}

	int s, e;
	cin >> s >> e;

	while (!pq.empty()) {
		auto [x, y, z] = pq.top();
		bool result = merge(x, y);
		if (result) {
			v[x].push_back({ y,-z });
			v[y].push_back({ x,-z });
		}
		pq.pop();
	}

	bfs(s);

	cout << visited[e] << '\n';
	return 0;
}