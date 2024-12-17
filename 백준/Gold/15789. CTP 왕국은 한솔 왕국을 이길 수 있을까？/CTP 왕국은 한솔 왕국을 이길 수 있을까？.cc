#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

const int SIZE = 1e5 + 1;

int parent[SIZE];
int ranking[SIZE];
map<int, int>m;

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

	if (ranking[x] < ranking[y]) {
		swap(x, y);
	}
	else if (ranking[x] == ranking[y]) {
		ranking[x]++;
	}
	parent[y] = x;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}

	int C, H, K;
	cin >> C >> H >> K;

	for (int i = 1; i <= N; i++) {
		if (m.find(find(i)) == m.end()) {
			m[find(i)] = 1;
		}
		else {
			m[find(i)]++;
		}
	}

	vector<pair<int, int>>v(m.begin(), m.end());

	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	int power = m[find(C)];
	for (auto iter : v) {
		if (cnt >= K) {
			break;
		}
		if (iter.first != find(C) && iter.first != find(H)) {
			power += iter.second;
			cnt++;
		}
	}
	cout << power << '\n';
	return 0;

	
}