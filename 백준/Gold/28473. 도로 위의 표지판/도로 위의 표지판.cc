#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N, M;
const int SIZE = 2 * 1e5 + 1;
int parent[SIZE];
int ranking[SIZE];

int number[10];

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

struct compare {
	bool operator()(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
		auto& [a1, a2, a3, a4] = a;
		auto& [b1, b2, b3, b4] = b;

		if (a3 == b3) {
			if (a4 == b4) {
				if (a1 == b1) {
					return a2 > b2;
				}
				return a1 > b1;
			}
			return a4 > b4;
		}

		return a3 > b3;
	}
};

priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, compare>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		pq.push({ x,y,z,w });
	}

	ll sum = 0;


	while (!pq.empty()) {
		auto [x, y, z, w] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			sum += w;
			number[z]++;
		}
	}

	int root = find(1);
	for (int i = 2; i <= N; i++) {
		if (root != find(i)) {
			cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < number[i]; j++) {
			cout <<i;
		}
	}
	cout << ' ' << sum << '\n';
	return 0;
}