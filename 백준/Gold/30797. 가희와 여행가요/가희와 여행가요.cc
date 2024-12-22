#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

typedef long long ll;

struct compare {
	bool operator()(const tuple<int, int, ll, int>& a, const tuple<int, int, ll, int>& b) {
		auto& [a1, a2, a3, a4] = a;
		auto& [b1, b2, b3, b4] = b;

		if (a3 == b3) {
			if (a4 == b4) {
				if (a1 == b1) {
					return a2 > b2;
				}
				return a1 > a2;
			}
			return a4 > b4;
		}
		return a3 > b3;
	}
};

priority_queue<tuple<int, int, ll, int>, vector<tuple<int, int, ll, int>>, compare>pq;

const int SIZE = 2 * 1e5 + 1;
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();

	int n, Q;
	cin >> n >> Q;
	for (int i = 0; i < Q; i++) {
		int x, y, cost, time;
		cin >> x >> y >> cost >> time;
		pq.push({x,y,cost,time});
	}

	ll sol = 0;
	int t =0 ;

	while (!pq.empty()) {
		auto [x,y,cost, time] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			sol += cost;
			t = max(t,time);
		}
	}

	int root = find(1);
	for (int i = 2; i <= n; i++) {
		if (root != find(i)) {
			cout << -1 <<'\n';
			return 0;
		}

	}
	cout << t << ' ' << sol <<'\n';
}