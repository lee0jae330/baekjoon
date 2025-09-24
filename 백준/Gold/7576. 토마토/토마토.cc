#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int M, N;

int arr[1001][1001];
int visited[1001][1001];

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

			if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] != -1) {
				continue;
			}

			if (!arr[tx][ty]) {
				visited[tx][ty] = visited[x][y] + 1;
				q.emplace(tx, ty);
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
	}

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				q.emplace(i, j);
				visited[i][j] = 0;
			}
		}
	}

	bfs();

	int sol = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!arr[i][j]) {
				if (visited[i][j] == -1) {
					cout << -1 << '\n';
					return 0;
				}
				else {
					sol = max(sol, visited[i][j]);
				}
			}
		}
	}
	cout << sol <<'\n';

	
	return 0; 
}
