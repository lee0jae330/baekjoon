#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<tuple>
#include<utility>

using namespace std;

const int SIZE = 201;
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
	parent[y]=x;
	return true;
}

struct compare {
	bool operator()(const tuple<int,int,int>&a, const tuple<int,int,int>&b) {
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

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare>pq;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int N, sol = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;
			if (i > j) {
				if (cost < 0) {
					merge(i,j);
					sol += -cost;
				}
				else {
					pq.push({i,j,cost});
				}
			}
		}
	}

	vector<pair<int,int>>v;

	while (!pq.empty()) {
		auto [x,y, cost] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			sol += cost;
			v.push_back({x,y});
		}
	}

	cout << sol <<' ' << v.size() << '\n';
	for (auto iter : v) {
		cout << iter.first <<' ' << iter.second <<'\n';
	}
	return 0;
}