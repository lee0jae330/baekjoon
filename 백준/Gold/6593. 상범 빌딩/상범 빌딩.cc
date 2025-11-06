#include<bits/stdc++.h>

using namespace std;

int L, R, C;

char arr[31][31][31];
int visited[31][31][31];

int xx[6] = { 0,1,0,-1,0,0 };
int yy[6] = { 1,0,-1,0,0,0 };
int zz[6] = { 0,0,0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (1) {
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				for (int k = 0; k < 31; k++) {
					visited[i][j][k] = -1;
				}
			}
		}

		cin >> L >> R >> C;
		if (!L && !R && !C) {
			return 0;
		}

		int sx, sy, sz, ex, ey, ez;

		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S') {
						sx = i, sy = j, sz = k;
						arr[i][j][k] = '.';
					}
					else if (arr[i][j][k] == 'E') {
						ex = i, ey = j, ez = k;
						arr[i][j][k] = '.';
					}
				}
			}
		}

		queue<tuple<int, int, int>>q;
		q.emplace(sx, sy, sz);
		visited[sx][sy][sz] = 0;

		while (!q.empty()) {
			auto [x, y, z] = q.front();
			q.pop();
			for (int i = 0; i < 6; i++) {
				int tx = x + xx[i], ty = y + yy[i], tz = z + zz[i];
				if (tx < 0 || ty < 0 || tz < 0 || tx >= R || ty >= C || tz >= L || visited[tx][ty][tz] != -1) {
					continue;
				}

				if (arr[tx][ty][tz] == '.') {
					visited[tx][ty][tz] = visited[x][y][z] +1;
					q.emplace(tx,ty,tz);
				}
			}
		}

		if (visited[ex][ey][ez] == -1) {
			cout << "Trapped!" <<'\n';
		}
		else {
			cout << "Escaped in " << visited[ex][ey][ez] << " minute(s)." <<'\n';
		}
	}
}