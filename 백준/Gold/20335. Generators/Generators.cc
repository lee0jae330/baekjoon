#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

typedef long long ll;

int N, M;


const int SIZE = 1e5 + 1;
int parent[SIZE];
int ranking[SIZE];
int root[SIZE];
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
	if (x == y || visited[x] && visited[y]) {
		return false;
	}

	if (ranking[x] < ranking[y]) {
		swap(x, y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
	if (visited[x] || visited[y]) {
		visited[x] = 1;
		visited[y] = 1;
	}
	return true;
}

struct compare {
	bool operator()(const tuple<int,int,int>&a, const tuple<int, int, int>& b) { 
		auto &[a1,a2,a3] = a;
		auto &[b1,b2,b3] = b;
		
		int rootA = root[a1] + root[a2];
		int rootB = root[b1] + root[b2];

		if (a3 == b3) {
			if (rootA == rootB) {
				if (a1 == b1) {
					return a2 > b2;
				}
				return a1 > b1;
			}
			return rootA > rootB;
		}

		return a3 > b3;

	}
};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, cost;
		cin >> x >> cost;
		root[x] = 1;
		pq.push({ x, x, cost });
	}

	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		if (i == N) {
			pq.push({ 1, i, cost });
		}
		else {
			pq.push({i, i + 1, cost });
		}
	}

	ll sum = 0;

	while (!pq.empty()) {
		auto [x, y, cost] = pq.top();
		pq.pop();

		//cout << x << ' ' << y << ' ' << cost << '\n';
		if (x == y) {
			if (x == find(x) && !visited[x]) {
				visited[x] = 1;
				sum += cost;

			}
			else {
				int root = find(x);
				if (!visited[root]) {
					visited[root] = 1;
					sum +=cost;

				}
			}
		}
		else {
			if (merge(x, y)) {
				sum += cost;

			}
		}
	}
	cout << sum << '\n';
	return 0;
}