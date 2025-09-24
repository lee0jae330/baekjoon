#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int parent[1001];
int ranking[1001];

void init() {
	for (int i = 0; i < 1001; i++) {
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

	if (ranking[x] > ranking[y]) {
		parent[y] = x;
	}
	else if (ranking[x] < ranking[y]) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
		ranking[x]++;
	}
	return true;
}

priority_queue<tuple<int,int,int>>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N;
	cin >> N;

	int M;
	cin >> M ;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.emplace(-c,a,b);
	}
	

	int sum = 0;
	while (!pq.empty()) {
		auto [cost, a, b] = pq.top();
		pq.pop();

		if (merge(a, b)) {
			sum+= -cost;
		}
	}

	cout << sum <<'\n';
	return 0;
}