#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>

using namespace std;

typedef long long ll;

const int SIZE = 2001;
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
		swap(x,y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}

	parent[y] = x;
	return true;
}

struct compare {
	bool operator()(const tuple<int, int, ll>&a, const tuple<int,int, ll>&b ) {
		auto &[a1,a2,a3] = a;
		auto &[b1,b2,b3] = b;

		if (a3 == b3) {
			if (a1 == b1) {
				return a2 > b2;
			}
			return a1 > b1;
		}
		return a3 > b3;
	}
};

priority_queue<tuple<int,int,ll> , vector<tuple<int, int, ll>>, compare>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		init();
		while (!pq.empty()) {
			pq.pop();
		}
		int N, M;
		cin >> N >> M;

		ll sol = 0;

		for (int i = 1; i <= N - 1; i++) {
			int u;
			ll c;
			cin >> u >> c;
			pq.push({i, u, c});
		}

		for (int i = 0; i < M; i++) {
			int x, y;
			ll cost;
			cin >> x >> y >> cost;
			pq.push({x,y, cost});
			
			auto tmp = pq;
			init();
			ll sum = 0;
			while (!tmp.empty()) {
				auto [a,b,c] = tmp.top();
				tmp.pop();
				if (merge(a, b)) {
					sum += c;
				}
			}
			sol ^= sum;
		}
		cout << sol <<'\n';
	}
	return 0;
}