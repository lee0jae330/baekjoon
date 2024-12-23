#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>

using namespace std;

int N, M;
const int SIZE = 2 * 1e5 + 1;
int parent[SIZE];
int ranking[SIZE];

set<int>mn;
set<int>mx;
set<int>sol;

vector<tuple<int,int,int,int>>v;

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

	cin >> N >> M;
	if (N - 1 == M) {
		cout << "NO" << '\n';
		return 0;
	}


	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v.push_back({cost, x,y, i+1});
	}

	sort(v.begin(),v.end());


	init();
	for (auto iter : v) {
		auto [cost, x,y, num] = iter;
		if (merge(x, y)) {
			mn.insert(num);
		}
	}

	init();
	for (int i = v.size() - 1; i >= 0; i--) {
		auto [cost, x, y, num] = v[i];
		if (merge(x, y)) {
			mx.insert(num);
		}
	}

	while (1) {
		init();
		sol.clear();
		shuffle(begin(v), end(v), default_random_engine());
		for (auto iter : v) {
			auto [cost, x, y, num] = iter;
			if (merge(x, y)) {
				sol.insert(num);
			}
		}
		if (sol != mn && sol != mx) {
			cout << "YES" <<'\n';
			for (auto i : sol) {
				cout << i << ' ';
			}
			return 0;
		}
	}
	return 0;
}
