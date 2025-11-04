#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int R, C;

char arr[1001][1001];
int visited1[1001][1001];
int visited2[1001][1001];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

queue<pair<int, int>>q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 1001; i++) {
		fill(visited1[i], visited1[i] + 1001, -1);
		fill(visited2[i], visited2[i] + 1001, -1);
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
				q.emplace(i, j);
				visited1[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= R || ty >= C || visited1[tx][ty] != -1) {
				continue;
			}

			if (arr[tx][ty] == '.') {
				visited1[tx][ty] = visited1[x][y] + 1;
				q.emplace(tx, ty);
			}
		}
	}

	q.emplace(sx, sy);
	visited2[sx][sy] = 0;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];
			if (tx < 0 || ty < 0 || tx >= R || ty >= C) {
				cout << visited2[x][y] + 1 << '\n';
				return 0;
			}
			if (arr[tx][ty] == '.' && visited2[tx][ty] == -1 && (visited2[x][y] + 1 < visited1[tx][ty] || visited1[tx][ty] == -1)) {
				q.emplace(tx, ty);
				visited2[tx][ty] = visited2[x][y] + 1;
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
	return 0;
}