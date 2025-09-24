#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
#include<memory.h>


using namespace std;


int N, M;

int arr[301][301];
int visited[301][301];
int cp[301][301];

int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };

bool checkMelt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.emplace(x, y);
	visited[x][y] = 1;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = x + xx[i];
			int ty = y + yy[i];

			if (tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty]) {
				continue;
			}

			if (arr[tx][ty]) {
				visited[tx][ty] = 1;
				q.emplace(tx, ty);
			}
		}
	}
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
	int year = 0;
	while (!checkMelt()) {
		memset(visited, 0, sizeof(visited));

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt > 1) {
			cout << year << '\n';
			return 0;
		}



		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cp[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j]) {
					for (int k = 0; k < 4; k++) {
						int tx = i + xx[k];
						int ty = j + yy[k];
						if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
							continue;
						}

						if (!arr[tx][ty]) {
							cp[i][j]--;
						}
					}
					cp[i][j] = max(cp[i][j], 0);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = cp[i][j];
			}
		}
		year++;
	}
	cout << 0 << '\n';
	return 0;
}