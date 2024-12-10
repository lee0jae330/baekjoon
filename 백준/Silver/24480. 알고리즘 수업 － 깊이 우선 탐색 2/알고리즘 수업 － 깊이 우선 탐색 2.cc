#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int>v[100001];
int visited[100001];

int N, M, R;
int idx = 1;


void dfs(int x) {
	visited[x] = idx++;
	for (int i = 0; i < v[x].size(); i++) {
		int tx = v[x][i];
		if (visited[tx])
			continue;
		dfs(tx);
	}
}

bool compare(const int& a, const int& b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), compare);
	}
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << '\n';
	}
	return 0;
}