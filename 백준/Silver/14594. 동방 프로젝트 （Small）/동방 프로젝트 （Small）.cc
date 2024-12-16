#include<iostream>
#include<set>;

using namespace std;

const int SIZE = 1e6+1;

int parent[SIZE];
int ranking[SIZE];
set<int>s;

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
	init();

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x + 1; j <= y; j++) {
			merge(x, j);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		find(i);
	}


	for (int i = 1; i <= N; i++) {
		s.insert(parent[i]);
	}

	cout << s.size() <<'\n';
	return 0;
}