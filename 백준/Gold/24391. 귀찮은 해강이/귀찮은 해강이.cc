#include<iostream>
#include<vector>

using namespace std;

int parent[100001];
int ranking[100001];

void init() {
	for (int i = 0; i < 100001; i++) {
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

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}

	if (ranking[x] > ranking[y]) {
		parent[y] = x;
	}
	else if (ranking[x] < ranking[y]) {
		parent[x] = y;
	}
	else {
		ranking[x]++;
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N, M;
	cin >> N >> M;

	while (M--) {
		int x, y;
		cin >> x >> y;
		merge(x,y);
	}

	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}


	int cnt = 0;
	int cur = find(v[0]);
	for (int i = 1; i < N; i++) {
		if (cur != find(v[i])) {
			cnt++;
			cur = find(v[i]);
		}
	}
	cout << cnt <<'\n';
	return 0;
}
