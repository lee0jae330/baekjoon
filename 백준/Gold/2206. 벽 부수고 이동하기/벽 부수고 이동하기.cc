#include<bits/stdc++.h>

using namespace std;

int N, M;
char arr[1001][1001];
int visited[1001][1001][2];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	queue<tuple<int, int, int>>q;
	q.emplace(x, y, 0);
	visited[x][y][0] = 1;
	while (!q.empty()) {
		auto [x, y, flag] = q.front();
		q.pop();
		if (x == N - 1 && y == M - 1) {
			cout << visited[x][y][flag] <<'\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
				continue;
			}

			if (arr[tx][ty] == '1') {
				if (!flag && !visited[tx][ty][1]) {
					visited[tx][ty][1] = visited[x][y][flag] + 1;
					q.emplace(tx, ty, 1);
				}
			}
			else {
				if (!visited[tx][ty][flag]) {
					visited[tx][ty][flag] = visited[x][y][flag]+1;
					q.emplace(tx, ty, flag);
				}
			}
		}
	}
	cout << -1 <<'\n';
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

	bfs(0, 0);
	return 0;
}