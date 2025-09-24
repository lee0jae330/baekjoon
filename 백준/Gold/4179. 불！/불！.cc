#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int R, C;

char arr[1001][1001];
int visited[1001][1001];
int visited1[1001][1001];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

queue<pair<int, int>>q;

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];

			if (tx < 0 || ty < 0 || tx >= R || ty >= C || visited[tx][ty] != -1) {
				continue;
			}

			if (arr[tx][ty] == '.') {
				visited[tx][ty] = visited[x][y] + 1;
				q.emplace(tx, ty);
			}
		}
	}
}

int sol = -1;

void bfs1() {
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];

			if (tx < 0 || ty < 0 || tx >= R || ty >= C) {
				sol = visited1[x][y] + 1;
				return;
			}

			if (visited1[tx][ty] != -1) {
				continue;
			}

			if (arr[tx][ty] == '.') {
				if (visited[tx][ty] == -1 || visited1[x][y] + 1 < visited[tx][ty]) {
					visited1[tx][ty] = visited1[x][y] + 1;
					q.emplace(tx, ty);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 1001; i++) {
		fill(visited[i], visited[i] + 1001, -1);
		fill(visited1[i], visited1[i] + 1001, -1);
	}

	cin >> R >> C;

	int sx, sy;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				sx = i, sy = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'F') {
				visited[i][j] = 0;
				q.emplace(i, j);
				arr[i][j] = '.';
			}
		}
	}

	bfs();
	visited1[sx][sy] = 0;
	q.emplace(sx, sy);
	bfs1();

	if (sol == -1) {
		cout << "IMPOSSIBLE" <<'\n';
	}
	else {
		cout << sol <<'\n';
	}
	return 0;
}