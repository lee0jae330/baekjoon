#include<iostream>

using namespace std;

int parent[1000001];
int ranking[1000001];

void init() {
	for (int i = 0; i < 1000001; i++) {
		parent[i] = i;
		ranking[i]= 0;
	}
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x =find(x);
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
		parent[y] = x;
		ranking[x]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N,M;
	cin >> N >> M;

	while (M--) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd) {
			if (find(a) == find(b)) {
				cout << "YES" <<'\n';
			}
			else {
				cout << "NO" <<'\n';
			}
		}
		else {
			merge(a,b);
		}
	}
	return 0;
}