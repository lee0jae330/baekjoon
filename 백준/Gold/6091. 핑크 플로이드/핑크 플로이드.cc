#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<tuple>
#include<set>

using namespace std;

const int SIZE = 1025;
int parent[SIZE];
int ranking[SIZE];
set<int>s[SIZE];

int N;

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

priority_queue<tuple<int,int,int>>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			int dist;
			cin >> dist;
			pq.push({-dist, i, j});
		}
	}

	while (!pq.empty()) {
		auto [dist, x, y] = pq.top();
		pq.pop();
		if (merge(x, y)) {
			s[x].insert(y);
			s[y].insert(x);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << s[i].size() <<' ';
		for (auto iter : s[i]) {
			cout << iter<<' ';
		}
		cout <<'\n';
	}

	return 0;




}