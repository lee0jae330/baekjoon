#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

const int SIZE = 1e4 + 1;
int parent[SIZE];
int ranking[SIZE];

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

priority_queue<tuple<int, int, int>>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int N, M;
	cin >> N >> M;

	int sum = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (d) {
			merge(a, b);
		}
		else {
			pq.push({ c, a,b });
			sum += c;
		}
	}

	while (!pq.empty()) {
		auto [cost, x, y] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			sum -= cost;
		}
	}

	cout << sum << '\n';
	return 0;
}