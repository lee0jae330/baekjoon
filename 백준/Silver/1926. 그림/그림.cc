#include<iostream>
#include<queue>

int N, M;
int arr[501][501];
int visited[501][501];
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

using namespace std;

int bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.emplace(x, y);
	visited[x][y] = 1;
	int cnt = 0;
	while (!q.empty()) {
		auto[x, y] = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty]) {
				continue;
			}

			if (arr[tx][ty]) {
				q.emplace(tx, ty);
				visited[tx][ty] = 1;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int sol = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] && !visited[i][j]) {
				sol = max(sol, bfs(i, j));
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	cout << sol << '\n';
	return 0;
}