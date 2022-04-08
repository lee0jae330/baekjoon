#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<memory.h>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[101][101];
int visited[101][101];
int sol[101][101];
int R, C;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
int dist[3][101][101];

void bfs(int x, int y, int n) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;
	dist[n][x][y] = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		int d = dist[n][x][y];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i], ty = y + yy[i];
			if (tx >= 0 && ty >= 0 && tx < R && ty < C && arr[tx][ty] == '0') {
				if (!visited[tx][ty]) {
					visited[tx][ty] = 1;
					dist[n][tx][ty] = d + 1;
					q.push({ tx,ty });
				}
			}
		}
	}
}

int main(void) {
	fastio();
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];
	}

	int x, y;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				dist[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		memset(visited, 0, sizeof(visited));
		cin >> x >> y;
		bfs(x - 1, y - 1, i);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (dist[0][i][j] != -1 && dist[1][i][j] != -1 && dist[2][i][j] != -1) {
				sol[i][j] = max(dist[0][i][j], max(dist[1][i][j], dist[2][i][j]));
			}
			else
			{
				sol[i][j] = -1;
			}
		}
	}
	int MIN = 20000;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sol[i][j] != -1) {
				MIN = min(sol[i][j], MIN);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sol[i][j] != -1) {
				if (MIN == sol[i][j])
					cnt++;
			}
		}
	}
	if (cnt == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << MIN << '\n' << cnt << '\n';
	}
	return 0;
}