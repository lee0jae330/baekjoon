#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int parent[1001];
vector<pair<char, pair<int, int>>>v;
bool check;

void init(int n) {
	for (int i = 0; i <=n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	check = false;
	if (x != y) {
		check = true;
		if (x > y)
			parent[x] = y;
		else
			parent[y] = x;
	}
}

bool comp(pair<char, pair<int, int>>p1, pair<char, pair<int, int>>p2) {
	return p1.first < p2.first;
}

bool comp1(pair<char, pair<int, int>>p1, pair<char, pair<int, int>>p2) {
	return p1.first > p2.first;
}

int main(void) {
	fastio();
	while (1) {
		v.clear();
		int N, M, K;
		cin >> N >> M >> K;
		int max_blue=0, min_blue=0;
		init(N);
		if (!N && !M && !K)
			break;
		for (int i = 0; i < M; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			v.push_back({ c,{a,b} });
		}
		sort(v.begin(), v.end(),comp);
		for (int i = 0; i < M; i++) {
			merge(v[i].second.first, v[i].second.second);
			if (check) {
				if (v[i].first == 'B')
					max_blue++;
			}
		}
		init(N);
		for (int i = M-1; i >=0; i--) {
			merge(v[i].second.first, v[i].second.second);
			if (check) {
				if (v[i].first == 'B')
					min_blue++;
			}
		}
		if (min_blue <= K && max_blue >= K)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}