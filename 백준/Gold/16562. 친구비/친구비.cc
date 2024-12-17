#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

const int SIZE = 1e4 + 2;

int parent[SIZE];
int ranking[SIZE];
vector<pair<int, int>>v;

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
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	init();

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		v.push_back({ i ,cost });
	}

	for (int i = 0; i < M; i++) {
		int  x, y;
		cin >> x >> y;
		merge(x, y);
	}

	sort(v.begin(), v.end(), compare);

	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		if (K < total + v[i].second) {
			break;
		}
		if (find(v[i].first) != find(10001)) {
			merge(v[i].first, 10001);
			total += v[i].second;
		}
	}

	int root = find(10001);
	for (int i = 1; i <= N; i++) {
		if (find(i) != root) {
			cout << "Oh no" << '\n';
			return 0;
		}
	}
	cout << total << '\n';
	return 0;
}