#include<iostream>
#include<algorithm>

using namespace std;

const int SIZE = 1e5 + 1;

int parent[SIZE];
int ranking[SIZE];
int weight[SIZE];

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

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		cout << weight[x] <<'\n';
		return;
	}
	if (ranking[x] < ranking[y]) {
		swap(x,y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
	weight[x] += weight[y];
	cout << weight[x] <<'\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		merge(x,y);
	}
	return 0;
}