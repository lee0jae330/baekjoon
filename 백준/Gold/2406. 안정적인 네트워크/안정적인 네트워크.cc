#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
#include<utility>

using namespace std;

int N, M;
const int SIZE = 1e3 +1;
int parent[SIZE];
int ranking[SIZE];
vector<pair<int,int>>v;

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
	x= find(x);
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
	bool operator()(const tuple<int,int,int>&a, const tuple<int, int, int>&b) {
		auto &[a1,a2,a3] = a;
		auto &[b1,b2,b3] = b;
		if (a3 == b3) {
			if(a1 == b1) {
				return a2 > b2;
			}
			return a1 > b1;
		}
		return a3 > b3;
	}
};

priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, compare>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		merge(x,y);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;
			if (i < j) {
				pq.push({i,j, cost});
			}
		}
	}

	int sol =0;

	while (!pq.empty()) {
		auto [x, y, cost] = pq.top();
		pq.pop();

		if (x == 1 || y == 1) {
			continue;
		}

		if (merge(x, y)) {
			v.push_back({x,y});
			sol += cost;
		}
	}

	cout << sol << ' ' << v.size() <<'\n';
	for (auto& iter : v) {
		cout << iter.first << ' ' << iter.second <<'\n';
	}

	return 0;
	
}
